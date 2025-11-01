#include <ncurses.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <mutex>
#include <functional>

using namespace std;

// Include all necessary headers
#include "../include/Plant.h"
#include "../include/GrowthState.h"
#include "../include/HealthState.h"
#include "../include/Mature.h"
#include "../include/Good.h"
#include "../include/TemperatePlantFactory.h"
#include "../include/TropicalPlantFactory.h"
#include "../include/CarnivorousPlantFactory.h"
#include "../include/SucculentPlantFactory.h"
#include "../include/PotDecorator.h"
#include "../include/FertilizerDecorator.h"
#include "../include/ConcreteCommMediator.h"
#include "../include/Manager.h"
#include "../include/Worker.h"
#include "../include/Customer.h"
#include "../include/WaterHandler.h"
#include "../include/SunHandler.h"
#include "../include/FertilizerHandler.h"
#include "../include/PruneHandler.h"
#include "../include/Inventory.h"
#include "../include/Stock.h"
#include "../include/Order.h"
#include "../include/StockIterator.h"

// Global state
atomic<bool> running(true);
atomic<int> tickCounter(0);
mutex ncursesMutex;

// Window pointers
WINDOW *statusWin = nullptr;
WINDOW *contentWin = nullptr;
WINDOW *menuWin = nullptr;

// Global order tracking
Order *currentOrder = nullptr;
int orderCounter = 1;

/**
 * @brief Initialize ncurses UI
 */
void initUI() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_RED, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_WHITE, COLOR_BLACK);
    }
    
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);
    
    statusWin = newwin(6, maxX, 0, 0);
    contentWin = newwin(maxY - 11, maxX, 6, 0);
    menuWin = newwin(5, maxX, maxY - 5, 0);
    
    scrollok(contentWin, TRUE);
    keypad(contentWin, TRUE);
    refresh();
}

/**
 * @brief Clean up ncurses
 */
void cleanupUI() {
    if (statusWin) delwin(statusWin);
    if (contentWin) delwin(contentWin);
    if (menuWin) delwin(menuWin);
    endwin();
}

/**
 * @brief Update status bar showing cart info
 */
void updateStatusBar(Stock *stock) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(statusWin);
    box(statusWin, 0, 0);
    
    wattron(statusWin, COLOR_PAIR(2) | A_BOLD);
    mvwprintw(statusWin, 0, 2, " 🌿 PLANT STORE - CUSTOMER PORTAL 🌿 ");
    wattroff(statusWin, COLOR_PAIR(2) | A_BOLD);
    
    wattron(statusWin, COLOR_PAIR(2));
    mvwprintw(statusWin, 2, 2, "Available Plants: %4d", stock->getPlantCount());
    wprintw(statusWin, " │ Total Stock Value: $%.2f", stock->getTotalStockValue());
    wattroff(statusWin, COLOR_PAIR(2));
    
    // Show current cart
    if (currentOrder) {
        wattron(statusWin, COLOR_PAIR(3));
        mvwprintw(statusWin, 3, 2, "🛒 Cart: %zu items │ Total: $%.2f │ Status: %s", 
                  currentOrder->getOrderItems().size(),
                  currentOrder->getTotal(),
                  currentOrder->getStateName().c_str());
        wattroff(statusWin, COLOR_PAIR(3));
    } else {
        wattron(statusWin, COLOR_PAIR(6));
        mvwprintw(statusWin, 3, 2, "🛒 Cart: Empty");
        wattroff(statusWin, COLOR_PAIR(6));
    }
    
    wrefresh(statusWin);
}

/**
 * @brief Display customer menu
 */
void displayMenu() {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(menuWin);
    box(menuWin, 0, 0);
    
    wattron(menuWin, COLOR_PAIR(5));
    mvwprintw(menuWin, 1, 2, "[1]Browse Plants [2]View Cart [3]Add to Cart [4]Remove from Cart");
    mvwprintw(menuWin, 2, 2, "[5]Checkout [6]Pay Order [7]View Orders [8]Ask Question [0]Exit");
    wattroff(menuWin, COLOR_PAIR(5));
    
    mvwprintw(menuWin, 3, 2, "Choice: ");
    wrefresh(menuWin);
}

/**
 * @brief Display content with dynamic resizing
 */
