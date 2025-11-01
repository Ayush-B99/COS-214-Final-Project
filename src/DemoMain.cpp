// File: COS-214-Final-Project/src/NCursesMain.cpp
#include <ncurses.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <future>
#include <atomic>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <mutex>

using namespace std;

// Include all necessary headers
#include "../include/Plant.h"
#include "../include/GrowthState.h"
#include "../include/HealthState.h"
#include "../include/Seed.h"
#include "../include/Sprout.h"
#include "../include/Mature.h"
#include "../include/Good.h"
#include "../include/NeedsCare.h"
#include "../include/Dead.h"
#include "../include/GrowthObserver.h"
#include "../include/TemperatePlantFactory.h"
#include "../include/TropicalPlantFactory.h"
#include "../include/CarnivorousPlantFactory.h"
#include "../include/SucculentPlantFactory.h"
#include "../include/PotDecorator.h"
#include "../include/FertilizerDecorator.h"
#include "../include/PlantDecorator.h"
#include "../include/ConcreteCommMediator.h"
#include "../include/Manager.h"
#include "../include/Worker.h"
#include "../include/Customer.h"
#include "../include/WaterHandler.h"
#include "../include/SunHandler.h"
#include "../include/FertilizerHandler.h"
#include "../include/PruneHandler.h"
#include "../include/Company.h"
#include "../include/Storage.h"
#include "../include/Inventory.h"
#include "../include/Stock.h"
#include "../include/PlantNode.h"
#include "../include/Iterator.h"
#include "../include/InventoryIterator.h"

// Global state
atomic<bool> running(true);
atomic<int> tickCounter(0);
atomic<int> plantsAdded(0);
mutex ncursesMutex;

// Window pointers
WINDOW *statusWin = nullptr;
WINDOW *contentWin = nullptr;
WINDOW *menuWin = nullptr;

/**
 * @brief Initialize ncurses and create windows
 */
void initUI() {
    initscr();              // Initialize ncurses
    cbreak();               // Disable line buffering
    noecho();               // Don't echo input
    curs_set(0);            // Hide cursor
    keypad(stdscr, TRUE);   // Enable special keys
    
    // Check if terminal supports colors
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);   // Header
        init_pair(2, COLOR_CYAN, COLOR_BLACK);    // Stats
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);  // Warnings
        init_pair(4, COLOR_RED, COLOR_BLACK);     // Errors
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK); // Menu
        init_pair(6, COLOR_WHITE, COLOR_BLUE);    // Title bar
    }
    
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);
    
    // Create three windows: status, content, menu
    statusWin = newwin(5, maxX, 0, 0);
    contentWin = newwin(maxY - 9, maxX, 5, 0);
    menuWin = newwin(4, maxX, maxY - 4, 0);
    
    scrollok(contentWin, TRUE);
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
 * @brief Update the status bar with live information
 */
