#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>
#include <thread>
#include <future>
#include <atomic>
#include <chrono>
#include <iomanip>
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

// Global atomic flags and counters
atomic<bool> running(true);
atomic<int> tickCounter(0);
atomic<int> plantsAdded(0);
mutex coutMutex;  // Protect console output

/**
 * @namespace TerminalUI
 * @brief ANSI escape code utilities for terminal control
 */
namespace TerminalUI
{
    /**
     * @brief Clear the entire screen
     */
    void clearScreen()
    {
        cout << "\033[2J\033[1;1H" << flush;
    }

    /**
     * @brief Move cursor to specific position (1-based row, col)
     */
    void moveCursor(int row, int col)
    {
        cout << "\033[" << row << ";" << col << "H" << flush;
    }

    /**
     * @brief Save current cursor position
     */
    void saveCursor()
    {
        cout << "\033[s" << flush;
    }

    /**
     * @brief Restore saved cursor position
     */
    void restoreCursor()
    {
        cout << "\033[u" << flush;
    }

    /**
     * @brief Hide the cursor
     */
    void hideCursor()
    {
        cout << "\033[?25l" << flush;
    }

    /**
     * @brief Show the cursor
     */
    void showCursor()
    {
        cout << "\033[?25h" << flush;
    }

    /**
     * @brief Clear from cursor to end of line
     */
    void clearLine()
    {
        cout << "\033[K" << flush;
    }

    /**
     * @brief Clear from cursor to end of screen
     */
    void clearToEnd()
    {
        cout << "\033[J" << flush;
    }

    /**
     * @brief Set text color
     */
    void setColor(const string &color)
    {
        if (color == "red")
            cout << "\033[31m";
        else if (color == "green")
            cout << "\033[32m";
        else if (color == "yellow")
            cout << "\033[33m";
        else if (color == "blue")
            cout << "\033[34m";
        else if (color == "magenta")
            cout << "\033[35m";
        else if (color == "cyan")
            cout << "\033[36m";
        else if (color == "white")
            cout << "\033[37m";
        else if (color == "bright_green")
            cout << "\033[92m";
        else if (color == "bright_yellow")
            cout << "\033[93m";
        else if (color == "bright_cyan")
            cout << "\033[96m";
        else
            cout << "\033[0m"; // reset
        cout << flush;
    }

    /**
     * @brief Reset all text attributes
     */
    void resetColor()
    {
        cout << "\033[0m" << flush;
    }

    /**
     * @brief Set bold text
     */
    void setBold()
    {
        cout << "\033[1m" << flush;
    }
}

/**
 * @brief Display live statistics at the top of the screen
 */
void displayLiveStats(Inventory *inv, Stock *stock)
{
    using namespace TerminalUI;

    lock_guard<mutex> lock(coutMutex);

    saveCursor();

    // Line 1: Top border
    moveCursor(1, 1);
    setColor("cyan");
    cout << "╔════════════════════════════════════════════════════════════════════════════════╗";
    clearLine();

    // Line 2: Live stats
    moveCursor(2, 1);
    cout << "║ ";
    setBold();
    setColor("bright_green");
    cout << "● LIVE STATS";
    resetColor();
    setColor("cyan");
    cout << " │ ";

    setColor("white");
    cout << "Tick: ";
    setColor("bright_yellow");
    cout << setw(6) << tickCounter.load();
    setColor("cyan");
    cout << " │ ";

    setColor("white");
    cout << "Inventory: ";
    setColor("bright_cyan");
    cout << setw(4) << inv->getPlantCount();
    setColor("cyan");
    cout << " │ ";

    setColor("white");
    cout << "Stock: ";
    setColor("bright_green");
    cout << setw(4) << stock->getPlantCount();
    setColor("cyan");
    cout << " │ ";

    setColor("white");
    cout << "Value: $";
    setColor("bright_yellow");
    cout << fixed << setprecision(2) << setw(8) << stock->getTotalStockValue();
    resetColor();
    setColor("cyan");
    cout << " ║";
    clearLine();

    // Line 3: Bottom border
    moveCursor(3, 1);
    cout << "╚════════════════════════════════════════════════════════════════════════════════╝";
    clearLine();

    resetColor();
    restoreCursor();
}

