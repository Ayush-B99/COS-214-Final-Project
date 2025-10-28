#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

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
//for inventory functionality
#include "../include/Storage.h"
#include "../include/Inventory.h"
#include "../include/Stock.h"
#include "../include/PlantNode.h"
#include "../include/Iterator.h"
#include "../include/InventoryIterator.h"



void testAbstractFactory() {
    cout << "=== ABSTRACT FACTORY PATTERN TESTING: ===" << endl;
    cout << endl;

    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    // sotred in vector to try and make mem management easier
    vector<Plant*> allPlants;

    // Testing Factories
    cout << "--- Temperate Plants ---" << endl;
    Plant* temperateSmall = temperateFactory.createSmallPlant();
    Plant* temperateMedium = temperateFactory.createMediumPlant();
    Plant* temperateLarge = temperateFactory.createLargePlant();

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
    Plant* tropicalSmall = tropicalFactory.createSmallPlant();
    Plant* tropicalMedium = tropicalFactory.createMediumPlant();
    Plant* tropicalLarge = tropicalFactory.createLargePlant();

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
    Plant* carnivorousSmall = carnivorousFactory.createSmallPlant();
    Plant* carnivorousMedium = carnivorousFactory.createMediumPlant();
    Plant* carnivorousLarge = carnivorousFactory.createLargePlant();

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
    Plant* succulentSmall = succulentFactory.createSmallPlant();
    Plant* succulentMedium = succulentFactory.createMediumPlant();
    Plant* succulentLarge = succulentFactory.createLargePlant();

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
    vector<Plant*> clonedPlants;
    
    if (temperateSmall) 
    {
        Plant* clonedDaisy = temperateSmall->clone();
        cout << "Original: " << temperateSmall->getDescription() << endl;
        cout << "Clone: " << clonedDaisy->getDescription() << endl;
        clonedPlants.push_back(clonedDaisy);
    }

    if (temperateMedium) 
    {
        Plant* clonedLilac = temperateMedium->clone();
        cout << "Original: " << temperateMedium->getDescription() << endl;
        cout << "Clone: " << clonedLilac->getDescription() << endl;
        clonedPlants.push_back(clonedLilac);
    }

    if (temperateLarge) 
    {
        Plant* clonedWhiteOak = temperateLarge->clone();
        cout << "Original: " << temperateLarge->getDescription() << endl;
        cout << "Clone: " << clonedWhiteOak->getDescription() << endl;
        clonedPlants.push_back(clonedWhiteOak);
    }

    cout << endl;

    // Cleanup: Delete all plants
    for (Plant* plant : allPlants) 
    {
        delete plant;
    }
    
    for (Plant* plant : clonedPlants) 
    {
        delete plant;
    }
}

void testDecoratorPattern() {
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
        "Slow-Release"
    );
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
        "Organic"
    );
    cout << "Nested (smart pointers): " << nested->getDescription() << endl;

    // Method 2: Step-by-step construction
    auto step1 = std::make_unique<WhiteOak>();
    auto step2 = std::make_unique<PotDecorator>(std::move(step1), "Clay");  
    auto step3 = std::make_unique<FertilizerDecorator>(std::move(step2), "Organic");
    cout << "Step-by-step: " << step3->getDescription() << endl;

    // No manual deletion needed - smart pointers handle cleanup automatically!
    cout << endl;
}

