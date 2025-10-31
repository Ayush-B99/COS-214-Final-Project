#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>
#include <thread>
#include <future>

#include "../include/Caretaker.h"
#include "../include/Memento.h"

using namespace std;

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
#include "../include/Plant.h"
#include "../include/PotDecorator.h"
#include "../include/FertilizerDecorator.h"
#include "../include/PlantDecorator.h"
#include "../include/ConcreteCommMediator.h"
#include "../include/ConcreteGrowthObserver.h"
#include "../include/Manager.h"
#include "../include/Worker.h"
#include "../include/Customer.h"
#include "../include/WaterHandler.h"
#include "../include/SunHandler.h"
#include "../include/FertilizerHandler.h"
#include "../include/PruneHandler.h"
#include "../include/Company.h"
#include "../include/Water.h"
#include "../include/Sun.h"
#include "../include/Fertilizer.h"
#include "../include/Prune.h"
// for inventory functionality
#include "../include/Storage.h"
#include "../include/Inventory.h"
#include "../include/Stock.h"
#include "../include/PlantNode.h"
#include "../include/Iterator.h"
#include "../include/InventoryIterator.h"

void testAbstractFactory();
void testDecoratorPattern();
void testPatternsTogether();

void testBasicPlantCreation();
void testGrowthProgression();
void testHealthDegradation();
void testHealthRecovery();
void testIndividualCareActions();
void testDeadState();

//Pattern 1 : Abstract Factory
void testAbstractFactory();
//Pattern 2 : Decorator
void testDecoratorPattern();
//Pattern 3 : State Pattern (Plant Growth & Health State)
void testStatePattern();
//Patten 4 : Chain of Responsibility(Care Handlers)
void testChainOfResponsibility();
//Pattern 5: Command Pattern(Care Commands)
void testCommandPattern();
// Pattern 6: Observer Pattern (Growth Observer)
void testObserverPattern();
// Pattern 7: Mediator (Communication System)
void testMediatorPattern();
// Pattern 8: Composite & Iterator (Inventory System)
void testIteratorPattern();
//pattern 9: composite
void testCompositePattern();
// Pattern 10: Integrated System Test
void testIntegratedSystem();


void testAll();

// void testPlantGrowth();

void testPlantGrowth()
{
    cout << "=== PLANT GROWTH TESTING ===" << endl;
    cout << endl;

    CarnivorousPlantFactory carnivorousFactory;
    Plant *venusFlytrap = carnivorousFactory.createSmallPlant();
    // ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(venusFlytrap);

    WaterHandler *waterHandler = new WaterHandler();
    SunHandler *sunHandler = new SunHandler();
    FertilizerHandler *fertilizerHandler = new FertilizerHandler();
    PruneHandler *pruneHandler = new PruneHandler();

    waterHandler->setNext(sunHandler);
    sunHandler->setNext(fertilizerHandler);
    fertilizerHandler->setNext(pruneHandler);

    venusFlytrap->setCareStrategy(waterHandler);

    int i = 0;
    while (i < 800)
    {
        cout << "--- Growth Cycle " << (i + 1) << " ---" << endl;
        venusFlytrap->printHealthStatus();
        venusFlytrap->printGrowthStatus();

        venusFlytrap->tick();

        // venusFlytrap->printFullStatus();

        i++;
    }

    delete venusFlytrap;
    delete waterHandler;
    delete sunHandler;
    delete pruneHandler;
    delete fertilizerHandler;
}

void testCommMediator();

void testInventory();

void testStaffWithInventory();

int main()
{
    try
    {
        cout << "PLANT STORE PATTERN TESTING" << endl;
        cout << "============================" << endl;
        cout << endl;

        // // ayush testing mem fine
        testAbstractFactory();
        testDecoratorPattern();
        testPatternsTogether();

        // // // diya testing mem fine
        testBasicPlantCreation();
        testGrowthProgression();
        testHealthDegradation();
        testHealthRecovery();
        testIndividualCareActions();
        testDeadState();

        // // //jaitin testing mem fine
        testPlantGrowth();

        // // //chimney testing mem fine
        testCommMediator();
        testStaffWithInventory();

        // // //shavir testing mem leaks
        testInventory();

        //didi testing
        //testAbstractFactoryPattern();
        testDecoratorPattern();
        testStatePattern();
        //testChainOfResponsibilityPattern();
        testCommandPattern();
        testObserverPattern();
        testMediatorPattern();
        testCompositePattern();
        testIteratorPattern();

        cout << "INTEGRATED SYSTEM TEST:" << endl;
        cout << "-------------------------" << endl;
        testIntegratedSystem();

        // testall
        testAll();

        cout << "All tests completed successfully!" << endl;
        return 0;
    }
    catch (const char *msg)
    {
        cerr << "Exception caught: " << msg << endl;
        return 1;
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception caught!" << endl;
        return 1;
    }
}

void testAbstractFactory()
{
    cout << "=== ABSTRACT FACTORY PATTERN TESTING: ===" << endl;
    cout << endl;

    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    // sotred in vector to try and make mem management easier
    vector<Plant *> allPlants;

    // Testing Factories
    cout << "--- Temperate Plants ---" << endl;
    Plant *temperateSmall = temperateFactory.createSmallPlant();
    Plant *temperateMedium = temperateFactory.createMediumPlant();
    Plant *temperateLarge = temperateFactory.createLargePlant();

    if (temperateSmall)
    {
        cout << "Small: " << temperateSmall->getDescription() << endl;
        allPlants.push_back(temperateSmall);
    }

    if (temperateMedium)
    {
        cout << "Medium: " << temperateMedium->getDescription() << endl;
        allPlants.push_back(temperateMedium);
    }

    if (temperateLarge)
    {
        cout << "Large: " << temperateLarge->getDescription() << endl;
        allPlants.push_back(temperateLarge);
    }
    cout << endl;

    cout << "--- Tropical Plants ---" << endl;
    Plant *tropicalSmall = tropicalFactory.createSmallPlant();
    Plant *tropicalMedium = tropicalFactory.createMediumPlant();
    Plant *tropicalLarge = tropicalFactory.createLargePlant();

    if (tropicalSmall)
    {
        cout << "Small: " << tropicalSmall->getDescription() << endl;
        allPlants.push_back(tropicalSmall);
    }

    if (tropicalMedium)
    {
        cout << "Medium: " << tropicalMedium->getDescription() << endl;
        allPlants.push_back(tropicalMedium);
    }

    if (tropicalLarge)
    {
        cout << "Large: " << tropicalLarge->getDescription() << endl;
        allPlants.push_back(tropicalLarge);
    }
    cout << endl;

    // Test Carnivorous Factory
    cout << "--- Carnivorous Plants ---" << endl;
    Plant *carnivorousSmall = carnivorousFactory.createSmallPlant();
    Plant *carnivorousMedium = carnivorousFactory.createMediumPlant();
    Plant *carnivorousLarge = carnivorousFactory.createLargePlant();

    if (carnivorousSmall)
    {
        cout << "Small: " << carnivorousSmall->getDescription() << endl;
        allPlants.push_back(carnivorousSmall);
    }

    if (carnivorousMedium)
    {
        cout << "Medium: " << carnivorousMedium->getDescription() << endl;
        allPlants.push_back(carnivorousMedium);
    }

    if (carnivorousLarge)
    {
        cout << "Large: " << carnivorousLarge->getDescription() << endl;
        allPlants.push_back(carnivorousLarge);
    }
    cout << endl;

    cout << "--- Succulent Plants ---" << endl;
    Plant *succulentSmall = succulentFactory.createSmallPlant();
    Plant *succulentMedium = succulentFactory.createMediumPlant();
    Plant *succulentLarge = succulentFactory.createLargePlant();

    if (succulentSmall)
    {
        cout << "Small: " << succulentSmall->getDescription() << endl;
        allPlants.push_back(succulentSmall);
    }

    if (succulentMedium)
    {
        cout << "Medium: " << succulentMedium->getDescription() << endl;
        allPlants.push_back(succulentMedium);
    }

    if (succulentLarge)
    {
        cout << "Large: " << succulentLarge->getDescription() << endl;
        allPlants.push_back(succulentLarge);
    }
    cout << endl;

    // Test cloning - manage cloned plants separately
    cout << "--- Testing Cloning ---" << endl;
    vector<Plant *> clonedPlants;

    if (temperateSmall)
    {
        Plant *clonedDaisy = temperateSmall->clone();
        cout << "Original: " << temperateSmall->getDescription() << endl;
        cout << "Clone: " << clonedDaisy->getDescription() << endl;
        clonedPlants.push_back(clonedDaisy);
    }

    if (temperateMedium)
    {
        Plant *clonedLilac = temperateMedium->clone();
        cout << "Original: " << temperateMedium->getDescription() << endl;
        cout << "Clone: " << clonedLilac->getDescription() << endl;
        clonedPlants.push_back(clonedLilac);
    }

    if (temperateLarge)
    {
        Plant *clonedWhiteOak = temperateLarge->clone();
        cout << "Original: " << temperateLarge->getDescription() << endl;
        cout << "Clone: " << clonedWhiteOak->getDescription() << endl;
        clonedPlants.push_back(clonedWhiteOak);
    }

    cout << endl;

    // Cleanup: Delete all plants
    for (Plant *plant : allPlants)
    {
        delete plant;
    }

    for (Plant *plant : clonedPlants)
    {
        delete plant;
    }
}

