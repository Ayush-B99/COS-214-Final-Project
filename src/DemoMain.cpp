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
 * @brief Update status bar
 */
void updateStatusBar(Inventory *inv, Stock *stock) {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(statusWin);
    box(statusWin, 0, 0);
    
    wattron(statusWin, COLOR_PAIR(2) | A_BOLD);
    mvwprintw(statusWin, 0, 2, " 🌿 PLANT STORE MANAGEMENT SYSTEM 🌿 ");
    wattroff(statusWin, COLOR_PAIR(2) | A_BOLD);
    
    wattron(statusWin, COLOR_PAIR(1));
    mvwprintw(statusWin, 2, 2, "● LIVE");
    wattroff(statusWin, COLOR_PAIR(1));
    
    wattron(statusWin, COLOR_PAIR(3));
    wprintw(statusWin, " Tick: %6d", tickCounter.load());
    wattroff(statusWin, COLOR_PAIR(3));
    
    wattron(statusWin, COLOR_PAIR(2));
    wprintw(statusWin, " │ Inventory: %4d", inv->getPlantCount());
    wprintw(statusWin, " │ Stock: %4d", stock->getPlantCount());
    wprintw(statusWin, " │ Value: $%.2f", stock->getTotalStockValue());
    wattroff(statusWin, COLOR_PAIR(2));
    
    mvwprintw(statusWin, 3, 2, "Auto-Added: %d │ Runtime: %.1fs", 
              plantsAdded.load(), tickCounter.load() * 0.1);
    
    wrefresh(statusWin);
}

/**
 * @brief Display menu
 */
void displayMenu() {
    lock_guard<mutex> lock(ncursesMutex);
    
    werase(menuWin);
    box(menuWin, 0, 0);
    
    wattron(menuWin, COLOR_PAIR(5));
    mvwprintw(menuWin, 1, 2, "[1]Inventory [2]Stock [3]Add [4]Question [5]Stats");
    mvwprintw(menuWin, 2, 2, "[6]Types [7]Move [8]Info [9]Clear [0]Exit");
    wattroff(menuWin, COLOR_PAIR(5));
    
    mvwprintw(menuWin, 3, 2, "Choice: ");
    wrefresh(menuWin);
}

/**
 * @brief Display content with dynamic window resizing
 */