void testPatternsTogether() {
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
            "Ceramic"
        ), 
        "Slow-Release"
    );

    auto premiumTropicalPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(tropicalFactory.createSmallPlant()), 
            "Decorative"
        ), 
        "Liquid"
    );

    auto premiumCarnivorousPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(carnivorousFactory.createLargePlant()), 
            "Clay"
        ), 
        "Organic"
    );

    auto premiumSucculentPackage = std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(succulentFactory.createLargePlant()), 
            "Decorative"
        ), 
        "Slow-Release"
    );

    if (premiumTemperatePackage) {
        cout << "Premium Temperate Package: " << premiumTemperatePackage->getDescription() << " - Price: R" << premiumTemperatePackage->getPrice() << endl;
    }

    if (premiumTropicalPackage) {
        cout << "Premium Tropical Package: " << premiumTropicalPackage->getDescription() << " - Price: R" << premiumTropicalPackage->getPrice() << endl;
    }
    
    if (premiumCarnivorousPackage) {
        cout << "Premium Carnivorous Package: " << premiumCarnivorousPackage->getDescription() << " - Price: R" << premiumCarnivorousPackage->getPrice() << endl;
    }

    if (premiumSucculentPackage) {
        cout << "Premium Succulent Package: " << premiumSucculentPackage->getDescription() << " - Price: R" << premiumSucculentPackage->getPrice() << endl;
    }

    cout << endl;

    cout << "--- Creating Multiple Decorated Plants from Factory ---" << endl;
    
    // Create multiple plants from factory and decorate differently
    vector<std::unique_ptr<Plant>> decoratedPlants;
    
    // Different decoration combos
    decoratedPlants.push_back(std::make_unique<PotDecorator>(
        std::unique_ptr<Plant>(temperateFactory.createSmallPlant()), "Plastic"
    ));
    
    decoratedPlants.push_back(std::make_unique<FertilizerDecorator>(
        std::unique_ptr<Plant>(temperateFactory.createSmallPlant()), "Organic"
    ));
    
    decoratedPlants.push_back(std::make_unique<FertilizerDecorator>(
        std::make_unique<PotDecorator>(
            std::unique_ptr<Plant>(temperateFactory.createLargePlant()), 
            "Decorative"
        ), 
        "Slow-Release"
    ));

    for (size_t i = 0; i < decoratedPlants.size(); i++) {
        cout << "Plant " << (i + 1) << ": " << decoratedPlants[i]->getDescription() << " - Price: R" << decoratedPlants[i]->getPrice() << endl;
    }
    cout << endl;

    // No manual deletion needed - smart pointers handle cleanup automatically!
}

//made a concrete plant class without abstract factory for testing in isolation
class TestPlant : public Plant {

    public: 
    TestPlant(string species) : Plant(species) {
        setGrowthRequirements(2,3,4); //seed: 2 cycles, sprout: 3 cycles, mature: 4 cycles
        setSize("small");
        setPrice(69.99);
        setDescription("like a little succulant idk");
    
    }

    Plant* clone() override {
        return new TestPlant(*this);
    }
};

// Mock observer for testing notifications
class TestObserver : public GrowthObserver {
public:
    void onGrowthChange(Plant* plant) override {
        cout << "OBSERVER: " << plant->getSpecies() << " growth state changed!" << endl;
    }
};

void testBasicPlantCreation() {
    cout << "=== TEST 1: Basic Plant Creation ===" << endl;
    TestPlant plant("HenAndChicks");
    
    cout << "Species: " << plant.getSpecies() << endl;
    cout << "Description: " << plant.getDescription() << endl;
    cout << "Price: $" << plant.getPrice() << endl;
    cout << "Size: " << plant.getsize() << endl;
    cout << "Is Dead: " << (plant.isDead() ? "Yes" : "No") << endl;
    //cout << "Is Mature: " << (plant.isMature() ? "Yes" : "No") << endl;
    
    plant.printFullStatus();
    cout << endl;
}

void testGrowthProgression() {
    cout << "=== TEST 2: Growth Progression ===" << endl;
    TestPlant plant("Sunflower");
    // TestObserver observer;
    // plant.attach(&observer);

    cout << "Initial state:" << endl;
    plant.printGrowthStatus();

    for (int i = 0; i < 10; i++) {
        cout << "--- Care cycle " << (i+1) << " ---\n";
    

        plant.receiveWatering();
        plant.receiveSunlight();

        if (i >= 2) {
            plant.receiveFertilizing();
        }
        if (i >= 5) {
            plant.receivePruning();

        }

        plant.completeCareSession();
        plant.printGrowthStatus();

        if (plant.shouldRemoveFromInventory()) {
            cout << "big sad :( plant be dead, remove from inventory!" << endl;
            break;
        }

    }
    // plant.detach(&observer);
    cout << endl;

}