void displayContent(const string &content) {
    lock_guard<mutex> lock(ncursesMutex);
    
    int screenMaxY, screenMaxX;
    getmaxyx(stdscr, screenMaxY, screenMaxX);
    
    istringstream iss(content);
    string line;
    vector<string> lines;
    
    while (getline(iss, line)) {
        if (line.empty()) {
            lines.push_back("");
            continue;
        }
        
        if (line.length() > (size_t)(screenMaxX - 4)) {
            size_t pos = 0;
            while (pos < line.length()) {
                size_t len = min((size_t)(screenMaxX - 4), line.length() - pos);
                lines.push_back(line.substr(pos, len));
                pos += len;
            }
        } else {
            lines.push_back(line);
        }
    }
    
    int contentHeight = lines.size() + 3;
    int maxContentHeight = screenMaxY - 11;
    
    if (contentWin) delwin(contentWin);
    
    if (contentHeight > maxContentHeight) {
        contentWin = newwin(maxContentHeight, screenMaxX, 6, 0);
        werase(contentWin);
        box(contentWin, 0, 0);
        
        for (int i = 0; i < maxContentHeight - 3 && i < (int)lines.size(); i++) {
            mvwprintw(contentWin, i + 1, 2, "%s", lines[i].c_str());
        }
        
        wattron(contentWin, COLOR_PAIR(3));
        mvwprintw(contentWin, maxContentHeight - 2, 2, 
                  "[%zu lines total] Press any key...", lines.size());
        wattroff(contentWin, COLOR_PAIR(3));
    } else {
        int newHeight = contentHeight;
        if (menuWin) delwin(menuWin);
        menuWin = newwin(5, screenMaxX, 6 + newHeight, 0);
        
        contentWin = newwin(newHeight, screenMaxX, 6, 0);
        werase(contentWin);
        box(contentWin, 0, 0);
        
        for (int i = 0; i < (int)lines.size(); i++) {
            mvwprintw(contentWin, i + 1, 2, "%s", lines[i].c_str());
        }
        
        wattron(contentWin, COLOR_PAIR(3));
        mvwprintw(contentWin, newHeight - 2, 2, "Press any key to continue...");
        wattroff(contentWin, COLOR_PAIR(3));
    }
    
    wrefresh(contentWin);
    
    nodelay(stdscr, FALSE);
    wgetch(contentWin);
    nodelay(stdscr, TRUE);
    
    // Restore layout
    if (contentWin) delwin(contentWin);
    if (menuWin) delwin(menuWin);
    contentWin = newwin(screenMaxY - 11, screenMaxX, 6, 0);
    menuWin = newwin(5, screenMaxX, screenMaxY - 5, 0);
    scrollok(contentWin, TRUE);
    keypad(contentWin, TRUE);
    werase(contentWin);
    box(contentWin, 0, 0);
    wrefresh(contentWin);
}

/**
 * @brief Capture output
 */
string captureOutput(function<void()> func) {
    streambuf *old = cout.rdbuf();
    ostringstream oss;
    cout.rdbuf(oss.rdbuf());
    func();
    cout.rdbuf(old);
    return oss.str();
}

/**
 * @brief Get input string
 */
string getInputString(const string &prompt) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(contentWin);
    box(contentWin, 0, 0);
    mvwprintw(contentWin, 1, 2, "%s", prompt.c_str());
    wrefresh(contentWin);
    
    echo();
    curs_set(1);
    nodelay(stdscr, FALSE);
    
    char buffer[256];
    mvwgetnstr(contentWin, 3, 2, buffer, 255);
    
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    
    return string(buffer);
}

/**
 * @brief Get input int
 */
int getInputInt(const string &prompt) {
    string input = getInputString(prompt);
    try {
        return stoi(input);
    } catch (...) {
        return -1;
    }
}

/**
 * @brief Browse available plants in stock
 */
void browsePlants(Stock *stock) {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║         AVAILABLE PLANTS FOR SALE            ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    
    string output = captureOutput([stock]() { stock->print(); });
    oss << output;
    
    displayContent(oss.str());
}

/**
 * @brief View current cart
 */
void viewCart() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║              YOUR SHOPPING CART              ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    
    if (!currentOrder) {
        oss << "Your cart is empty.\n";
        oss << "\nStart shopping by selecting 'Add to Cart'!";
    } else {
        oss << "Order ID: " << currentOrder->getId() << "\n";
        oss << "Status: " << currentOrder->getStateName() << "\n\n";
        
        string orderOutput = captureOutput([&]() { currentOrder->print(); });
        oss << orderOutput;
        
        oss << "\n" << string(46, '-') << "\n";
        oss << "TOTAL: $" << fixed << setprecision(2) << currentOrder->getTotal() << "\n";
    }
    
    displayContent(oss.str());
}