void displayContent(const string &content) {
    lock_guard<mutex> lock(ncursesMutex);
    
    int screenMaxY, screenMaxX;
    getmaxyx(stdscr, screenMaxY, screenMaxX);
    
    // Parse content into lines with wrapping
    istringstream iss(content);
    string line;
    vector<string> lines;
    
    while (getline(iss, line)) {
        if (line.empty()) {
            lines.push_back("");
            continue;
        }
        
        // Wrap long lines
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
    
    // Calculate required height
    int contentHeight = lines.size() + 3; // +3 for border and prompt
    int maxContentHeight = screenMaxY - 11; // Leave room for status and menu
    
    // Delete old content window
    if (contentWin) {
        delwin(contentWin);
    }
    
    // Create new resized content window
    if (contentHeight > maxContentHeight) {
        // Content too large - use max available space with scrolling
        contentWin = newwin(maxContentHeight, screenMaxX, 6, 0);
        scrollok(contentWin, TRUE);
        keypad(contentWin, TRUE);
        
        werase(contentWin);
        box(contentWin, 0, 0);
        
        // Display what fits
        for (int i = 0; i < maxContentHeight - 3 && i < (int)lines.size(); i++) {
            mvwprintw(contentWin, i + 1, 2, "%s", lines[i].c_str());
        }
        
        wattron(contentWin, COLOR_PAIR(3));
        mvwprintw(contentWin, maxContentHeight - 2, 2, 
                  "[Content truncated: %zu lines total] Press any key...", lines.size());
        wattroff(contentWin, COLOR_PAIR(3));
        
        wrefresh(contentWin);
        
    } else {
        // Content fits - resize window to exact size needed
        int newHeight = contentHeight;
        int newY = 6;
        
        // Adjust menu position
        if (menuWin) {
            delwin(menuWin);
        }
        int menuY = newY + newHeight;
        menuWin = newwin(5, screenMaxX, menuY, 0);
        
        // Create perfectly sized content window
        contentWin = newwin(newHeight, screenMaxX, newY, 0);
        keypad(contentWin, TRUE);
        
        werase(contentWin);
        box(contentWin, 0, 0);
        
        // Display all lines
        for (int i = 0; i < (int)lines.size(); i++) {
            mvwprintw(contentWin, i + 1, 2, "%s", lines[i].c_str());
        }
        
        wattron(contentWin, COLOR_PAIR(3));
        mvwprintw(contentWin, newHeight - 2, 2, "Press any key to continue...");
        wattroff(contentWin, COLOR_PAIR(3));
        
        wrefresh(contentWin);
    }
    
    // Wait for key
    nodelay(stdscr, FALSE);
    wgetch(contentWin);
    nodelay(stdscr, TRUE);
    
    // Restore original layout
    if (contentWin) {
        delwin(contentWin);
    }
    if (menuWin) {
        delwin(menuWin);
    }
    
    contentWin = newwin(screenMaxY - 11, screenMaxX, 6, 0);
    menuWin = newwin(5, screenMaxX, screenMaxY - 5, 0);
    scrollok(contentWin, TRUE);
    keypad(contentWin, TRUE);
    
    werase(contentWin);
    box(contentWin, 0, 0);
    wrefresh(contentWin);
}

/**
 * @brief Show message
 */
void showMessage(const string &message, int colorPair = 2) {
    displayContent(message);
}

/**
 * @brief Async tick system
 */
void asyncTickSystem(Inventory *inv, Stock *stock, PlantCareHandler *handler) {
    int cycles = 0;
    
    while (running.load()) {
        cycles++;
        tickCounter.store(cycles);
        
        if (cycles % 5 == 0) {
            updateStatusBar(inv, stock);
        }
        
        if (cycles % 100 == 0) {
            inv->moveValidPlantsToStock(stock);
            inv->addSmallPlant(inv->getCarnivorousFactory(), handler);
            inv->addMediumPlant(inv->getTemperateFactory(), handler);
            inv->addLargePlant(inv->getTropicalFactory(), handler);
            inv->addSmallPlant(inv->getSucculentFactory(), handler);
            plantsAdded.fetch_add(4);
        }
        
        inv->tick();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * @brief Capture output to string
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
    mvwgetnstr(contentWin, 2, 2, buffer, 255);
    
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
 * @brief Show inventory
 */
void showInventory(Inventory *inv) {
    string output = captureOutput([inv]() { inv->print(); });
    displayContent(output);
}

/**
 * @brief Show stock
 */
void showStock(Stock *stock) {
    string output = captureOutput([stock]() { stock->print(); });
    displayContent(output);
}

/**
 * @brief Add plants dialog
 */
void addPlantsDialog(Inventory *inv, PlantCareHandler *handler) {
    string prompt = "Plant Types:\n[1] Carnivorous\n[2] Temperate\n[3] Tropical\n[4] Succulent\n\nEnter type:";
    int type = getInputInt(prompt);
    
    prompt = "Sizes:\n[1] Small\n[2] Medium\n[3] Large\n\nEnter size:";
    int size = getInputInt(prompt);
    
    int qty = getInputInt("Enter quantity (1-100):");
    
    if (qty <= 0 || qty > 100 || type < 1 || type > 4 || size < 1 || size > 3) {
        showMessage("❌ Invalid input!");
        return;
    }
    
    GreenHouse *factory = nullptr;
    string typeStr;
    switch (type) {
        case 1: factory = inv->getCarnivorousFactory(); typeStr = "Carnivorous"; break;
        case 2: factory = inv->getTemperateFactory(); typeStr = "Temperate"; break;
        case 3: factory = inv->getTropicalFactory(); typeStr = "Tropical"; break;
        case 4: factory = inv->getSucculentFactory(); typeStr = "Succulent"; break;
    }
    
    string sizeStr = (size == 1) ? "Small" : (size == 2) ? "Medium" : "Large";
    
    for (int i = 0; i < qty; i++) {
        switch (size) {
            case 1: inv->addSmallPlant(factory, handler); break;
            case 2: inv->addMediumPlant(factory, handler); break;
            case 3: inv->addLargePlant(factory, handler); break;
        }
    }
    
    showMessage("✓ Successfully added " + to_string(qty) + " " + sizeStr + " " + typeStr + " plants!");
}

/**
 * @brief Customer question dialog
 */
void customerQuestionDialog(Customer *customer) {
    vector<string> questions = {
        "How often should I water my plants?",
        "How much sunlight do succulents need?",
        "Do you have carnivorous plants in stock?",
        "I want to buy plants in bulk",
        "Can I purchase tropical plants?",
        "I need care advice"
    };
    
    string prompt = "CUSTOMER QUESTIONS:\n\n";
    for (size_t i = 0; i < questions.size(); i++) {
        prompt += "[" + to_string(i + 1) + "] " + questions[i] + "\n";
    }
    prompt += "\nEnter choice (1-6):";
    
    int choice = getInputInt(prompt);
    
    if (choice >= 1 && choice <= 6) {
        customer->askQuestion(questions[choice - 1]);
        showMessage("✓ Question sent to staff!");
    } else {
        showMessage("❌ Invalid choice!");
    }
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
}

/**
 * @brief Show plant types
 */
void showPlantTypes() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║         AVAILABLE PLANT TYPES                ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "1. 🦷 CARNIVOROUS: Pitcher, Sundew, Nepenthes\n";
    oss << "2. 🍃 TEMPERATE: Lilac, Daisy, White Oak\n";
    oss << "3. 🌴 TROPICAL: Bird of Paradise, Rubber, Nerve\n";
    oss << "4. 🌵 SUCCULENT: Aloe Vera, Candelabra, Hen and Chicks";
    
    displayContent(oss.str());
}

/**
 * @brief Show tick info
 */
void showTickInfo() {
    ostringstream oss;
    oss << "╔══════════════════════════════════════════════╗\n";
    oss << "║           TICK SYSTEM INFO                   ║\n";
    oss << "╚══════════════════════════════════════════════╝\n\n";
    oss << "Current tick: " << tickCounter.load() << "\n";
    oss << "Tick rate: 10 ticks/second\n";
    oss << "New plants: every 100 ticks (~10s)\n";
    oss << "UI updates: every 5 ticks (0.5s)\n\n";
    oss << "Design Patterns:\n";
    oss << "• Observer: Plant state changes\n";
    oss << "• State: Health and growth\n";
    oss << "• Chain of Responsibility: Care handlers\n";
    oss << "• Abstract Factory: Plant factories\n";
    oss << "• Iterator: Collection traversal\n";
    oss << "• Mediator: Communication";
    
    displayContent(oss.str());
}

/**
 * @brief Main function
 */
int main() {
    // Suppress initialization output
    streambuf *oldCoutBuf = cout.rdbuf();
    ostringstream initOutput;
    cout.rdbuf(initOutput.rdbuf());
    
    try {
        // Initialize systems
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
        
        Customer *customer = new Customer("Interactive Customer", mediator);
        
        // Add initial plants
        for (int i = 0; i < 3; i++) {
            inv->addSmallPlant(inv->getCarnivorousFactory(), waterHandler);
            inv->addMediumPlant(inv->getTemperateFactory(), waterHandler);
            inv->addLargePlant(inv->getTropicalFactory(), waterHandler);
            inv->addSmallPlant(inv->getSucculentFactory(), waterHandler);
        }
        
        // Restore cout
        cout.rdbuf(oldCoutBuf);
        
        // Initialize UI
        initUI();
        
        // Start tick thread
        thread tickThread(asyncTickSystem, inv, stock, waterHandler);
        this_thread::sleep_for(chrono::milliseconds(500));
        
        // Initial display
        updateStatusBar(inv, stock);
        displayMenu();
        showMessage("Welcome to Plant Store Management System!\n\nSystem running in background.\nUse menu to interact.");
        
        // Main loop
        bool exitProgram = false;
        while (!exitProgram) {
            updateStatusBar(inv, stock);
            displayMenu();
            
            nodelay(stdscr, FALSE);
            int ch = getch();
            nodelay(stdscr, TRUE);
            
            switch (ch) {
                case '0': exitProgram = true; break;
                case '1': showInventory(inv); break;
                case '2': showStock(stock); break;
                case '3': addPlantsDialog(inv, waterHandler); break;
                case '4': customerQuestionDialog(customer); break;
                case '5': showStatistics(inv, stock); break;
                case '6': showPlantTypes(); break;
                case '7':
                    inv->moveValidPlantsToStock(stock);
                    showMessage("✓ Mature plants moved to stock!");
                    break;
                case '8': showTickInfo(); break;
                case '9':
                    werase(contentWin);
                    box(contentWin, 0, 0);
                    wrefresh(contentWin);
                    break;
            }
            
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        
        // Cleanup
        running.store(false);
        tickThread.join();
        cleanupUI();
        
        cout << "\n✓ Thank you for using Plant Store Management System!\n" << endl;
        
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