void testHealthDegradation() {
    cout << "=== TEST 3: Health Degradation ===" << endl;
    TestPlant plant("Cactus");

    cout << "Initial health:" << endl;
    plant.printHealthStatus();

    for (int i = 0; i < 3; i++) {
        cout << "--- Care Cycle " << (i + 1) << " (INCOMPLETE CARE) ---" << endl;
    

     // Only do partial care (miss some requirements)
        if (i % 2 == 0) {
            plant.receiveWatering();
        }
        // Don't provide sunlight (incomplete care)
        
        plant.completeCareSession();
        plant.printHealthStatus();

         if (plant.isDead()) {
            cout << "Plant has died!" << endl;
            break;
        }
    }
    cout << endl;
}

void testHealthRecovery() {
    cout << "=== TEST 4: Health Recovery ===" << endl;
    TestPlant plant("Fern");

    cout << "Degrading health..." << endl;
    for (int i = 0; i < 2; i++) {
        plant.receiveWatering(); // Only water, no sunlight
        plant.completeCareSession();
    }
    plant.printHealthStatus();

    // Now provide complete care to recover
    cout << "Recovering health..." << endl;
    for (int i = 0; i < 2; i++) {
        plant.receiveWatering();
        plant.receiveSunlight();
        plant.completeCareSession();
        plant.printHealthStatus();
    }
    cout << endl;

}