/**
 * @brief Add plant to cart
 */
void addToCart(Stock *stock, Inventory *inv) {
    (void)inv; // Unused for now
    
    // Create order if doesn't exist
    if (!currentOrder) {
        currentOrder = new Order("ORD" + to_string(orderCounter++));
    }
    
    if (currentOrder->getStateName() != "draft") {
        displayContent("❌ Cannot modify order after checkout!\nCreate a new order by completing payment.");
        return;
    }
    
    // Get list of available plants
    vector<Plant*> availablePlants = stock->getAllPlants();
    
    if (availablePlants.empty()) {
        displayContent("❌ No plants available in stock!");
        return;
    }
    
    // Display plants with numbers
    ostringstream oss;
    oss << "Available Plants:\n\n";
    for (size_t i = 0; i < availablePlants.size(); i++) {
        oss << "[" << (i + 1) << "] " << availablePlants[i]->getSpecies() 
            << " - $" << fixed << setprecision(2) << availablePlants[i]->getPrice() << "\n";
    }
    oss << "\nEnter plant number to add (0 to cancel):";
    
    int choice = getInputInt(oss.str());
    
    if (choice <= 0 || choice > (int)availablePlants.size()) {
        displayContent("Cancelled.");
        return;
    }
    
    Plant *selectedPlant = availablePlants[choice - 1];
    
    // Ask for confirmation
    ostringstream confirm;
    confirm << "Add " << selectedPlant->getSpecies() 
            << " ($" << fixed << setprecision(2) << selectedPlant->getPrice() 
            << ") to cart?\n\n[Y/N]";
    
    string response = getInputString(confirm.str());
    
    if (response != "Y" && response != "y") {
        displayContent("Cancelled.");
        return;
    }
    
    // Remove from stock and add to order
    stock->removePlant(selectedPlant);
    currentOrder->addPlant(selectedPlant);
    
    ostringstream success;
    success << "✓ Plant added to cart!\n\n";
    success << selectedPlant->getDescription() << "\n";
    success << "Price: $" << fixed << setprecision(2) << selectedPlant->getPrice();
    
    displayContent(success.str());
}

/**
 * @brief Remove plant from cart
 */
void removeFromCart(Stock *stock, Inventory *inv) {
    if (!currentOrder || currentOrder->getOrderItems().empty()) {
        displayContent("❌ Your cart is empty!");
        return;
    }
    
    if (currentOrder->getStateName() != "draft") {
        displayContent("❌ Cannot modify order after checkout!");
        return;
    }
    
    vector<Plant*> orderItems = currentOrder->getOrderItems();
    
    ostringstream oss;
    oss << "Items in your cart:\n\n";
    for (size_t i = 0; i < orderItems.size(); i++) {
        oss << "[" << (i + 1) << "] " << orderItems[i]->getDescription() 
            << " - $" << fixed << setprecision(2) << orderItems[i]->getPrice() << "\n";
    }
    oss << "\nEnter item number to remove (0 to cancel):";
    
    int choice = getInputInt(oss.str());
    
    if (choice <= 0 || choice > (int)orderItems.size()) {
        displayContent("Cancelled.");
        return;
    }
    
    Plant *toRemove = orderItems[choice - 1];
    currentOrder->removePlant(toRemove, inv, stock);
    
    displayContent("✓ Item removed from cart!");
}

/**
 * @brief Checkout - proceed order to submitted state
 */
void checkoutOrder() {
    if (!currentOrder) {
        displayContent("❌ Your cart is empty!\nAdd items before checking out.");
        return;
    }
    
    if (currentOrder->getOrderItems().empty()) {
        displayContent("❌ Your cart is empty!\nAdd items before checking out.");
        return;
    }
    
    if (currentOrder->getStateName() != "draft") {
        displayContent("❌ Order already checked out!");
        return;
    }
    
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║              CHECKOUT SUMMARY                ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "Order ID: " << currentOrder->getId() << "\n";
    oss << "Items: " << currentOrder->getOrderItems().size() << "\n";
    oss << "Total: $" << fixed << setprecision(2) << currentOrder->getTotal() << "\n\n";
    oss << "Confirm checkout? [Y/N]";
    
    string confirm = getInputString(oss.str());
    
    if (confirm == "Y" || confirm == "y") {
        currentOrder->proceed();
        displayContent("✓ Order submitted!\nProceed to payment (option 6).");
    } else {
        displayContent("Checkout cancelled.");
    }
}