void testDecoratorPattern()
{
    cout << "=== TESTING DECORATOR PATTERN ===" << endl;
    cout << endl;

    // Create plants using unique_ptr
    auto daisy = std::make_unique<Daisy>();
    auto aloe = std::make_unique<AloeVera>();
    auto nepenthes = std::make_unique<Nepenthes>();

    cout << "--- Basic Plants with no decoration ---" << endl;
    cout << "Daisy: " << daisy->getDescription() << " - Price: R" << daisy->getPrice() << endl;
    cout << "Aloe Vera: " << aloe->getDescription() << " - Price: R" << aloe->getPrice() << endl;
    cout << "Nepenthes: " << nepenthes->getDescription() << " - Price: R" << nepenthes->getPrice() << endl;
    cout << endl;

    // Test individual decorators - use std::move to transfer ownership
    cout << "--- Individual Decorators ---" << endl;

    auto daisyInClayPot = std::make_unique<PotDecorator>(std::move(daisy), "Clay");
    cout << "Daisy in Clay Pot: " << daisyInClayPot->getDescription() << " - Price: R" << daisyInClayPot->getPrice() << endl;

    auto aloeWithFertilizer = std::make_unique<FertilizerDecorator>(std::move(aloe), "Organic");
    cout << "Aloe with Fertilizer: " << aloeWithFertilizer->getDescription() << " - Price: R" << aloeWithFertilizer->getPrice() << endl;
    cout << endl;

    // Test multiple decorations - create new plants for each chain
    cout << "--- Multiple Decorations ---" << endl;

    auto premiumNepenthes = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(std::make_unique<Nepenthes>(), "Decorative"),
        "Slow-Release");
    cout << "Premium Nepenthes: " << premiumNepenthes->getDescription() << " - Price: R" << premiumNepenthes->getPrice() << endl;

    // Different pot types
    auto daisyCeramic = std::make_unique<PotDecorator>(std::make_unique<Daisy>(), "Ceramic");
    auto daisyPlastic = std::make_unique<PotDecorator>(std::make_unique<Daisy>(), "Plastic");
    cout << "Daisy Ceramic: " << daisyCeramic->getDescription() << " - Price: R" << daisyCeramic->getPrice() << endl;
    cout << "Daisy Plastic: " << daisyPlastic->getDescription() << " - Price: R" << daisyPlastic->getPrice() << endl;
    cout << endl;

    // Different fertilizer types
    cout << "--- Different Fertilizer Types ---" << endl;
    auto aloeOrganic = std::make_unique<FertilizerDecorator>(std::make_unique<AloeVera>(), "Organic");
    auto aloeLiquid = std::make_unique<FertilizerDecorator>(std::make_unique<AloeVera>(), "Liquid");
    auto aloeSlowRelease = std::make_unique<FertilizerDecorator>(std::make_unique<AloeVera>(), "Slow-Release");

    cout << "Aloe Organic: " << aloeOrganic->getDescription() << " - Price: R" << aloeOrganic->getPrice() << endl;
    cout << "Aloe Liquid: " << aloeLiquid->getDescription() << " - Price: R" << aloeLiquid->getPrice() << endl;
    cout << "Aloe Slow-Release: " << aloeSlowRelease->getDescription() << " - Price: R" << aloeSlowRelease->getPrice() << endl;
    cout << endl;

    cout << "--- Testing Construction Methods ---" << endl;

    // Method 1: Direct construction with smart pointers
    auto nested = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(std::make_unique<WhiteOak>(), "Clay"),
        "Organic");
    cout << "Nested (smart pointers): " << nested->getDescription() << endl;

    // Method 2: Step-by-step construction
    auto step1 = std::make_unique<WhiteOak>();
    auto step2 = std::make_unique<PotDecorator>(std::move(step1), "Clay");
    auto step3 = std::make_unique<FertilizerDecorator>(std::move(step2), "Organic");
    cout << "Step-by-step: " << step3->getDescription() << endl;

    // No manual deletion needed - smart pointers handle cleanup automatically!
    cout << endl;
}

void testPatternsTogether()
{
    cout << "=== TESTING PATTERNS TOGETHER ===" << endl;
    cout << endl;

    // Create factories
    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    cout << "--- Creating Premium Plant Packages ---" << endl;

    // Create plants from factories and decorate them - convert raw pointers to unique_ptr
    auto premiumTemperatePackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(temperateFactory.createMediumPlant()),
            "Ceramic"),
        "Slow-Release");

    auto premiumTropicalPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(tropicalFactory.createSmallPlant()),
            "Decorative"),
        "Liquid");

    auto premiumCarnivorousPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(carnivorousFactory.createLargePlant()),
            "Clay"),
        "Organic");

    auto premiumSucculentPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(succulentFactory.createLargePlant()),
            "Decorative"),
        "Slow-Release");

    if (premiumTemperatePackage)
    {
        cout << "Premium Temperate Package: " << premiumTemperatePackage->getDescription() << " - Price: R" << premiumTemperatePackage->getPrice() << endl;
    }

    if (premiumTropicalPackage)
    {
        cout << "Premium Tropical Package: " << premiumTropicalPackage->getDescription() << " - Price: R" << premiumTropicalPackage->getPrice() << endl;
    }

    if (premiumCarnivorousPackage)
    {
        cout << "Premium Carnivorous Package: " << premiumCarnivorousPackage->getDescription() << " - Price: R" << premiumCarnivorousPackage->getPrice() << endl;
    }

    if (premiumSucculentPackage)
    {
        cout << "Premium Succulent Package: " << premiumSucculentPackage->getDescription() << " - Price: R" << premiumSucculentPackage->getPrice() << endl;
    }

    cout << endl;

    cout << "--- Creating Multiple Decorated Plants from Factory ---" << endl;

    // Create multiple plants from factory and decorate differently
    vector<std::unique_ptr<Plant>> decoratedPlants;

    // Different decoration combos
    decoratedPlants.push_back(std::make_unique<PotDecorator>(
        std::unique_ptr<Plant>(temperateFactory.createSmallPlant()), "Plastic"));

    decoratedPlants.push_back(std::make_unique<FertilizerDecorator>(
        std::unique_ptr<Plant>(temperateFactory.createSmallPlant()), "Organic"));

    decoratedPlants.push_back(std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(temperateFactory.createLargePlant()),
            "Decorative"),
        "Slow-Release"));

    for (size_t i = 0; i < decoratedPlants.size(); i++)
    {
        cout << "Plant " << (i + 1) << ": " << decoratedPlants[i]->getDescription() << " - Price: R" << decoratedPlants[i]->getPrice() << endl;
    }
    cout << endl;

    // No manual deletion needed - smart pointers handle cleanup automatically!
}

// made a concrete plant class without abstract factory for testing in isolation
class TestPlant : public Plant
{

public:
    TestPlant(string species) : Plant(species)
    {
        setGrowthRequirements(2, 3, 4); // seed: 2 cycles, sprout: 3 cycles, mature: 4 cycles
        setSize("small");
        setPrice(69.99);
        setDescription("like a little succulant idk");
    }