void testIndividualCareActions() {
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

void testSoldState() {
    cout << "=== TEST 6: Sold State ===" << endl;
    TestPlant plant("Tulip");
    
    // Fast-forward to mature state
    for (int i = 0; i < 9; i++) {
        plant.receiveWatering();
        plant.receiveSunlight();
        plant.receiveFertilizing();
        plant.receivePruning();
        plant.completeCareSession();
        
        if (plant.shouldRemoveFromInventory()) {
            break;
        }
    }

    plant.printFullStatus();
    cout << "Should remove from inventory: " << (plant.shouldRemoveFromInventory() ? "Yes" : "No") << endl;
    cout << "Is ready for stock: " << (plant.isReadyForStock() ? "Yes" : "No") << endl;
    cout << endl;

}

void testDeadState() {
    cout << "=== TEST 7: Dead State ===" << endl;
    TestPlant plant("Basil");
    
    // Kill the plant
    for (int i = 0; i < 4; i++) {
        // Incomplete care
        if (i % 2 == 0) {
            plant.receiveWatering();
        }
        plant.completeCareSession();
        
        if (plant.isDead()) {
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

void testInventory();


int main()
{
    try {
        cout << "PLANT STORE PATTERN TESTING" << endl;
        cout << "============================" << endl;
        cout << endl;

        // testAbstractFactory();
        // testDecoratorPattern();
        // testPatternsTogether();

        // testBasicPlantCreation();
        // testGrowthProgression();
        // testHealthDegradation();
        // testHealthRecovery();
        // testIndividualCareActions();
        // testSoldState();
        // testDeadState();
        testInventory();


        cout << "All tests completed successfully!" << endl;
        return 0;
    } catch (const char* msg) {
        cerr << "Exception caught: " << msg << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown exception caught!" << endl;
        return 1;
    }
}


void testInventory(){
cout << "=== Inventory Testing ===\n";

    Inventory* inv = new Inventory();

    // Add some plants
    GreenHouse* carnivorous = inv->getCarnivorousFactory();
    GreenHouse* tropical = inv->getTropicalFactory();
    GreenHouse* temperate = inv->getTemperateFactory();

    cout << "\n-- Adding plants --\n";
    inv->addLargePlant(carnivorous);
    inv->addLargePlant(tropical);
    inv->addMediumPlant(temperate);
    inv->print();

    // Add duplicates and store pointers to manipulate later
    cout << "\n-- Adding duplicates --\n";
    Plant* healthmanip = inv->addLargePlant(carnivorous);
    Plant* torem = inv->addLargePlant(carnivorous);
    Plant* growthmanip = inv->addMediumPlant(temperate);
    Plant* bird = inv->addMediumPlant(tropical);
    Plant* uniquerem = inv->addSmallPlant(carnivorous);
    inv->print();

    // Direct removals
    cout << "\n-- Direct removals --\n";
    inv->removePlant(torem);
    inv->print();
    inv->removePlant(uniquerem);
    inv->print();

    // Test getPlants by specific growth and health states
    cout << "\n-- Testing getPlants variants --\n";
    GrowthState* seedling = new Seed();
    GrowthState* mature = new Mature();
    HealthState* healthy = new Good();
    HealthState* dead = new Dead();

    cout << "Plants in seedling state: " << inv->getPlants(seedling).size() << endl;
    cout << "Plants in mature state: " << inv->getPlants(mature).size() << endl;
    cout << "Healthy plants: " << inv->getPlants(healthy).size() << endl;
    cout << "Dead plants: " << inv->getPlants(dead).size() << endl;

    // Manipulate some plant states manually
    cout << "\n-- Manually manipulating states --\n";
    if (healthmanip) healthmanip->setHealthState(new Dead());
    cout << "setting states\n";
    if (growthmanip) growthmanip->setGrowthState(new Mature());
    inv->print();

    // Remove by state across entire tree
    cout << "\n-- Removing by GrowthState (Mature) --\n";
    vector<Plant*> removedMature = inv->removePlants(mature);
    cout << "Removed " << removedMature.size() << " mature plants.\n";
    inv->print();

    cout << "\n-- Removing by HealthState (Dead) --\n";
    vector<Plant*> removedDead = inv->removePlants(dead);
    cout << "Removed " << removedDead.size() << " dead plants.\n";
    inv->print();

    // Re-add a few plants for next phase
    cout << "\n-- Re-adding plants for further tests --\n";
    Plant* p1 = inv->addLargePlant(tropical);
    Plant* p2 = inv->addSmallPlant(carnivorous);
    Plant* p3 = inv->addMediumPlant(temperate);
    if (p1) p1->setGrowthState(new Mature());
    if (p3) p3->setGrowthState(new Mature());
    if (p2) p2->setHealthState(new Dead());
    inv->print();

    // Test moveValidPlantsToStock
    // cout << "\n-- Testing moveValidPlantsToStock --\n";
    // Storage* stock = new Stock();
    // inv->moveValidPlantsToStock(stock);
    // cout << "Stock contents after move:\n";
    //stock->printStorage();

    // Test cleanUpDeadPlants (should remove dead ones)
    cout << "\n-- Testing cleanUpDeadPlants --\n";
    inv->cleanUpDeadPlants();
    inv->print();

    // Remove by string key
    cout << "\n-- Testing removePlants(string key, GrowthState*) --\n";
    vector<Plant*> removedByKeyGrowth = inv->removePlants("TropicalPlant", mature);
    cout << "Removed " << removedByKeyGrowth.size() << " by key+growth.\n";
    inv->print();

    cout << "\n-- Testing removePlants(string key, HealthState*) --\n";
    vector<Plant*> removedByKeyHealth = inv->removePlants("CarnivorousPlant", healthy);
    cout << "Removed " << removedByKeyHealth.size() << " by key+health.\n";
    inv->print();

    // Test getNodeCount
    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    // Test iterator manually
    cout << "\n-- Testing iterator traversal --\n";
    InventoryIterator it(inv->getRoot());
    while (it.hasNext()) {
        Plant* p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    //bugs might be here
    cout << "trying to find a bird of paradise (medium tropical) since thats not found by the iterator\n";
    vector<Plant*> birds = inv->getPlants(bird->getSpecies());
    for (Plant* p : birds){
        cout << "   > " << p->getSpecies();

        if (p->getGrowthState() && p->getHealthState()) {
            cout << " | Growth: " << p->getGrowthState()->getName()
                 << " | Health: " << p->getHealthState()->getName();
        }

        cout << " | Price: R" << p->getPrice() << endl;
    }

    cout << "now try to delete the bird of paradise, print out the tree again, and run the stats again\n";

    inv->print();
    
    it.reset();
    while (it.hasNext()) {
        Plant* p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    inv->removePlant(bird);

    inv->print();

    it.reset();
    while (it.hasNext()) {
        Plant* p = it.next();
        if (p)
            cout << "Iterated: " << p->getSpecies() << " (" << p->getGrowthState()->getName() << ")\n";
    }

    cout << "\n-- Node count: " << inv->getNodeCount() << " types of plants in inventory\n";
    cout << "\n-- Plant count: " << inv->getPlantCount() << " plants in inventory\n";

    cout << "\nlooks like coarse isnt working properly, print out the trace\n";
    
    it.reset();
    while(it.hasNextNode()){
        Plant* p = it.nextCoarse();
        cout << "iterated: " << p->getSpecies() << " node.\n";
    }

    delete seedling;
    delete mature;
    delete healthy;
    delete dead;
    //delete stock;
    delete inv;
}

/*
// oboselete testing code, the new ones work better and have no memory leaks
void testAbstractFactory() {
    cout << "=== ABSTRACT FACTORY PATTERN TESTING: ===" << endl;
    cout << endl;

    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    // Testing Factories
    cout << "--- Temperate Plants ---" << endl;
    Plant* temperateSmall = temperateFactory.createSmallPlant();
    Plant* temperateMedium = temperateFactory.createMediumPlant();
    Plant* temperateLarge = temperateFactory.createLargePlant();

    cout << "Small: " << temperateSmall->getDescription() << endl;
    cout << "Medium: " << temperateMedium->getDescription() << endl;
    cout << "Large: " << temperateLarge->getDescription() << endl;
    cout << endl;

    cout << "--- Tropical Plants ---" << endl;
    Plant* tropicalSmall = tropicalFactory.createSmallPlant();
    Plant* tropicalMedium = tropicalFactory.createMediumPlant();
    Plant* tropicalLarge = tropicalFactory.createLargePlant();

    if (tropicalSmall) 
        cout << "Small: " << tropicalSmall->getDescription() << endl;

    if (tropicalMedium) 
        cout << "Medium: " << tropicalMedium->getDescription() << endl;

    if (tropicalLarge) 
        cout << "Large: " << tropicalLarge->getDescription() << endl;

    cout << endl;

    // Test Carnivorous Factory
    cout << "--- Carnivorous Plants ---" << endl;
    Plant* carnivorousSmall = carnivorousFactory.createSmallPlant();
    Plant* carnivorousMedium = carnivorousFactory.createMediumPlant();
    Plant* carnivorousLarge = carnivorousFactory.createLargePlant();

    if (carnivorousSmall) 
        cout << "Small: " << carnivorousSmall->getDescription() << endl;
    
    if (carnivorousMedium) 
        cout << "Medium: " << carnivorousMedium->getDescription() << endl;

    if (carnivorousLarge) 
        cout << "Large: " << carnivorousLarge->getDescription() << endl;

    cout << endl;

    cout << "--- Succulent Plants ---" << endl;
    Plant* succulentSmall = succulentFactory.createSmallPlant();
    Plant* succulentMedium = succulentFactory.createMediumPlant();
    Plant* succulentLarge = succulentFactory.createLargePlant();

    cout << "Small: " << succulentSmall->getDescription() << endl;
    cout << "Medium: " << succulentMedium->getDescription() << endl;
    cout << "Large: " << succulentLarge->getDescription() << endl;
    cout << endl;

    // Test cloning
    cout << "--- Testing Cloning ---" << endl;
    Plant* clonedDaisy = temperateSmall->clone();
    cout << "Original: " << temperateSmall->getDescription() << endl;
    cout << "Clone: " << clonedDaisy->getDescription() << endl;

    Plant* clonedLilac = temperateMedium->clone();
    cout << "Original: " << temperateMedium->getDescription() << endl;
    cout << "Clone: " << clonedLilac->getDescription() << endl;

    Plant* clonedWhiteOak = temperateLarge->clone();
    cout << "Original: " << temperateLarge->getDescription() << endl;
    cout << "Clone: " << clonedWhiteOak->getDescription() << endl;

    cout << endl;

    delete temperateSmall;
    delete temperateMedium;
    delete temperateLarge;
    delete tropicalSmall;
    delete tropicalMedium;
    delete tropicalLarge;
    delete carnivorousSmall;
    delete carnivorousMedium;
    delete carnivorousLarge;
    delete clonedDaisy;
    delete clonedLilac;
    delete clonedWhiteOak;
}
*/

// oboselete testing code, the new ones work better and have no memory leaks
/*void testDecoratorPattern() {
    cout << "=== TESTING DECORATOR PATTERN ===" << endl;
    cout << endl;

    // create a small mediium & large plant
    Plant* daisy = new Daisy();
    Plant* aloe = new AloeVera();
    Plant* nepenthes = new Nepenthes();

    cout << "--- Basic Plantswith no decoration ---" << endl;
    cout << "Daisy: " << daisy->getDescription() << " - Price: R" << daisy->getPrice() << endl;
    cout << "Aloe Vera: " << aloe->getDescription() << " - Price: R" << aloe->getPrice() << endl;
    cout << "Nepenthes: " << nepenthes->getDescription() << " - Price: R" << nepenthes->getPrice() << endl;
    cout << endl;

    // Test one decorators
    cout << "--- Individual Decorators ---" << endl;
    
    //  pot decorator alone test
    Plant* daisyInClayPot = new PotDecorator(new Daisy(), "Clay");
    cout << "Daisy in Clay Pot: " << daisyInClayPot->getDescription() << " - Price: R" << daisyInClayPot->getPrice() << endl;
    
    // fertilizer decorator alone test
    Plant* aloeWithFertilizer = new FertilizerDecorator(new AloeVera(), "Organic");
    cout << "Aloe with Fertilizer: " << aloeWithFertilizer->getDescription() << " - Price: R" << aloeWithFertilizer->getPrice() << endl;
    cout << endl;

    // Test multiple decorations now
    cout << "--- Multiple Decorations ---" << endl;
    
    // Pot + Fertilizer
    Plant* PremiumNepenthes = new FertilizerDecorator(new PotDecorator(new Nepenthes(), "Decorative"), "Slow-Release");
    cout << "Premium Oak: " << PremiumNepenthes->getDescription() << " - Price: R" << PremiumNepenthes->getPrice() << endl;
    
    // Diff pot types
    Plant* daisyCeramic = new PotDecorator(new Daisy(), "Ceramic");
    Plant* daisyPlastic = new PotDecorator(new Daisy(), "Plastic");
    cout << "Daisy Ceramic: " << daisyCeramic->getDescription() << " - Price: R" << daisyCeramic->getPrice() << endl;
    cout << "Daisy Plastic: " << daisyPlastic->getDescription() << " - Price: R" << daisyPlastic->getPrice() << endl;
    cout << endl;

    // diff fertilizer types
    cout << "--- Different Fertilizer Types ---" << endl;
    Plant* aloeOrganic = new FertilizerDecorator(new AloeVera(), "Organic");
    Plant* aloeLiquid = new FertilizerDecorator(new AloeVera(), "Liquid");
    Plant* aloeSlowRelease = new FertilizerDecorator(new AloeVera(), "Slow-Release");
    
    cout << "Aloe Organic: " << aloeOrganic->getDescription() << " - Price: R" << aloeOrganic->getPrice() << endl;
    cout << "Aloe Liquid: " << aloeLiquid->getDescription() << " - Price: R" << aloeLiquid->getPrice() << endl;
    cout << "Aloe Slow-Release: " << aloeSlowRelease->getDescription() << " - Price: R" << aloeSlowRelease->getPrice() << endl;
    cout << endl;

    cout << "--- Testing Construction Methods ---" << endl;

// Method 1: Direct construction (current way - broken)
Plant* broken = new FertilizerDecorator(new PotDecorator(new WhiteOak(), "Clay"), "Organic");
cout << "Nested (broken): " << broken->getDescription() << endl;

// Method 2: Step-by-step construction
Plant* step1 = new WhiteOak();
Plant* step2 = new PotDecorator(step1, "Clay");  
Plant* step3 = new FertilizerDecorator(step2, "Organic");
cout << "Step-by-step: " << step3->getDescription() << endl;

    delete daisy;
    delete aloe;
    delete nepenthes;
    delete daisyInClayPot;
    delete aloeWithFertilizer;
    delete PremiumNepenthes;
    delete daisyCeramic;
    delete daisyPlastic;
    delete aloeOrganic;
    delete aloeLiquid;
    delete aloeSlowRelease;
}
*/

/*
// oboselete testing code, the new ones work better and have no memory leaks

void testPatternsTogether() {
    cout << "=== TESTING PATTERNS TOGETHER ===" << endl;
    cout << endl;

    // Create factories
    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;
    SucculentPlantFactory succulentFactory;

    cout << "--- Creating Premium Plant Packages ---" << endl;
    
    // Create plants from factories and decorate them, has both decorators being ussed
    Plant* premiumTemperatePackage = new FertilizerDecorator(new PotDecorator(temperateFactory.createMediumPlant(), "Ceramic"), "Slow-Release");
    Plant* premiumTropicalPackage = new FertilizerDecorator(new PotDecorator(tropicalFactory.createSmallPlant(), "Decorative"), "Liquid");
    Plant* premiumCarnivorousPackage = new FertilizerDecorator(new PotDecorator(carnivorousFactory.createLargePlant(), "Clay"), "Organic");
    Plant* premiumSucculentPackage = new FertilizerDecorator(new PotDecorator(succulentFactory.createLargePlant(), "Decorative"), "Slow-Release");

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
    vector<Plant*> decoratedPlants;
    
    // Different decoration combos, kfc would be great rn 
    decoratedPlants.push_back(new PotDecorator(temperateFactory.createSmallPlant(), "Plastic"));
    decoratedPlants.push_back(new FertilizerDecorator(temperateFactory.createSmallPlant(), "Organic"));
    decoratedPlants.push_back(new FertilizerDecorator(new PotDecorator(temperateFactory.createLargePlant(), "Decorative"), "Slow-Release"));

    // do this type for loop with vectors diff ways usually will complian/crash @compile time
    for (size_t i = 0; i < decoratedPlants.size(); i++) 
    {
        cout << "Plant " << (i + 1) << ": " << decoratedPlants[i]->getDescription() << " - Price: R" << decoratedPlants[i]->getPrice() << endl;
    }
    cout << endl;

    delete premiumTemperatePackage;
    delete premiumTropicalPackage;
    delete premiumCarnivorousPackage;

    for (size_t i = 0; i < decoratedPlants.size(); i++) 
    {
        delete decoratedPlants[i];
    }
}
*/