/**
 * @brief Pay for order
 */
void payOrder() {
    if (!currentOrder) {
        displayContent("❌ No order to pay!");
        return;
    }
    
    string state = currentOrder->getStateName();
    
    if (state == "draft") {
        displayContent("❌ Please checkout first (option 5)!");
        return;
    }
    
    if (state == "paid" || state == "completed") {
        displayContent("✓ Order already paid!");
        return;
    }
    
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║                 PAYMENT                      ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "Order ID: " << currentOrder->getId() << "\n";
    oss << "Amount Due: $" << fixed << setprecision(2) << currentOrder->getTotal() << "\n\n";
    oss << "Payment Methods:\n";
    oss << "[1] Credit Card\n";
    oss << "[2] Debit Card\n";
    oss << "[3] Cash\n\n";
    oss << "Select payment method:";
    
    int payment = getInputInt(oss.str());
    
    if (payment < 1 || payment > 3) {
        displayContent("❌ Invalid payment method!");
        return;
    }
    
    // Process payment
    currentOrder->proceed();
    currentOrder->proceed();
    
    ostringstream success;
    success << "╔══════════════════════════════════════════════╗\n";
    success << "║           ✓ PAYMENT SUCCESSFUL!              ║\n";
    success << "╚══════════════════════════════════════════════╝\n\n";
    success << "Order ID: " << currentOrder->getId() << "\n";
    success << "Paid: $" << fixed << setprecision(2) << currentOrder->getTotal() << "\n\n";
    success << "Thank you for your purchase!\n";
    success << "Your plants will be prepared for pickup.";
    
    displayContent(success.str());
    
    currentOrder = nullptr;
}

/**
 * @brief View order history
 */
void viewOrders() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║              ORDER HISTORY                   ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    
    if (currentOrder) {
        oss << "Current Order:\n";
        oss << "  ID: " << currentOrder->getId() << "\n";
        oss << "  Status: " << currentOrder->getStateName() << "\n";
        oss << "  Items: " << currentOrder->getOrderItems().size() << "\n";
        oss << "  Total: $" << fixed << setprecision(2) << currentOrder->getTotal() << "\n";
    } else {
        oss << "No active orders.\n";
    }
    
    displayContent(oss.str());
}

/**
 * @brief Ask question to staff
 */
void askQuestion(Customer *customer) {
    vector<string> questions = {
        "How do I care for my new plants?",
        "What is your return policy?",
        "Do you offer delivery services?",
        "Can I get a bulk discount?",
        "What are your store hours?",
        "Do you have gift cards?"
    };
    
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║          CUSTOMER SERVICE QUESTIONS          ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    
    for (size_t i = 0; i < questions.size(); i++) {
        oss << "[" << (i + 1) << "] " << questions[i] << "\n";
    }
    oss << "[7] Custom question\n\n";
    oss << "Select question:";
    
    int choice = getInputInt(oss.str());
    
    string question;
    if (choice >= 1 && choice <= 6) {
        question = questions[choice - 1];
    } else if (choice == 7) {
        question = getInputString("Enter your question:");
    } else {
        displayContent("❌ Invalid choice!");
        return;
    }
    
    customer->askQuestion(question);
    displayContent("✓ Question sent to staff!\nA representative will respond shortly.");
}

/**
 * @brief Async tick system for plant growth
 */