    Plant *clone() override
    {
        return new TestPlant(*this);
    }
};

// Mock observer for testing notifications
// class TestObserver : public ConcreteGrowthObserver
// {
// public:
//     void onGrowthChange(Plant *plant) override
//     {
//         cout << "OBSERVER: " << plant->getSpecies() << " growth state changed!" << endl;
//     }
// };

void testBasicPlantCreation()
{
    cout << "=== TEST 1: Basic Plant Creation ===" << endl;
    TestPlant plant("HenAndChicks");

    cout << "Species: " << plant.getSpecies() << endl;
    cout << "Description: " << plant.getDescription() << endl;
    cout << "Price: $" << plant.getPrice() << endl;
    cout << "Size: " << plant.getsize() << endl;
    cout << "Is Dead: " << (plant.isDead() ? "Yes" : "No") << endl;
    // cout << "Is Mature: " << (plant.isMature() ? "Yes" : "No") << endl;

    plant.printFullStatus();
    cout << endl;
}

void testGrowthProgression()
{
    cout << "=== TEST 2: Growth Progression ===" << endl;
    TestPlant plant("Sunflower");

    cout << "Initial state:" << endl;
    plant.printGrowthStatus();
    plant.printCurrentNeeds();

    // Simulate progression through all growth stages
    for (int i = 0; i < 15; i++)
    { // Increased to 15 to account for all stages
        cout << "--- Care Cycle " << (i + 1) << " ---" << endl;

        // Print current needs to see what's required
        plant.printCurrentNeeds();

        // ALWAYS provide ALL required care for the current growth stage
        vector<string> requiredCare = plant.getGrowthState()->getRequiredCare();

        // Provide all required care actions
        for (const string &care : requiredCare)
        {
            if (care == "water")
            {
                plant.receiveWatering();
            }
            else if (care == "sunlight")
            {
                plant.receiveSunlight();
            }
            else if (care == "fertilizer")
            {
                plant.receiveFertilizing();
            }
            else if (care == "prune")
            {
                plant.receivePruning();
            }
        }

        plant.completeCareSession();
        plant.printGrowthStatus();

        // Check if plant should be removed (dead or sold)
        if (plant.shouldRemoveFromInventory())
        {
            if (plant.isDead())
            {
                cout << "Plant died! Remove from inventory." << endl;
            }
            else
            {
                cout << "Plant sold! Remove from inventory." << endl;
            }
            break;
        }

        // Check if plant is ready for stock (mature and pruned)
        if (plant.isReadyForStock())
        {
            cout << "*** PLANT READY FOR STOCK! ***" << endl;
        }

        cout << endl;
    }

    cout << endl;
}

void testHealthDegradation()
{
    cout << "=== TEST 3: Health Degradation ===" << endl;
    TestPlant plant("Cactus");

    cout << "Initial health:" << endl;
    plant.printHealthStatus();

    for (int i = 0; i < 3; i++)
    {
        cout << "--- Care Cycle " << (i + 1) << " (INCOMPLETE CARE) ---" << endl;

        // Only do partial care (miss some requirements)
        if (i % 2 == 0)
        {
            plant.receiveWatering();
        }
        // Don't provide sunlight (incomplete care)

        plant.completeCareSession();
        plant.printHealthStatus();

        if (plant.isDead())
        {
            cout << "Plant has died!" << endl;
            break;
        }
    }
    cout << endl;
}

void testHealthRecovery()
{
    cout << "=== TEST 4: Health Recovery ===" << endl;
    TestPlant plant("Fern");

    cout << "Degrading health..." << endl;
    for (int i = 0; i < 2; i++)
    {
        plant.receiveWatering(); // Only water, no sunlight
        plant.completeCareSession();
    }
    plant.printHealthStatus();

    // Now provide complete care to recover
    cout << "Recovering health..." << endl;
    for (int i = 0; i < 2; i++)
    {
        plant.receiveWatering();
        plant.receiveSunlight();
        plant.completeCareSession();
        plant.printHealthStatus();
    }
    cout << endl;
}

void testIndividualCareActions()
{
    cout << "=== TEST 5: Individual Care Actions ===" << endl;
    TestPlant plant("Orchid");

    cout << "Initial needs:" << endl;
    plant.printCurrentNeeds();

    // Test individual care actions
    plant.receiveWatering();
    plant.printCurrentNeeds();

    plant.receiveSunlight();
    plant.printCurrentNeeds();

    // Complete the session
    plant.completeCareSession();
    plant.printFullStatus();
    cout << endl;
}

void testDeadState()
{
    cout << "=== TEST 7: Dead State ===" << endl;
    TestPlant plant("Basil");

    // Kill the plant
    for (int i = 0; i < 4; i++)
    {
        // Incomplete care
        if (i % 2 == 0)
        {
            plant.receiveWatering();
        }
        plant.completeCareSession();

        if (plant.isDead())
        {
            cout << "Plant died at cycle " << (i + 1) << endl;
            break;
        }
    }

    plant.printFullStatus();
    cout << "Is dead: " << (plant.isDead() ? "Yes" : "No") << endl;
    cout << "Should remove from inventory: " << (plant.shouldRemoveFromInventory() ? "Yes" : "No") << endl;

    // Try to improve a dead plant
    cout << "Trying to improve dead plant..." << endl;
    plant.receiveWatering();
    plant.receiveSunlight();
    plant.completeCareSession();
    cout << endl;
}

void testCommMediator()
{
    cout << "=== COMMMEDIATOR TESTING ===" << endl
         << endl;

    ConcreteCommMediator *mediator = new ConcreteCommMediator();

    Manager *manager = new Manager("SHAVIR (Manager)", mediator);
    Worker *worker1 = new Worker("DIYA (Worker)", mediator);
    Worker *worker2 = new Worker("CHINMAYI (Worker)", mediator);

    Customer *customer1 = new Customer("AYUSH");
    Customer *customer2 = new Customer("FABIO");
    Customer *customer3 = new Customer("DIDI");

    mediator->addCustomer(customer1);
    mediator->addCustomer(customer2);
    mediator->addCustomer(customer3);

    cout << endl
         << "=== TEST 1: Basic Customer Queries ===" << endl;

    mediator->notifyStaff(customer1, "How often should I water my plants?", nullptr);
    cout << endl;

    mediator->notifyStaff(customer2, "I want to buy plants in bulk for my office", nullptr);
    cout << endl;

    mediator->notifyStaff(customer3, "How much sunlight do succulents need?", nullptr);
    cout << endl;

    cout << "=== TEST 2: Staff Availability ===" << endl;
    mediator->notifyStaff(customer1, "idk a plant ques", nullptr);
    cout << endl;

    cout << "=== TEST 3: Direct Staff Assignment ===" << endl;
    mediator->assignStaffToCustomer(worker2, customer1);
    cout << endl;

    cout << "=== TEST 4: Get Assigned Staff ===" << endl;
    StaffMember *assigned = mediator->getAssignedStaff(customer1);
    if (assigned)
    {
        cout << "Customer " << customer1->getName() << " is assigned to: " << assigned->getName() << endl;
    }
    cout << endl;

    // Cleanup
    delete mediator;
    delete manager;
    delete worker1;
    delete worker2;
    delete customer1;
    delete customer2;
    delete customer3;

    cout << "=== YAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAY ===" << endl;
}