void updateStatusBar(Inventory *inv, Stock *stock) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(statusWin);
    box(statusWin, 0, 0);
    
    // Title
    wattron(statusWin, COLOR_PAIR(6) | A_BOLD);
    mvwprintw(statusWin, 0, 2, " 🌿 PLANT STORE MANAGEMENT SYSTEM 🌿 ");
    wattroff(statusWin, COLOR_PAIR(6) | A_BOLD);
    
    // Stats line 1
    wattron(statusWin, COLOR_PAIR(2));
    mvwprintw(statusWin, 2, 2, "Tick: ");
    wattron(statusWin, COLOR_PAIR(3) | A_BOLD);
    wprintw(statusWin, "%6d", tickCounter.load());
    wattroff(statusWin, COLOR_PAIR(3) | A_BOLD);
    
    wattron(statusWin, COLOR_PAIR(2));
    wprintw(statusWin, " │ Inventory: ");
    wattron(statusWin, COLOR_PAIR(1) | A_BOLD);
    wprintw(statusWin, "%4d", inv->getPlantCount());
    wattroff(statusWin, COLOR_PAIR(1) | A_BOLD);
    
    wattron(statusWin, COLOR_PAIR(2));
    wprintw(statusWin, " │ Stock: ");
    wattron(statusWin, COLOR_PAIR(1) | A_BOLD);
    wprintw(statusWin, "%4d", stock->getPlantCount());
    wattroff(statusWin, COLOR_PAIR(1) | A_BOLD);
    
    wattron(statusWin, COLOR_PAIR(2));
    wprintw(statusWin, " │ Value: $");
    wattron(statusWin, COLOR_PAIR(3) | A_BOLD);
    wprintw(statusWin, "%.2f", stock->getTotalStockValue());
    wattroff(statusWin, COLOR_PAIR(3) | A_BOLD);
    wattroff(statusWin, COLOR_PAIR(2));
    
    // Stats line 2
    wattron(statusWin, COLOR_PAIR(2));
    mvwprintw(statusWin, 3, 2, "Plants Auto-Added: ");
    wattron(statusWin, COLOR_PAIR(1) | A_BOLD);
    wprintw(statusWin, "%d", plantsAdded.load());
    wattroff(statusWin, COLOR_PAIR(1) | A_BOLD);
    
    wprintw(statusWin, " │ Runtime: ");
    wattron(statusWin, COLOR_PAIR(3));
    wprintw(statusWin, "%.1fs", tickCounter.load() * 0.1);
    wattroff(statusWin, COLOR_PAIR(3));
    wattroff(statusWin, COLOR_PAIR(2));
    
    wrefresh(statusWin);
}

/**
 * @brief Display the menu
 */
void displayMenu() {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(menuWin);
    box(menuWin, 0, 0);
    
    wattron(menuWin, COLOR_PAIR(5));
    mvwprintw(menuWin, 1, 2, "[1]Inventory [2]Stock [3]Add Plants [4]Ask Question [5]Stats");
    mvwprintw(menuWin, 2, 2, "[6]Plant Types [7]Move to Stock [8]Tick Info [9]Clear [0]Exit");
    wattroff(menuWin, COLOR_PAIR(5));
    
    wrefresh(menuWin);
}

/**
 * @brief Display content in the content window
 */
void displayContent(const string &content) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(contentWin);
    box(contentWin, 0, 0);
    
    // Parse and display content line by line
    istringstream iss(content);
    string line;
    int y = 1;
    int maxY, maxX;
    getmaxyx(contentWin, maxY, maxX);
    
    while (getline(iss, line) && y < maxY - 1) {
        // Truncate line if too long
        if (line.length() > (size_t)(maxX - 4)) {
            line = line.substr(0, maxX - 7) + "...";
        }
        mvwprintw(contentWin, y++, 2, "%s", line.c_str());
    }
    
    wrefresh(contentWin);
}

/**
 * @brief Show a message in the content area
 */
void showMessage(const string &message, int colorPair = 2) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(contentWin);
    box(contentWin, 0, 0);
    
    wattron(contentWin, COLOR_PAIR(colorPair) | A_BOLD);
    mvwprintw(contentWin, 1, 2, "%s", message.c_str());
    wattroff(contentWin, COLOR_PAIR(colorPair) | A_BOLD);
    
    mvwprintw(contentWin, 3, 2, "Press any key to continue...");
    wrefresh(contentWin);
}

/**
 * @brief Get user input (single character)
 */
int getUserChoice() {
    return wgetch(menuWin);
}

/**
 * @brief Async tick system
 */