/**
 * @brief Async function that continuously ticks the inventory system with live display
 * This simulates the passage of time and plant growth/decay
 */
int asyncTickSystem(Inventory *inv, Stock *stock, PlantCareHandler *handler)
{
    int cycles = 0;

    {
        lock_guard<mutex> lock(coutMutex);
        TerminalUI::moveCursor(4, 1);
        cout << "\n[TICK SYSTEM] Started async tick system..." << endl;
    }

    while (running.load())
    {
        cycles++;
        tickCounter.store(cycles);

        // Update live stats display every 5 ticks (0.5 seconds)
        if (cycles % 5 == 0)
        {
            displayLiveStats(inv, stock);
        }

        // Every 100 cycles, add new plants to maintain stock
        if (cycles % 100 == 0)
        {
            inv->moveValidPlantsToStock(stock);

            inv->addSmallPlant(inv->getCarnivorousFactory(), handler);
            inv->addMediumPlant(inv->getTemperateFactory(), handler);
            inv->addLargePlant(inv->getTropicalFactory(), handler);
            inv->addSmallPlant(inv->getSucculentFactory(), handler);

            plantsAdded.fetch_add(4);

            {
                lock_guard<mutex> lock(coutMutex);
                TerminalUI::saveCursor();
                TerminalUI::moveCursor(4, 1);
                TerminalUI::setColor("green");
                cout << "[TICK " << cycles << "] Added 4 new plants to inventory (Total added: " 
                     << plantsAdded.load() << ")";
                TerminalUI::clearLine();
                TerminalUI::resetColor();
                TerminalUI::restoreCursor();
            }
        }

        // Tick the inventory to update plant states
        inv->tick();

        // Sleep for 100ms between ticks (10 ticks per second)
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    {
        lock_guard<mutex> lock(coutMutex);
        TerminalUI::moveCursor(4, 1);
        TerminalUI::setColor("yellow");
        cout << "\n[TICK SYSTEM] Stopped after " << cycles << " cycles.";
        TerminalUI::clearLine();
        TerminalUI::resetColor();
    }

    return cycles;
}

/**
 * @brief Display the main menu (reserves space for live stats)
 */
void displayMenu()
{
    lock_guard<mutex> lock(coutMutex);

    // Move below the live stats area
    TerminalUI::moveCursor(6, 1);
    TerminalUI::clearToEnd();

    cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║           🌿 PLANT STORE MANAGEMENT SYSTEM 🌿           ║" << endl;
    cout << "╠══════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. View Inventory                                       ║" << endl;
    cout << "║  2. View Stock (Plants Ready for Sale)                  ║" << endl;
    cout << "║  3. Add New Plants                                       ║" << endl;
    cout << "║  4. Ask a Question (Customer)                            ║" << endl;
    cout << "║  5. View System Statistics                               ║" << endl;
    cout << "║  6. View Available Plant Types                           ║" << endl;
    cout << "║  7. Move Mature Plants to Stock                          ║" << endl;
    cout << "║  8. Display Tick Information                             ║" << endl;
    cout << "║  9. Clear Screen                                         ║" << endl;
    cout << "║  0. Exit                                                 ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << "\n→ Enter choice: ";
    cout << flush;
}

/**
 * @brief Display plant type selection menu
 */
void displayPlantTypeMenu()
{
    cout << "\n--- Select Plant Type ---" << endl;
    cout << "1. Carnivorous Plants" << endl;
    cout << "2. Temperate Plants" << endl;
    cout << "3. Tropical Plants" << endl;
    cout << "4. Succulent Plants" << endl;
    cout << "→ Enter choice: ";
}

/**
 * @brief Display plant size selection menu
 */
void displayPlantSizeMenu()
{
    cout << "\n--- Select Plant Size ---" << endl;
    cout << "1. Small Plant" << endl;
    cout << "2. Medium Plant" << endl;
    cout << "3. Large Plant" << endl;
    cout << "→ Enter choice: ";
}

/**
 * @brief Add plants to inventory based on user selection
 */
void addPlantsToInventory(Inventory *inv, PlantCareHandler *handler)
{
    int typeChoice, sizeChoice, quantity;

    displayPlantTypeMenu();
    cin >> typeChoice;

    displayPlantSizeMenu();
    cin >> sizeChoice;

    cout << "→ Enter quantity to add: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > 100)
    {
        TerminalUI::setColor("red");
        cout << "\n❌ Invalid quantity. Please enter a value between 1 and 100." << endl;
        TerminalUI::resetColor();
        return;
    }

    GreenHouse *factory = nullptr;
    string plantType;

    switch (typeChoice)
    {
    case 1:
        factory = inv->getCarnivorousFactory();
        plantType = "Carnivorous";
        break;
    case 2:
        factory = inv->getTemperateFactory();
        plantType = "Temperate";
        break;
    case 3:
        factory = inv->getTropicalFactory();
        plantType = "Tropical";
        break;
    case 4:
        factory = inv->getSucculentFactory();
        plantType = "Succulent";
        break;
    default:
        TerminalUI::setColor("red");
        cout << "\n❌ Invalid plant type selection!" << endl;
        TerminalUI::resetColor();
        return;
    }

    string sizeStr;
    for (int i = 0; i < quantity; i++)
    {
        Plant *plant = nullptr;
        switch (sizeChoice)
        {
        case 1:
            plant = inv->addSmallPlant(factory, handler);
            sizeStr = "Small";
            break;
        case 2:
            plant = inv->addMediumPlant(factory, handler);
            sizeStr = "Medium";
            break;
        case 3:
            plant = inv->addLargePlant(factory, handler);
            sizeStr = "Large";
            break;
        default:
            TerminalUI::setColor("red");
            cout << "\n❌ Invalid size selection!" << endl;
            TerminalUI::resetColor();
            return;
        }
    }

    TerminalUI::setColor("green");
    cout << "\n✓ Successfully added " << quantity << " " << sizeStr
         << " " << plantType << " plant(s) to inventory!" << endl;
    TerminalUI::resetColor();
}

/**
 * @brief Display system statistics
 */
void displayStatistics(Inventory *inv, Stock *stock)
{
    cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    SYSTEM STATISTICS                     ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << "\nTotal Plants in Inventory: " << inv->getPlantCount() << endl;
    cout << "Total Plants in Stock: " << stock->getPlantCount() << endl;
    cout << "Total Stock Value: $" << fixed << setprecision(2)
         << stock->getTotalStockValue() << endl;
    cout << "System Ticks Elapsed: " << tickCounter.load() << endl;
    cout << "Plants Auto-Added: " << plantsAdded.load() << endl;
    cout << "Estimated Runtime: " << (tickCounter.load() * 0.1) << " seconds" << endl;
}

/**
 * @brief Display available plant types information
 */
void displayPlantTypes()
{
    cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║                  AVAILABLE PLANT TYPES                   ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << "\n1. 🦷 CARNIVOROUS PLANTS" << endl;
    cout << "   - Pitcher Plants: Trap insects in pitcher-shaped leaves" << endl;
    cout << "   - Sundew: Uses sticky droplets to catch prey" << endl;
    cout << "   - Nepenthes: Large tropical pitcher plants" << endl;

    cout << "\n2. 🍃 TEMPERATE PLANTS" << endl;
    cout << "   - Lilac: Fragrant flowering shrubs" << endl;
    cout << "   - Daisy: Classic cheerful flowers" << endl;
    cout << "   - White Oak: Majestic shade trees" << endl;

    cout << "\n3. 🌴 TROPICAL PLANTS" << endl;
    cout << "   - Bird of Paradise: Exotic orange flowers" << endl;
    cout << "   - Rubber Plant: Large glossy leaves" << endl;
    cout << "   - Nerve Plant: Colorful veined leaves" << endl;

    cout << "\n4. 🌵 SUCCULENT PLANTS" << endl;
    cout << "   - Aloe Vera: Medicinal gel-filled leaves" << endl;
    cout << "   - Candelabra: Tall branching cacti" << endl;
    cout << "   - Hen and Chicks: Rosette-forming succulents" << endl;
}

/**
 * @brief Customer asks a question through the mediator system
 */
void customerAskQuestion(Customer *customer, vector<string> &questions)
{
    cout << "\n--- Customer Questions ---" << endl;
    cout << "1. How often should I water my plants?" << endl;
    cout << "2. How much sunlight do succulents need?" << endl;
    cout << "3. Do you have carnivorous plants in stock?" << endl;
    cout << "4. I want to buy plants in bulk for my office" << endl;
    cout << "5. Can I purchase tropical plants?" << endl;
    cout << "6. I need care advice for my plant" << endl;
    cout << "7. Enter custom question" << endl;
    cout << "→ Enter choice: ";

    int choice;
    cin >> choice;
    cin.ignore(); // Clear newline

    string question;
    switch (choice)
    {
    case 1:
        question = "How often should I water my plants?";
        break;
    case 2:
        question = "How much sunlight do succulents need?";
        break;
    case 3:
        question = "Do you have carnivorous plants in stock?";
        break;
    case 4:
        question = "I want to buy plants in bulk for my office";
        break;
    case 5:
        question = "Can I purchase tropical plants?";
        break;
    case 6:
        question = "I need care advice for my plant";
        break;
    case 7:
        cout << "→ Enter your question: ";
        getline(cin, question);
        break;
    default:
        TerminalUI::setColor("red");
        cout << "\n❌ Invalid choice!" << endl;
        TerminalUI::resetColor();
        return;
    }

    customer->askQuestion(question);
    questions.push_back(question);
    
    TerminalUI::setColor("green");
    cout << "\n✓ Question sent! A staff member will respond through the mediator." << endl;
    TerminalUI::resetColor();
}

/**
 * @brief Display tick information
 */
void displayTickInfo()
{
    cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║                   TICK SYSTEM INFO                       ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << "\nThe tick system runs asynchronously in the background." << endl;
    cout << "It simulates the passage of time for plant growth and care." << endl;
    cout << "\nCurrent tick count: " << tickCounter.load() << endl;
    cout << "Tick rate: 10 ticks per second (100ms per tick)" << endl;
    cout << "New plants added every 100 ticks (~10 seconds)" << endl;
    cout << "Live stats update every 5 ticks (0.5 seconds)" << endl;
    cout << "\nPatterns in action:" << endl;
    cout << "  • Observer Pattern: Plants notify observers of state changes" << endl;
    cout << "  • State Pattern: Plant health and growth states" << endl;
    cout << "  • Chain of Responsibility: Plant care handlers" << endl;
    cout << "  • Abstract Factory: Different plant type factories" << endl;
    cout << "  • Iterator Pattern: Traversing inventory and stock" << endl;
    cout << "  • Mediator Pattern: Staff and customer communication" << endl;
}

int main()
{
    try
    {
        // Initialize terminal
        TerminalUI::clearScreen();
        TerminalUI::hideCursor();

        cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
        cout << "║      INITIALIZING PLANT STORE MANAGEMENT SYSTEM...       ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════╝" << endl;

        // Initialize core systems
        Inventory *inv = new Inventory();
        Stock *stock = new Stock();

        // Create chain of responsibility for plant care
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

        for (int k = 0; k < 3; k++)
        {
            Worker *worker = new Worker("Worker" + to_string(k + 1), mediator, inv);
            staff.push_back(worker);
        }

        // Create a customer for interaction
        Customer *customer = new Customer("Interactive Customer", mediator);
        vector<string> questionHistory;

        // Add initial plants to get started
        cout << "\n[INIT] Adding initial plant inventory..." << endl;
        for (int i = 0; i < 3; i++)
        {
            inv->addSmallPlant(inv->getCarnivorousFactory(), waterHandler);
            inv->addMediumPlant(inv->getTemperateFactory(), waterHandler);
            inv->addLargePlant(inv->getTropicalFactory(), waterHandler);
            inv->addSmallPlant(inv->getSucculentFactory(), waterHandler);
        }

        cout << "[INIT] Initial inventory created!" << endl;
        cout << "[INIT] Starting async tick system..." << endl;

        // Start the async tick system
        future<int> tickFuture = async(launch::async, asyncTickSystem, inv, stock, waterHandler);

        // Give the tick system a moment to start
        this_thread::sleep_for(chrono::milliseconds(500));

        // Clear screen and set up live display
        TerminalUI::clearScreen();
        displayLiveStats(inv, stock);

        cout << "\n\n[READY] System initialized! You can now interact with the store.\n" << endl;

        // Main interactive loop
        int choice;
        bool exitProgram = false;

        while (!exitProgram)
        {
            TerminalUI::showCursor();
            displayMenu();
            cin >> choice;
            TerminalUI::hideCursor();

            // Clear the menu area before showing output
            TerminalUI::moveCursor(6, 1);
            TerminalUI::clearToEnd();

            switch (choice)
            {
            case 0:
                cout << "\n[SHUTDOWN] Stopping tick system..." << endl;
                running.store(false);
                tickFuture.wait();
                cout << "[SHUTDOWN] Tick system stopped." << endl;
                exitProgram = true;
                break;

            case 1:
                cout << "\n═══════════════ INVENTORY ═══════════════" << endl;
                inv->print();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 2:
                cout << "\n═══════════════ STOCK ═══════════════" << endl;
                stock->print();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 3:
                addPlantsToInventory(inv, waterHandler);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 4:
                customerAskQuestion(customer, questionHistory);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 5:
                displayStatistics(inv, stock);
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 6:
                displayPlantTypes();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 7:
                cout << "\n[ACTION] Moving mature plants to stock..." << endl;
                inv->moveValidPlantsToStock(stock);
                TerminalUI::setColor("green");
                cout << "✓ Plants moved successfully!" << endl;
                TerminalUI::resetColor();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 8:
                displayTickInfo();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 9:
                TerminalUI::clearScreen();
                displayLiveStats(inv, stock);
                break;

            default:
                TerminalUI::setColor("red");
                cout << "\n❌ Invalid choice! Please select 0-9." << endl;
                TerminalUI::resetColor();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
            }

            // Small delay to prevent race conditions
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Cleanup
        TerminalUI::showCursor();
        TerminalUI::clearScreen();
        
        cout << "\n[CLEANUP] Freeing resources..." << endl;

        // delete inv;
        // delete stock;
        delete waterHandler;
        delete sunlightHandler;
        delete fertilizerHandler;
        delete pruneHandler;
        delete mediator;
        delete customer;

        for (StaffMember *s : staff)
        {
            delete s;
        }

        cout << "[CLEANUP] Complete!" << endl;
        cout << "\n╔══════════════════════════════════════════════════════════╗" << endl;
        cout << "║         Thank you for using Plant Store System!         ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════╝\n" << endl;

        TerminalUI::resetColor();
        return 0;
    }
    catch (const char *msg)
    {
        TerminalUI::showCursor();
        TerminalUI::resetColor();
        cerr << "\n❌ Exception caught: " << msg << endl;
        running.store(false);
        return 1;
    }
    catch (const exception &e)
    {
        TerminalUI::showCursor();
        TerminalUI::resetColor();
        cerr << "\n❌ Exception caught: " << e.what() << endl;
        running.store(false);
        return 1;
    }
    catch (...)
    {
        TerminalUI::showCursor();
        TerminalUI::resetColor();
        cerr << "\n❌ Unknown exception caught!" << endl;
        running.store(false);
        return 1;
    }
}