void testInventory()
{
    cout << "=== Inventory Testing ===\n";

    Inventory *inv = new Inventory();

    // Add some plants
    GreenHouse *carnivorous = inv->getCarnivorousFactory();
    GreenHouse *tropical = inv->getTropicalFactory();
    GreenHouse *temperate = inv->getTemperateFactory();

    cout << "\n-- Adding plants --\n";
    inv->addLargePlant(carnivorous, nullptr);
    inv->addLargePlant(tropical, nullptr);
    inv->addMediumPlant(temperate, nullptr);
    inv->print();

    // Add duplicates and store pointers to manipulate later
    cout << "\n-- Adding duplicates --\n";
    Plant *healthmanip = inv->addLargePlant(carnivorous, nullptr);
    Plant *torem = inv->addLargePlant(carnivorous, nullptr);
    Plant *growthmanip = inv->addMediumPlant(temperate, nullptr);
    Plant *bird = inv->addMediumPlant(tropical, nullptr);
    Plant *uniquerem = inv->addSmallPlant(carnivorous, nullptr);
    inv->print();

    // Direct removals
    cout << "\n-- Direct removals --\n";
    inv->removePlant(torem);
    inv->print();
    inv->removePlant(uniquerem);
    inv->print();

    // Test getPlants by specific growth and health states
    cout << "\n-- Testing getPlants variants --\n";
    GrowthState *seedling = new Seed();
    GrowthState *mature = new Mature();
    HealthState *healthy = new Good();
    HealthState *dead = new Dead();

    cout << "Plants in seedling state: " << inv->getPlants(seedling).size() << endl;
    cout << "Plants in mature state: " << inv->getPlants(mature).size() << endl;
    cout << "Healthy plants: " << inv->getPlants(healthy).size() << endl;
    cout << "Dead plants: " << inv->getPlants(dead).size() << endl;

    //

    // Remove by state across entire tree
    cout << "\n-- Removing by GrowthState (Mature) --\n";
    vector<Plant *> removedMature = inv->removePlants(mature);
    cout << "Removed " << removedMature.size() << " mature plants.\n";
    inv->print();

    cout << "\n-- Removing by HealthState (Dead) --\n";
    vector<Plant *> removedDead = inv->removePlants(dead);
    cout << "Removed " << removedDead.size() << " dead plants.\n";
    inv->print();

    // Re-add a few plants for next phase
    cout << "\n-- Re-adding plants for further tests --\n";
    Plant *p1 = inv->addLargePlant(tropical, nullptr);
    Plant *p2 = inv->addSmallPlant(carnivorous, nullptr);
    Plant *p3 = inv->addMediumPlant(temperate, nullptr);
    if (p1)
        p1->setGrowthState(new Mature());
    if (p3)
        p3->setGrowthState(new Mature());
    if (p2)
        p2->setHealthState(new Dead());
    inv->print();

    // Test moveValidPlantsToStock
    //  cout << "\n-- Testing moveValidPlantsToStock --\n";
    //  Storage* stock = new Stock();
    //  inv->moveValidPlantsToStock(stock);
    //  cout << "Stock contents after move:\n";
    //  stock->printStorage();

    // Test cleanUpDeadPlants (should remove dead ones)
    cout << "\n-- Testing cleanUpDeadPlants --\n";
    inv->cleanUpDeadPlants();
    inv->print();

    // Remove by string key
    cout << "\n-- Testing removePlants(string key, GrowthState*) --\n";
    vector<Plant *> removedByKeyGrowth = inv->removePlants("TropicalPlant", mature);
    cout << "Removed " << removedByKeyGrowth.size() << " by key+growth.\n";
    inv->print();

    cout << "\n-- Testing removePlants(string key, HealthState*) --\n";
    vector<Plant *> removedByKeyHealth = inv->removePlants("CarnivorousPlant", healthy);
    cout << "Removed " << removedByKeyHealth.size() << " by key+health.\n";
    inv->print();

    // Test getNodeCount
    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    // Test iterator manually
    cout << "\n-- Testing iterator traversal --\n";
    InventoryIterator it(inv->getRoot());
    while (it.hasNext())
    {
        Plant *p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    // bugs might be here
    cout << "trying to find a bird of paradise (medium tropical) since thats not found by the iterator\n";
    vector<Plant *> birds = inv->getPlants(bird->getSpecies());
    for (Plant *p : birds)
    {
        cout << "   > " << p->getSpecies();

        if (p->getGrowthState() && p->getHealthState())
        {
            cout << " | Growth: " << p->getGrowthState()->getName()
                 << " | Health: " << p->getHealthState()->getName();
        }

        cout << " | Price: R" << p->getPrice() << endl;
    }

    cout << "now try to delete the bird of paradise, print out the tree again, and run the stats again\n";

    inv->print();

    it.reset();
    while (it.hasNext())
    {
        Plant *p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    inv->removePlant(bird);

    inv->print();

    it.reset();
    while (it.hasNext())
    {
        Plant *p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    cout << "\nlooks like coarse isnt working properly, print out the trace\n";

    it.reset();
    while (it.hasNextNode())
    {
        Plant *p = it.nextCoarse();
        cout << "iterated: " << p->getSpecies() << " node.\n";
    }

    delete seedling;
    delete mature;
    delete healthy;
    delete dead;
    // delete stock;
    delete inv;
}

void testStaffWithInventory()
{
    cout << "=== STAFF WITH INVENTORY TESTING ===" << endl;
    cout << endl;

    // Create system components
    Inventory *nurseryInventory = new Inventory();
    ConcreteCommMediator *commMediator = new ConcreteCommMediator();

    // ADD SOME PLANTS TO INVENTORY FIRST
    cout << "=== SETUP: Adding plants to inventory ===" << endl;
    GreenHouse *carnivorous = nurseryInventory->getCarnivorousFactory();
    GreenHouse *tropical = nurseryInventory->getTropicalFactory();
    GreenHouse *temperate = nurseryInventory->getTemperateFactory();
    GreenHouse *succulent = nurseryInventory->getSucculentFactory();

    nurseryInventory->addMediumPlant(carnivorous, nullptr);
    nurseryInventory->addSmallPlant(tropical, nullptr);
    nurseryInventory->addLargePlant(temperate, nullptr);
    nurseryInventory->addMediumPlant(carnivorous, nullptr); // Add another carnivorous
    nurseryInventory->addSmallPlant(succulent, nullptr);
    nurseryInventory->addLargePlant(tropical, nullptr);

    cout << "Initial inventory state:" << endl;
    nurseryInventory->print();
    cout << endl;

    // Create staff with inventory access
    Worker worker1("Alice", commMediator, nurseryInventory);
    Worker worker2("Charlie", commMediator, nurseryInventory);
    Manager manager1("Bob", commMediator, nurseryInventory);

    // Create test customers
    Customer customer1("John");
    Customer customer2("Sarah");
    Customer customer3("Mike");

    // Add customers to mediator
    commMediator->addCustomer(&customer1);
    commMediator->addCustomer(&customer2);
    commMediator->addCustomer(&customer3);

    cout << "=== TEST 1: Customer Queries with Real Inventory ===" << endl;

    // USE CORRECT PLANT NAMES THAT MATCH FACTORY OUTPUT
    commMediator->notifyStaff(&customer1, "Do you have any carnivorous plants in stock?", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer2, "I need care advice for my tropical plant", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer3, "I want to make a bulk purchase of temperate plants", nullptr);
    cout << endl;

    cout << "=== TEST 2: Purchase Requests with Inventory Checking ===" << endl;
    commMediator->notifyStaff(&customer1, "I want to buy 2 carnivorous plants", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer2, "Can I purchase 1 tropical plant?", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer3, "I need 10 temperate plants for my garden", nullptr);
    cout << endl;

    cout << "=== TEST 3: Direct Staff Inventory Methods ===" << endl;
    // Worker checking inventory directly
    cout << "Worker checking inventory:" << endl;
    worker1.checkInventory("CarnivorousPlant");
    worker2.checkInventory("TropicalPlant");
    worker1.checkInventory("SucculentPlant");
    cout << endl;

    // Manager checking overall status
    cout << "Manager checking inventory status:" << endl;
    manager1.checkInventoryStatus();
    cout << endl;

    cout << "=== TEST 4: Inventory After Operations ===" << endl;
    nurseryInventory->print();
    cout << endl;

    cout << "=== TEST 5: Staff Information and Availability ===" << endl;
    cout << "Worker 1 name: " << worker1.getName() << endl;
    cout << "Worker 2 name: " << worker2.getName() << endl;
    cout << "Manager name: " << manager1.getName() << endl;

    cout << "Setting worker 1 as unavailable..." << endl;
    worker1.setAvailability(false);
    cout << "Worker 1 availability: " << (worker1.getAvailability() ? "Available" : "Unavailable") << endl;
    cout << "Worker 2 availability: " << (worker2.getAvailability() ? "Available" : "Unavailable") << endl;
    cout << "Manager availability: " << (manager1.getAvailability() ? "Available" : "Unavailable") << endl;
    cout << endl;

    cout << "=== TEST 6: Advanced Inventory Queries ===" << endl;
    // Test plant availability checks
    cout << "Carnivorous plant availability (2 plants): "
         << (worker1.checkPlantAvailability("CarnivorousPlant", 2) ? "Available" : "Not Available") << endl;
    cout << "Carnivorous plant stock count: " << worker1.getPlantStockCount("CarnivorousPlant") << endl;
    cout << "Tropical plant stock count: " << worker1.getPlantStockCount("TropicalPlant") << endl;
    cout << "Temperate plant stock count: " << worker1.getPlantStockCount("TemperatePlant") << endl;
    cout << "Succulent plant stock count: " << worker1.getPlantStockCount("SucculentPlant") << endl;
    cout << "Total plants in inventory: " << manager1.getTotalPlantCount() << endl;
    cout << endl;

    cout << "=== TEST 7: Edge Cases ===" << endl;
    // Non-existent plant type
    commMediator->notifyStaff(&customer1, "Do you have blue moonflowers?", nullptr);
    cout << endl;

    // Large quantity request
    commMediator->notifyStaff(&customer2, "I want to buy 100 carnivorous plants", nullptr);
    cout << endl;

    // Test with plants that don't exist in inventory
    cout << "Checking availability for non-existent plant:" << endl;
    cout << "BlueMoonflower availability: " << (worker1.checkPlantAvailability("BlueMoonflower") ? "Available" : "Not Available") << endl;
    cout << "BlueMoonflower stock count: " << worker1.getPlantStockCount("BlueMoonflower") << endl;
    cout << endl;

    cout << "=== TEST 8: Mixed Queries ===" << endl;
    commMediator->notifyStaff(&customer1, "What's the price of succulent plants?", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer2, "How much sunlight do carnivorous plants need?", nullptr);
    cout << endl;

    commMediator->notifyStaff(&customer3, "I have a complaint about my recent purchase", nullptr);
    cout << endl;

    cout << "=== TEST 9: Final Inventory State ===" << endl;
    manager1.checkInventoryStatus();
    cout << endl;

    // Cleanup
    delete nurseryInventory;
    delete commMediator;

    cout << "=== STAFF WITH INVENTORY TESTING COMPLETE ===" << endl;
    cout << endl;
}

int decayPlants(Inventory *inv, Stock *stock, PlantCareHandler *handler)
{
    int cycles = 0;

    /*
    Patterns implemented

    Command
    Chain of Responsibility
    Health State
    Growth State
    Observer
    Abstract Factory
    Iterator
    */

    while (cycles < 10000)
    {
        cout << "iteration " << cycles << endl;
        if (cycles % 100 == 0)
        {
            // stock->cleanUpDeadPlants();
            // inv->cleanUpDeadPlants();
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

            inv->print();
        }

        inv->tick();

        cycles++;

        this_thread::sleep_for(chrono::milliseconds(0));
    }
    return 0;
}

void testAll() // cant check memory until inventory leaks are fixed
{
    // inventory
    Inventory *inv = new Inventory();
    Stock *stock = new Stock();

    // chain
    WaterHandler *waterHandler = new WaterHandler();
    SunHandler *sunlightHandler = new SunHandler();
    FertilizerHandler *fertilizerHandler = new FertilizerHandler();
    PruneHandler *pruneHandler = new PruneHandler();

    waterHandler->setNext(sunlightHandler);
    sunlightHandler->setNext(fertilizerHandler);
    fertilizerHandler->setNext(pruneHandler);

    // start async decayPlants
    future<int> result = async(launch::async, decayPlants, inv, stock, waterHandler);

    CommMediator *mediator = new ConcreteCommMediator();
    vector<StaffMember *> staff;

    for (int i = 0; i < 5; i++)
    {
        Worker *worker = new Worker("Worker" + to_string(i + 1), mediator, inv);
        staff.push_back(worker);
    }

    vector<Customer *> customers;

    for (int i = 0; i < 10; i++)
    {
        Customer *customer = new Customer("Customer" + to_string(i + 1), mediator);
        customers.push_back(customer);
    }

    Company *company = new Company("Company", mediator);

    customers.push_back(company);

    customers[6]->askQuestion("How often should I water my plants?");
    customers[2]->askQuestion("I want to buy plants in bulk for my office");
    customers[9]->askQuestion("How much sunlight do succulents need?");
    customers[0]->askQuestion("I want to buy 3 carnivorous plants");
    customers[4]->askQuestion("Can I purchase 1 tropical plant?");
    customers[5]->askQuestion("I need 10 temperate plants for my garden");
    customers[3]->askQuestion("Do you have any carnivorous plants in stock?");
    customers[1]->askQuestion("I need care advice for my tropical plant");
    customers[8]->askQuestion("I want to make a bulk purchase of temperate plants");
    customers[7]->askQuestion("What's the price of succulent plants?");

    // company ask question creates a seg fault
    // customers[11]->askQuestion("herro");

    result.wait();

    inv->print();

    delete inv;
    delete stock;

    delete waterHandler;
    delete sunlightHandler;
    delete fertilizerHandler;
    delete pruneHandler;

    delete mediator;

    for (StaffMember *s : staff)
    {
        delete s;
    }

    for (Customer *c : customers)
    {
        delete c;
    }
}


void testAbstractFactoryPattern()
{
    cout << "=== ABSTRACT FACTORY PATTERN TESTING ===" << endl;
    cout << endl;

    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    // Store in vector for memory management
    vector<Plant *> allPlants;
    vector<Plant *> clonedPlants;

    // Testing Temperate Factory
    cout << "--- Temperate Plants ---" << endl;
    Plant *temperateSmall = temperateFactory.createSmallPlant();
    Plant *temperateMedium = temperateFactory.createMediumPlant();
    Plant *temperateLarge = temperateFactory.createLargePlant();

    if (temperateSmall)
    {
        cout << "Small: " << temperateSmall->getDescription() << endl;
        allPlants.push_back(temperateSmall);
    }

    if (temperateMedium)
    {
        cout << "Medium: " << temperateMedium->getDescription() << endl;
        allPlants.push_back(temperateMedium);
    }

    if (temperateLarge)
    {
        cout << "Large: " << temperateLarge->getDescription() << endl;
        allPlants.push_back(temperateLarge);
    }
    cout << endl;

    // Testing Tropical Factory
    cout << "--- Tropical Plants ---" << endl;
    Plant *tropicalSmall = tropicalFactory.createSmallPlant();
    Plant *tropicalMedium = tropicalFactory.createMediumPlant();
    Plant *tropicalLarge = tropicalFactory.createLargePlant();

    if (tropicalSmall)
    {
        cout << "Small: " << tropicalSmall->getDescription() << endl;
        allPlants.push_back(tropicalSmall);
    }

    if (tropicalMedium)
    {
        cout << "Medium: " << tropicalMedium->getDescription() << endl;
        allPlants.push_back(tropicalMedium);
    }

    if (tropicalLarge)
    {
        cout << "Large: " << tropicalLarge->getDescription() << endl;
        allPlants.push_back(tropicalLarge);
    }
    cout << endl;

    // Test Carnivorous Factory
    cout << "--- Carnivorous Plants ---" << endl;
    Plant *carnivorousSmall = carnivorousFactory.createSmallPlant();
    Plant *carnivorousMedium = carnivorousFactory.createMediumPlant();
    Plant *carnivorousLarge = carnivorousFactory.createLargePlant();

    if (carnivorousSmall)
    {
        cout << "Small: " << carnivorousSmall->getDescription() << endl;
        allPlants.push_back(carnivorousSmall);
    }

    if (carnivorousMedium)
    {
        cout << "Medium: " << carnivorousMedium->getDescription() << endl;
        allPlants.push_back(carnivorousMedium);
    }

    if (carnivorousLarge)
    {
        cout << "Large: " << carnivorousLarge->getDescription() << endl;
        allPlants.push_back(carnivorousLarge);
    }
    cout << endl;

    // Test Succulent Factory
    cout << "--- Succulent Plants ---" << endl;
    Plant *succulentSmall = succulentFactory.createSmallPlant();
    Plant *succulentMedium = succulentFactory.createMediumPlant();
    Plant *succulentLarge = succulentFactory.createLargePlant();

    if (succulentSmall)
    {
        cout << "Small: " << succulentSmall->getDescription() << endl;
        allPlants.push_back(succulentSmall);
    }

    if (succulentMedium)
    {
        cout << "Medium: " << succulentMedium->getDescription() << endl;
        allPlants.push_back(succulentMedium);
    }

    if (succulentLarge)
    {
        cout << "Large: " << succulentLarge->getDescription() << endl;
        allPlants.push_back(succulentLarge);
    }
    cout << endl;

    // Test cloning functionality
    cout << "--- Testing Cloning ---" << endl;
    if (temperateSmall)
    {
        Plant *clonedDaisy = temperateSmall->clone();
        cout << "Original: " << temperateSmall->getDescription() << endl;
        cout << "Clone: " << clonedDaisy->getDescription() << endl;
        clonedPlants.push_back(clonedDaisy);
    }

    if (temperateMedium)
    {
        Plant *clonedLilac = temperateMedium->clone();
        cout << "Original: " << temperateMedium->getDescription() << endl;
        cout << "Clone: " << clonedLilac->getDescription() << endl;
        clonedPlants.push_back(clonedLilac);
    }

    if (temperateLarge)
    {
        Plant *clonedWhiteOak = temperateLarge->clone();
        cout << "Original: " << temperateLarge->getDescription() << endl;
        cout << "Clone: " << clonedWhiteOak->getDescription() << endl;
        clonedPlants.push_back(clonedWhiteOak);
    }

    cout << endl;

    // Cleanup
    cout << "--- Cleanup ---" << endl;
    for (Plant *plant : allPlants)
    {
        delete plant;
    }

    for (Plant *plant : clonedPlants)
    {
        delete plant;
    }
    
    cout << "Abstract Factory Pattern Test Completed!" << endl << endl;
}



void testStatePattern()
{
    cout << "=== STATE PATTERN TESTING (Growth & Health States) ===" << endl;
    cout << endl;

    // Test 1: Basic Plant Creation
    cout << "--- TEST 1: Basic Plant Creation ---" << endl;
    TestPlant plant("HenAndChicks");

    cout << "Species: " << plant.getSpecies() << endl;
    cout << "Description: " << plant.getDescription() << endl;
    cout << "Price: R" << plant.getPrice() << endl;
    cout << "Size: " << plant.getsize() << endl;
    cout << "Is Dead: " << (plant.isDead() ? "Yes" : "No") << endl;
    plant.printFullStatus();
    cout << endl;

    // Test 2: Growth Progression
    cout << "--- TEST 2: Growth Progression ---" << endl;
    TestPlant growthPlant("Sunflower");

    cout << "Initial state:" << endl;
    growthPlant.printGrowthStatus();
    growthPlant.printCurrentNeeds();

    // Simulate progression through growth stages
    for (int i = 0; i < 15; i++)
    {
        cout << "--- Care Cycle " << (i + 1) << " ---" << endl;
        growthPlant.printCurrentNeeds();

        // Provide all required care actions
        vector<string> requiredCare = growthPlant.getGrowthState()->getRequiredCare();
        for (const string &care : requiredCare)
        {
            if (care == "water") growthPlant.receiveWatering();
            else if (care == "sunlight") growthPlant.receiveSunlight();
            else if (care == "fertilizer") growthPlant.receiveFertilizing();
            else if (care == "prune") growthPlant.receivePruning();
        }

        growthPlant.completeCareSession();
        growthPlant.printGrowthStatus();

        if (growthPlant.shouldRemoveFromInventory())
        {
            if (growthPlant.isDead()) cout << "Plant died! Remove from inventory." << endl;
            else cout << "Plant sold! Remove from inventory." << endl;
            break;
        }

        if (growthPlant.isReadyForStock())
        {
            cout << "*** PLANT READY FOR STOCK! ***" << endl;
        }
        cout << endl;
    }

    // Test 3: Health Degradation & Recovery
    cout << "--- TEST 3: Health Degradation & Recovery ---" << endl;
    TestPlant healthPlant("Cactus");

    cout << "Degrading health..." << endl;
    for (int i = 0; i < 2; i++)
    {
        healthPlant.receiveWatering(); // Only water, no sunlight (incomplete care)
        healthPlant.completeCareSession();
    }
    healthPlant.printHealthStatus();

    cout << "Recovering health..." << endl;
    for (int i = 0; i < 2; i++)
    {
        healthPlant.receiveWatering();
        healthPlant.receiveSunlight();
        healthPlant.completeCareSession();
        healthPlant.printHealthStatus();
    }

    // Test 4: Dead State
    cout << "--- TEST 4: Dead State ---" << endl;
    TestPlant deadPlant("Basil");

    // Kill the plant with incomplete care
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0) deadPlant.receiveWatering();
        deadPlant.completeCareSession();
        if (deadPlant.isDead())
        {
            cout << "Plant died at cycle " << (i + 1) << endl;
            break;
        }
    }

    deadPlant.printFullStatus();
    cout << "Is dead: " << (deadPlant.isDead() ? "Yes" : "No") << endl;
    cout << "Should remove from inventory: " << (deadPlant.shouldRemoveFromInventory() ? "Yes" : "No") << endl;

    // Try to improve a dead plant (should not work)
    cout << "Trying to improve dead plant..." << endl;
    deadPlant.receiveWatering();
    deadPlant.receiveSunlight();
    deadPlant.completeCareSession();

    cout << "State Pattern Test Completed!" << endl << endl;
}

void testChainOfResponsibilityPattern()
{
    cout << "=== CHAIN OF RESPONSIBILITY PATTERN TESTING ===" << endl;
    cout << endl;

    CarnivorousPlantFactory carnivorousFactory;
    Plant *venusFlytrap = carnivorousFactory.createSmallPlant();

    // Create the chain of responsibility
    WaterHandler *waterHandler = new WaterHandler();
    SunHandler *sunHandler = new SunHandler();
    FertilizerHandler *fertilizerHandler = new FertilizerHandler();
    PruneHandler *pruneHandler = new PruneHandler();

    waterHandler->setNext(sunHandler);
    sunHandler->setNext(fertilizerHandler);
    fertilizerHandler->setNext(pruneHandler);

    venusFlytrap->setCareStrategy(waterHandler);

    cout << "--- Testing Plant Growth with Care Chain ---" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "--- Growth Cycle " << (i + 1) << " ---" << endl;
        venusFlytrap->printHealthStatus();
        venusFlytrap->printGrowthStatus();

        // Process care through the chain
        venusFlytrap->handleCareRequest();
        
        venusFlytrap->tick();
        venusFlytrap->completeCareSession();
        
        if (venusFlytrap->isDead()) break;
    }

    // Cleanup
    delete venusFlytrap;
    delete waterHandler;
    delete sunHandler;
    delete pruneHandler;
    delete fertilizerHandler;

    cout << "Chain of Responsibility Pattern Test Completed!" << endl << endl;
}