void asyncTickSystem(Inventory *inv, Stock *stock, PlantCareHandler *handler) {
    int cycles = 0;
    
    while (running.load())
    {
        cycles++;
        tickCounter.store(cycles);
        
        // Update UI every 5 ticks
        if (cycles % 5 == 0)
        {
            updateStatusBar(inv, stock);
        }
        
        // Add plants every 100 ticks
        if (cycles % 100 == 0)
        {
            stock->cleanUpDeadPlants();
            inv->cleanUpDeadPlants();
            inv->moveValidPlantsToStock(stock);

            inv->addLargePlant(inv->getCarnivorousFactory(), handler);
            inv->addMediumPlant(inv->getCarnivorousFactory(), handler);
            inv->addSmallPlant(inv->getCarnivorousFactory(), handler);

            inv->addLargePlant(inv->getTemperateFactory(), handler);
            inv->addMediumPlant(inv->getTemperateFactory(), handler);
            inv->addSmallPlant(inv->getTemperateFactory(), handler);

            inv->addLargePlant(inv->getTropicalFactory(), handler);
            inv->addMediumPlant(inv->getTropicalFactory(), handler);
            inv->addSmallPlant(inv->getTropicalFactory(), handler);

            inv->addLargePlant(inv->getSucculentFactory(), handler);
            inv->addMediumPlant(inv->getSucculentFactory(), handler);
            inv->addSmallPlant(inv->getSucculentFactory(), handler);
            
            plantsAdded.fetch_add(4);
        }
        
        // Tick the inventory
        inv->tick();
        
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * @brief Capture output from a function
 */
string captureOutput(function<void()> func) {
    // Redirect cout to stringstream
    streambuf *oldCoutBuf = cout.rdbuf();
    ostringstream oss;
    cout.rdbuf(oss.rdbuf());
    
    func();
    
    // Restore cout
    cout.rdbuf(oldCoutBuf);
    return oss.str();
}

/**
 * @brief Display inventory
 */
void showInventory(Inventory *inv)
{
    string output = captureOutput([inv]()
    {
        inv->print();
    });
    displayContent(output);
    getUserChoice();
}

/**
 * @brief Display stock
 */
void showStock(Stock *stock) {
    string output = captureOutput([stock]() {
        stock->print();
    });
    displayContent(output);
    getUserChoice();
}

/**
 * @brief Add plants dialog
 */
void addPlantsDialog(Inventory *inv, PlantCareHandler *handler) {
    werase(contentWin);
    box(contentWin, 0, 0);
    echo();
    curs_set(1);
    
    wattron(contentWin, COLOR_PAIR(1) | A_BOLD);
    mvwprintw(contentWin, 1, 2, "ADD PLANTS TO INVENTORY");
    wattroff(contentWin, COLOR_PAIR(1) | A_BOLD);
    
    mvwprintw(contentWin, 3, 2, "Plant Types: [1]Carnivorous [2]Temperate [3]Tropical [4]Succulent");
    mvwprintw(contentWin, 4, 2, "Enter type: ");
    wrefresh(contentWin);
    
    int type = wgetch(contentWin) - '0';
    
    mvwprintw(contentWin, 6, 2, "Sizes: [1]Small [2]Medium [3]Large");
    mvwprintw(contentWin, 7, 2, "Enter size: ");
    wrefresh(contentWin);
    
    int size = wgetch(contentWin) - '0';
    
    mvwprintw(contentWin, 9, 2, "Enter quantity (1-100): ");
    wrefresh(contentWin);
    
    char qtyStr[10];
    wgetnstr(contentWin, qtyStr, 9);
    int qty = atoi(qtyStr);
    
    noecho();
    curs_set(0);
    
    if (qty <= 0 || qty > 100 || type < 1 || type > 4 || size < 1 || size > 3) {
        showMessage("❌ Invalid input!", 4);
        getUserChoice();
        return;
    }
    
    GreenHouse *factory = nullptr;
    switch (type) {
        case 1: factory = inv->getCarnivorousFactory(); break;
        case 2: factory = inv->getTemperateFactory(); break;
        case 3: factory = inv->getTropicalFactory(); break;
        case 4: factory = inv->getSucculentFactory(); break;
    }
    
    for (int i = 0; i < qty; i++) {
        switch (size) {
            case 1: inv->addSmallPlant(factory, handler); break;
            case 2: inv->addMediumPlant(factory, handler); break;
            case 3: inv->addLargePlant(factory, handler); break;
        }
    }
    
    showMessage("✓ Plants added successfully!", 1);
    getUserChoice();
}

/**
 * @brief Customer question dialog
 */
void customerQuestionDialog(Customer *customer) {
    werase(contentWin);
    box(contentWin, 0, 0);
    
    wattron(contentWin, COLOR_PAIR(1) | A_BOLD);
    mvwprintw(contentWin, 1, 2, "CUSTOMER QUESTIONS");
    wattroff(contentWin, COLOR_PAIR(1) | A_BOLD);
    
    vector<string> questions = {
        "How often should I water my plants?",
        "How much sunlight do succulents need?",
        "Do you have carnivorous plants in stock?",
        "I want to buy plants in bulk for my office",
        "Can I purchase tropical plants?",
        "I need care advice for my plant"
    };
    
    for (size_t i = 0; i < questions.size(); i++) {
        mvwprintw(contentWin, 3 + i, 2, "[%zu] %s", i + 1, questions[i].c_str());
    }
    
    mvwprintw(contentWin, 10, 2, "Enter choice (1-6): ");
    wrefresh(contentWin);
    
    int choice = getUserChoice() - '0';
    
    if (choice >= 1 && choice <= 6) {
        customer->askQuestion(questions[choice - 1]);
        showMessage("✓ Question sent to staff!", 1);
    } else {
        showMessage("❌ Invalid choice!", 4);
    }
    
    getUserChoice();
}

/**
 * @brief Show statistics
 */
void showStatistics(Inventory *inv, Stock *stock) {
    ostringstream oss;
    oss << "╔══════════════════════════════════════╗\n";
    oss << "║       SYSTEM STATISTICS              ║\n";
    oss << "╚══════════════════════════════════════╝\n\n";
    oss << "Total Plants in Inventory: " << inv->getPlantCount() << "\n";
    oss << "Total Plants in Stock: " << stock->getPlantCount() << "\n";
    oss << "Total Stock Value: $" << fixed << setprecision(2) << stock->getTotalStockValue() << "\n";
    oss << "System Ticks Elapsed: " << tickCounter.load() << "\n";
    oss << "Plants Auto-Added: " << plantsAdded.load() << "\n";
    oss << "Estimated Runtime: " << (tickCounter.load() * 0.1) << " seconds\n";
    
    displayContent(oss.str());
    getUserChoice();
}

/**
 * @brief Show plant types information
 */
void showPlantTypes() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║         AVAILABLE PLANT TYPES                ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "1. 🦷 CARNIVOROUS PLANTS\n";
    oss << "   - Pitcher Plants\n";
    oss << "   - Sundew\n";
    oss << "   - Nepenthes\n\n";
    oss << "2. 🍃 TEMPERATE PLANTS\n";
    oss << "   - Lilac\n";
    oss << "   - Daisy\n";
    oss << "   - White Oak\n\n";
    oss << "3. 🌴 TROPICAL PLANTS\n";
    oss << "   - Bird of Paradise\n";
    oss << "   - Rubber Plant\n";
    oss << "   - Nerve Plant\n\n";
    oss << "4. 🌵 SUCCULENT PLANTS\n";
    oss << "   - Aloe Vera\n";
    oss << "   - Candelabra\n";
    oss << "   - Hen and Chicks\n";
    
    displayContent(oss.str());
    getUserChoice();
}

/**
 * @brief Show tick information
 */
void showTickInfo() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║           TICK SYSTEM INFO                   ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "The tick system runs asynchronously.\n";
    oss << "It simulates plant growth and care.\n\n";
    oss << "Current tick count: " << tickCounter.load() << "\n";
    oss << "Tick rate: 10 ticks per second\n";
    oss << "New plants every 100 ticks (~10s)\n";
    oss << "UI updates every 5 ticks (0.5s)\n\n";
    oss << "Design Patterns in Action:\n";
    oss << "  • Observer: Plant state changes\n";
    oss << "  • State: Health and growth states\n";
    oss << "  • Chain of Responsibility: Care handlers\n";
    oss << "  • Abstract Factory: Plant factories\n";
    oss << "  • Iterator: Inventory traversal\n";
    oss << "  • Mediator: Staff communication\n";
    
    displayContent(oss.str());
    getUserChoice();
}