void asyncTickSystem(Inventory *inv, Stock *stock, PlantCareHandler *handler) {
    int cycles = 0;
    
    while (running.load()) {
        cycles++;
        tickCounter.store(cycles);
        
        if (cycles % 50 == 0) {
            inv->moveValidPlantsToStock(stock);
        }
        
        if (cycles % 150 == 0) {
            inv->addSmallPlant(inv->getCarnivorousFactory(), handler);
            inv->addMediumPlant(inv->getTemperateFactory(), handler);
            inv->addLargePlant(inv->getTropicalFactory(), handler);
            inv->addSmallPlant(inv->getSucculentFactory(), handler);
        }
        
        inv->tick();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * @brief Main function
 */
int main() {
    streambuf *oldCoutBuf = cout.rdbuf();
    ostringstream initOutput;
    cout.rdbuf(initOutput.rdbuf());
    
    try {
        Inventory *inv = new Inventory();
        Stock *stock = new Stock();
        
        WaterHandler *waterHandler = new WaterHandler();
        SunHandler *sunlightHandler = new SunHandler();
        FertilizerHandler *fertilizerHandler = new FertilizerHandler();
        PruneHandler *pruneHandler = new PruneHandler();
        
        waterHandler->setNext(sunlightHandler);
        sunlightHandler->setNext(fertilizerHandler);
        fertilizerHandler->setNext(pruneHandler);
        
        CommMediator *mediator = new ConcreteCommMediator();
        vector<StaffMember *> staff;
        
        for (int k = 0; k < 3; k++) {
            Worker *worker = new Worker("Worker" + to_string(k + 1), mediator, inv);
            staff.push_back(worker);
        }
        
        Customer *customer = new Customer("Valued Customer", mediator);
        
        for (int i = 0; i < 5; i++) {
            inv->addSmallPlant(inv->getCarnivorousFactory(), waterHandler);
            inv->addMediumPlant(inv->getTemperateFactory(), waterHandler);
            inv->addLargePlant(inv->getTropicalFactory(), waterHandler);
            inv->addSmallPlant(inv->getSucculentFactory(), waterHandler);
        }
        
        // Tick plants to mature them
        for (int i = 0; i < 20; i++) {
            inv->tick();
        }
        inv->moveValidPlantsToStock(stock);
        
        // Restore cout
        cout.rdbuf(oldCoutBuf);
        
        // Initialize UI
        initUI();
        
        // Start tick thread
        thread tickThread(asyncTickSystem, inv, stock, waterHandler);
        this_thread::sleep_for(chrono::milliseconds(500));
        
        // Initial display
        updateStatusBar(stock);
        displayMenu();
        
        ostringstream welcome;
        welcome << "╔══════════════════════════════════════════════╗\n";
        welcome << "║     Welcome to the Plant Store Portal!      ║\n";
        welcome << "╚══════════════════════════════════════════════╝\n\n";
        welcome << "Browse our selection of beautiful plants!\n\n";
        welcome << "Features:\n";
        welcome << "• Browse available plants\n";
        welcome << "• Add plants to your cart\n";
        welcome << "• Decorate with pots & fertilizer\n";
        welcome << "• Secure checkout & payment\n";
        welcome << "• Customer service support\n\n";
        welcome << "Happy shopping! 🌿";
        
        displayContent(welcome.str());
        
        // Main loop
        bool exitProgram = false;
        while (!exitProgram) {
            updateStatusBar(stock);
            displayMenu();
            
            nodelay(stdscr, FALSE);
            int ch = getch();
            nodelay(stdscr, TRUE);
            
            switch (ch) {
                case '0':
                    exitProgram = true;
                    break;
                case '1':
                    browsePlants(stock);
                    break;
                case '2':
                    viewCart();
                    break;
                case '3':
                    addToCart(stock, inv);
                    break;
                case '4':
                    removeFromCart(stock, inv);
                    break;
                case '5':
                    checkoutOrder();
                    break;
                case '6':
                    payOrder();
                    break;
                case '7':
                    viewOrders();
                    break;
                case '8':
                    askQuestion(customer);
                    break;
            }
            
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        
        // Cleanup
        running.store(false);
        tickThread.join();
        cleanupUI();
        
        cout << "\n✓ Thank you for shopping at Plant Store!\n" << endl;
        
        // if (currentOrder) delete currentOrder;
        delete waterHandler;
        delete sunlightHandler;
        delete fertilizerHandler;
        delete pruneHandler;
        delete mediator;
        delete customer;
        
        for (StaffMember *s : staff) {
            delete s;
        }
        
        return 0;
    }
    catch (const exception &e) {
        cout.rdbuf(oldCoutBuf);
        cleanupUI();
        cerr << "Exception: " << e.what() << endl;
        running.store(false);
        return 1;
    }
    catch (...) {
        cout.rdbuf(oldCoutBuf);
        cleanupUI();
        cerr << "Unknown exception!" << endl;
        running.store(false);
        return 1;
    }
}