void testCommandPattern()
{
    cout << "=== COMMAND PATTERN TESTING ===" << endl;
    cout << endl;

    // Create a test plant
    TestPlant plant("TestPlant");
    
    cout << "--- Testing Individual Care Commands ---" << endl;
    
    // Create commands
    Water waterCmd(&plant);
    Sun sunCmd(&plant);
    Fertilizer fertilizerCmd(&plant);
    Prune pruneCmd(&plant);
    
    // Test initial state
    cout << "Initial resource levels:" << endl;
    cout << "Water: " << plant.getWaterLevel() << "%" << endl;
    cout << "Sunlight: " << plant.getSunlightLevel() << "%" << endl;
    cout << "Fertilizer: " << plant.getFertilizerLevel() << "%" << endl;
    cout << "Prune: " << plant.getPruneLevel() << "%" << endl;
    cout << endl;
    
    // Execute commands
    cout << "Executing water command..." << endl;
    waterCmd.execute();
    
    cout << "Executing sunlight command..." << endl;
    sunCmd.execute();
    
    cout << "Executing fertilizer command..." << endl;
    fertilizerCmd.execute();
    
    cout << "Executing prune command..." << endl;
    pruneCmd.execute();
    
    // Test final state
    cout << "Final resource levels:" << endl;
    cout << "Water: " << plant.getWaterLevel() << "%" << endl;
    cout << "Sunlight: " << plant.getSunlightLevel() << "%" << endl;
    cout << "Fertilizer: " << plant.getFertilizerLevel() << "%" << endl;
    cout << "Prune: " << plant.getPruneLevel() << "%" << endl;
    
    cout << "Command Pattern Test Completed!" << endl << endl;
}