/**
 * @brief Main function
 */
int main() {
    try {
        // Initialize core systems
        Inventory *inv = new Inventory();
        Stock *stock = new Stock();
        
        // Create chain of responsibility
        WaterHandler *waterHandler = new WaterHandler();
        SunHandler *sunlightHandler = new SunHandler();
        FertilizerHandler *fertilizerHandler = new FertilizerHandler();
        PruneHandler *pruneHandler = new PruneHandler();
        
        waterHandler->setNext(sunlightHandler);
        sunlightHandler->setNext(fertilizerHandler);
        fertilizerHandler->setNext(pruneHandler);
        
        // Initialize mediator and staff
        CommMediator *mediator = new ConcreteCommMediator();
        vector<StaffMember *> staff;
        
        for (int k = 0; k < 3; k++) {
            Worker *worker = new Worker("Worker" + to_string(k + 1), mediator, inv);
            staff.push_back(worker);
        }
        
        Customer *customer = new Customer("Interactive Customer", mediator);
        
        // Add initial plants
        for (int i = 0; i < 3; i++) {
            inv->addSmallPlant(inv->getCarnivorousFactory(), waterHandler);
            inv->addMediumPlant(inv->getTemperateFactory(), waterHandler);
            inv->addLargePlant(inv->getTropicalFactory(), waterHandler);
            inv->addSmallPlant(inv->getSucculentFactory(), waterHandler);
        }
        
        // Initialize UI
        initUI();
        
        // Start async tick system
        thread tickThread(asyncTickSystem, inv, stock, waterHandler);
        
        // Initial display
        updateStatusBar(inv, stock);
        displayMenu();
        showMessage("Welcome to Plant Store Management System!\n\nThe system is now running.\nUse the menu below to interact.", 1);
        getUserChoice();
        
        // Main loop
        bool exitProgram = false;
        while (!exitProgram) {
            updateStatusBar(inv, stock);
            displayMenu();
            
            int choice = getUserChoice();
            
            switch (choice) {
                case '0':
                    exitProgram = true;
                    break;
                case '1':
                    showInventory(inv);
                    break;
                case '2':
                    showStock(stock);
                    break;
                case '3':
                    addPlantsDialog(inv, waterHandler);
                    break;
                case '4':
                    customerQuestionDialog(customer);
                    break;
                case '5':
                    showStatistics(inv, stock);
                    break;
                case '6':
                    showPlantTypes();
                    break;
                case '7':
                    inv->moveValidPlantsToStock(stock);
                    showMessage("✓ Mature plants moved to stock!", 1);
                    getUserChoice();
                    break;
                case '8':
                    showTickInfo();
                    break;
                case '9':
                    werase(contentWin);
                    box(contentWin, 0, 0);
                    wrefresh(contentWin);
                    break;
                default:
                    showMessage("❌ Invalid choice! Please select 0-9.", 4);
                    getUserChoice();
                    break;
            }
        }
        
        // Cleanup
        running.store(false);
        tickThread.join();
        
        cleanupUI();
        
        delete waterHandler;
        delete sunlightHandler;
        delete fertilizerHandler;
        delete pruneHandler;
        delete mediator;
        delete customer;
        
        for (StaffMember *s : staff) {
            delete s;
        }
        
        cout << "\nThank you for using Plant Store Management System!\n" << endl;
        
        return 0;
    }
    catch (const exception &e) {
        cleanupUI();
        cerr << "Exception: " << e.what() << endl;
        running.store(false);
        return 1;
    }
    catch (...) {
        cleanupUI();
        cerr << "Unknown exception!" << endl;
        running.store(false);
        return 1;
    }
}