void testObserverPattern()
{
    cout << "=== OBSERVER PATTERN TESTING ===" << endl;
    cout << endl;

    // Create a plant and observer
    TestPlant plant("ObservedPlant");
    ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(&plant);
    
    cout << "--- Testing Observer Notifications ---" << endl;
    
    // Degrade plant health to trigger observer
    cout << "Degrading plant health to trigger observer..." << endl;
    for (int i = 0; i < 5; i++)
    {
        plant.tick(); // This degrades resources
    }
    
    // Manually set to needs care to trigger observer
    plant.setHealthState(new NeedsCare());
    
    
    cout << "Observer Pattern Test Completed!" << endl << endl;
}

void testMediatorPattern()
{
    cout << "=== MEDIATOR PATTERN TESTING ===" << endl;
    cout << endl;

    ConcreteCommMediator *mediator = new ConcreteCommMediator();

    Manager *manager = new Manager("SHAVIR (Manager)", mediator);
    Worker *worker1 = new Worker("DIYA (Worker)", mediator);
    Worker *worker2 = new Worker("CHINMAYI (Worker)", mediator);

    Customer *customer1 = new Customer("AYUSH");
    Customer *customer2 = new Customer("FABIO");
    Customer *customer3 = new Customer("DIDI");//didi ordered some roses :)

    mediator->addCustomer(customer1);
    mediator->addCustomer(customer2);
    mediator->addCustomer(customer3);

    cout << "--- TEST 1: Basic Customer Queries ---" << endl;
    mediator->notifyStaff(customer1, "How often should I water my plants?", nullptr);
    cout << endl;

    mediator->notifyStaff(customer2, "I want to buy plants in bulk for my office", nullptr);
    cout << endl;

    mediator->notifyStaff(customer3, "How much sunlight do succulents need?", nullptr);
    cout << endl;

    cout << "--- TEST 2: Staff Availability ---" << endl;
    mediator->notifyStaff(customer1, "idk a plant ques", nullptr);
    cout << endl;

    cout << "--- TEST 3: Direct Staff Assignment ---" << endl;
    mediator->assignStaffToCustomer(worker2, customer1);
    cout << endl;

    cout << "--- TEST 4: Get Assigned Staff ---" << endl;
    StaffMember *assigned = mediator->getAssignedStaff(customer1);
    if (assigned)
    {
        cout << "Customer " << customer1->getName() << " is assigned to: " << assigned->getName() << endl;
    }
    cout << endl;

    // Cleanup
    delete mediator;
    delete manager;
    delete worker1;
    delete worker2;
    delete customer1;
    delete customer2;
    delete customer3;

    cout << "Mediator Pattern Test Completed!" << endl << endl;
}

void testCompositePattern()
{
    cout << "=== COMPOSITE PATTERN TESTING (Customer Hierarchy) ===" << endl;
    cout << endl;

    // Create mediator for communication
    ConcreteCommMediator *mediator = new ConcreteCommMediator();

    cout << "--- Creating Individual Customers (Leaf Nodes) ---" << endl;
    
    // Create individual customers (leaves)
    Customer *individual1 = new Customer("DIDI", mediator);
    Customer *individual2 = new Customer("AYUSH", mediator);
    Customer *individual3 = new Customer("JAITIN", mediator);
    Customer *individual4 = new Customer("SHAVIR", mediator);
    
    cout << "Individual customers created:" << endl;
    cout << " - " << individual1->getName() << endl;
    cout << " - " << individual2->getName() << endl;
    cout << " - " << individual3->getName() << endl;
    cout << " - " << individual4->getName() << endl;
    cout << endl;

    cout << "--- Creating Company Composites ---" << endl;
    
    // Create companies (composite nodes)
    Company *techCompany = new Company("Tech Corp", mediator);
    Company *designStudio = new Company("Design Studio", mediator);
    Company *holdingCompany = new Company("Global Holdings", mediator);
    
    cout << "Companies created:" << endl;
    cout << " - " << techCompany->getName() << endl;
    cout << " - " << designStudio->getName() << endl;
    cout << " - " << holdingCompany->getName() << endl;
    cout << endl;

    cout << "--- Building Customer Hierarchy ---" << endl;
    
    // Add individual customers to companies
    techCompany->addCustomer(individual1);
    techCompany->addCustomer(individual2);
    designStudio->addCustomer(individual3);
    
    cout << "Customers added to companies:" << endl;
    cout << " - " << individual1->getName() << " added to " << techCompany->getName() << endl;
    cout << " - " << individual2->getName() << " added to " << techCompany->getName() << endl;
    cout << " - " << individual3->getName() << " added to " << designStudio->getName() << endl;
    cout << endl;

    cout << "--- Testing Nested Composite Structure ---" << endl;
    
    // Create a hierarchical structure: holding company contains other companies
    holdingCompany->addCustomer(techCompany);
    holdingCompany->addCustomer(designStudio);
    holdingCompany->addCustomer(individual4);  // Also add an individual directly
    
    cout << "Nested hierarchy created:" << endl;
    cout << " - " << holdingCompany->getName() << " contains:" << endl;
    cout << "   * " << techCompany->getName() << " (with 2 customers)" << endl;
    cout << "   * " << designStudio->getName() << " (with 1 customer)" << endl;
    cout << "   * " << individual4->getName() << " (direct customer)" << endl;
    cout << endl;

    cout << "--- Testing Composite Operations ---" << endl;
    
    // Test discount calculation across the entire hierarchy
    cout << "Testing discount aggregation:" << endl;
    double techDiscount = techCompany->getDiscount();
    double designDiscount = designStudio->getDiscount();
    double holdingDiscount = holdingCompany->getDiscount();
    
    cout << "Tech Company total discount: " << techDiscount << endl;
    cout << "Design Studio total discount: " << designDiscount << endl;
    cout << "Holding Company total discount: " << holdingDiscount << endl;
    cout << "Note: Discount values represent aggregated customer discounts" << endl;
    cout << endl;

    cout << "--- Testing Customer Removal ---" << endl;
    
    // Remove a customer from a company
    cout << "Before removal - Tech Company discount: " << techCompany->getDiscount() << endl;
    techCompany->removeCustomer(individual1);
    cout << "Removed " << individual1->getName() << " from " << techCompany->getName() << endl;
    cout << "After removal - Tech Company discount: " << techCompany->getDiscount() << endl;
    cout << endl;

    cout << "--- Testing Communication Through Hierarchy ---" << endl;
    
    // Test that all customers in the hierarchy can communicate
    cout << "Testing customer inquiries through mediator:" << endl;
    individual2->askQuestion("Do you offer corporate plant maintenance?", nullptr);
    cout << endl;
    
    individual3->requestPurchase("Office Plants", 15);
    cout << endl;
    
    individual4->askQuestion("What are your bulk purchase options?", nullptr);
    cout << endl;

    cout << "--- Testing Purchase History Tracking ---" << endl;
    
    // Simulate purchases across the hierarchy
    individual2->requestPurchase("Snake Plant", 5);
    individual3->requestPurchase("Peace Lily", 8);
    individual4->requestPurchase("Rubber Plant", 12);
    
    cout << "Purchase histories across hierarchy:" << endl;
    
    vector<string> history2 = individual2->getPurchaseHistory();
    cout << individual2->getName() << " (" << techCompany->getName() << "): ";
    for (const string& purchase : history2) {
        cout << purchase << "; ";
    }
    cout << endl;
    
    vector<string> history3 = individual3->getPurchaseHistory();
    cout << individual3->getName() << " (" << designStudio->getName() << "): ";
    for (const string& purchase : history3) {
        cout << purchase << "; ";
    }
    cout << endl;
    
    vector<string> history4 = individual4->getPurchaseHistory();
    cout << individual4->getName() << " (" << holdingCompany->getName() << " direct): ";
    for (const string& purchase : history4) 
    {
        cout << purchase << "; ";
    }
    cout << endl << endl;

    cout << "--- Testing Uniform Treatment (Composite Pattern Benefit) ---" << endl;
    
    // Demonstrate that we can treat individual customers and companies uniformly
    vector<Customer*> allEntities = {individual2, individual3, techCompany, holdingCompany};
    
    cout << "Treating all customer entities uniformly:" << endl;
    for (Customer* entity : allEntities) 
    {
        cout << " - " << entity->getName() << " can communicate and has discount: " << entity->getDiscount() << endl;
    }
    cout << endl;

    // Cleanup
    cout << "--- Cleanup ---" << endl;
    
    delete individual1;  // Was removed from techCompany
    delete holdingCompany;   
    delete mediator;
    
    cout << "Composite Pattern Test Completed Successfully!" << endl;
    cout << "Demonstrated: Leaf nodes (individuals), Composite nodes (companies), and nested hierarchies" << endl;
    cout << "All customer types treated uniformly through Customer interface" << endl << endl;
}

void testIteratorPattern()
{
    cout << "=== ITERATOR PATTERN TESTING (Inventory System) ===" << endl;
    cout << endl;

    Inventory *inv = new Inventory();

    // Add some plants
    GreenHouse *carnivorous = inv->getCarnivorousFactory();
    GreenHouse *tropical = inv->getTropicalFactory();
    GreenHouse *temperate = inv->getTemperateFactory();

    cout << "--- Adding Plants to Inventory ---" << endl;
    inv->addLargePlant(carnivorous,nullptr);
    inv->addLargePlant(tropical,nullptr);
    inv->addMediumPlant(temperate,nullptr);
    inv->print();

    cout << "--- Adding Duplicates ---" << endl;
    Plant *healthmanip = inv->addLargePlant(carnivorous,nullptr);
    Plant *torem = inv->addLargePlant(carnivorous,nullptr);
    Plant *growthmanip = inv->addMediumPlant(temperate,nullptr);
    Plant *bird = inv->addMediumPlant(tropical,nullptr);
    Plant *uniquerem = inv->addSmallPlant(carnivorous,nullptr);
    inv->print();

    cout << "--- Testing Direct Removals ---" << endl;
    inv->removePlant(torem);
    inv->print();
    inv->removePlant(uniquerem);
    inv->print();

    // Test state-based operations
    cout << "--- Testing State-Based Operations ---" << endl;
    GrowthState *seedling = new Seed();
    GrowthState *mature = new Mature();
    HealthState *healthy = new Good();
    HealthState *dead = new Dead();

    cout << "Plants in seedling state: " << inv->getPlants(seedling).size() << endl;
    cout << "Plants in mature state: " << inv->getPlants(mature).size() << endl;
    cout << "Healthy plants: " << inv->getPlants(healthy).size() << endl;
    cout << "Dead plants: " << inv->getPlants(dead).size() << endl;

    cout << "--- Testing Iterator Traversal ---" << endl;
    InventoryIterator it(inv->getRoot());
    while (it.hasNext())
    {
        Plant *p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")" << endl;
    }

    cout << "--- Testing Inventory Statistics ---" << endl;
    cout << "Node count: " << inv->getNodeCount() << " types of plants in inventory" << endl;
    cout << "Plant count: " << inv->getPlantCount() << " plants in inventory" << endl;

    // Cleanup - JUST delete the inventory, it will handle plant cleanup
    cout << "--- Cleanup ---" << endl;
    delete seedling;
    delete mature;
    delete healthy;
    delete dead;
    delete inv;  // Inventory destructor should handle plant deletion

    cout << "Iterator Pattern Test Completed!" << endl << endl;
}

void testIntegratedSystem()
{
    cout << "====================================================================" << endl;
    cout << "=== INTEGRATED SYSTEM TEST - ALL PATTERNS WORKING TOGETHER ===" << endl;
    cout << "====================================================================" << endl;
    cout << endl;

    // PHASE 1: SYSTEM SETUP
    cout << "--- PHASE 1: SYSTEM INITIALIZATION ---" << endl;
    TemperatePlantFactory temperateFactory;
    ConcreteCommMediator *mediator = new ConcreteCommMediator();
    Inventory *inventory = new Inventory();
    
    Manager *manager = new Manager("Store Manager", mediator);
    Worker *worker = new Worker("Plant Specialist", mediator);
    cout << "System initialized with factories, inventory, staff, and mediator" << endl << endl;

    // PHASE 2: PLANT CREATION & ENHANCEMENT - FIXED
    cout << "--- PHASE 2: PLANT CREATION & ENHANCEMENT ---" << endl;
    // Option 1: Use decorator with direct plant creation (recommended)
    {
        auto premiumPlant = std::make_unique<FertilizerDecorator>(
            std::make_unique<PotDecorator>(
                std::make_unique<Lilac>(),  // Create plant directly, not from factory
                "Ceramic"),
            "Organic");
        cout << "Created: " << premiumPlant->getDescription() << endl;
    } // premiumPlant automatically destroyed here
    
    // Option 2: If you want to use factory, don't mix raw and smart pointers
    Plant *simplePlant = temperateFactory.createMediumPlant();
    cout << "Also created: " << simplePlant->getDescription() << endl;
    cout << endl;

    // PHASE 3: INVENTORY MANAGEMENT
    cout << "--- PHASE 3: INVENTORY MANAGEMENT ---" << endl;
    inventory->addMediumPlant(inventory->getTemperateFactory(),nullptr);
    cout << "Inventory now contains " << inventory->getPlantCount() << " plants" << endl << endl;

    // PHASE 4: AUTOMATED PLANT CARE SYSTEM
    cout << "--- PHASE 4: AUTOMATED PLANT CARE SYSTEM ---" << endl;
    Plant *carePlant = temperateFactory.createSmallPlant();
    
    // Set up Chain of Responsibility
    WaterHandler *waterHandler = new WaterHandler();
    SunHandler *sunHandler = new SunHandler();
    waterHandler->setNext(sunHandler);
    carePlant->setCareStrategy(waterHandler);
    
    // Attach Observer - FIXED: Don't delete observer, plant owns it
    ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(carePlant);
    
    // Simulate care cycle
    carePlant->tick();
    carePlant->tick();
    carePlant->handleCareRequest();
    cout << "Automated care system processed plant needs" << endl << endl;

    // PHASE 5: CUSTOMER INTERACTION
    cout << "--- PHASE 5: CUSTOMER INTERACTION SYSTEM ---" << endl;
    Customer *customer = new Customer("Retail Customer", mediator);
    
    customer->askQuestion("Do you have mature plants available?", carePlant);
    cout << "Customer communication handled through mediator" << endl << endl;

    // PHASE 6: COMMAND SYSTEM
    cout << "--- PHASE 6: MANUAL COMMAND SYSTEM ---" << endl;
    Water waterCmd(carePlant);
    waterCmd.execute();
    cout << " Manual care commands executed successfully" << endl << endl;

    // PHASE 7: SYSTEM CLEANUP - FIXED
    cout << "--- PHASE 7: SYSTEM CLEANUP ---" << endl;
    
    // Delete care plant (observer is owned by plant, so don't delete separately)
    delete carePlant;
    
    // Delete the simple plant we created
    delete simplePlant;
    
    // Delete handlers
    delete waterHandler;
    delete sunHandler;
    
    // Delete customer
    delete customer;
    
    // Delete inventory (it manages its own plants)
    delete inventory;
    
    // Delete mediator and staff
    delete mediator;
    delete manager;
    delete worker;
    
    cout << " All resources properly cleaned up" << endl << endl;

    cout << "================================================================" << endl;
    cout << "=== ALL DESIGN PATTERNS SUCCESSFULLY INTEGRATED AND WORKING ===" << endl;
    cout << "================================================================" << endl;
    cout << endl;
}

