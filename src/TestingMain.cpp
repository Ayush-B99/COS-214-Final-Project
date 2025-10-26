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
#include "../include/Sold.h"
#include "../include/Good.h"
#include "../include/NeedsCare.h"
#include "../include/Dead.h"
#include "../include/GrowthObserver.h"

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
    cout << "Is Mature: " << (plant.isMature() ? "Yes" : "No") << endl;
    
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




int main()
{
    cout << "PLANT MANAGEMENT SYSTEM TEST STATE AND SOME OF PLANT" << endl;
    cout << "===================================" << endl << endl;
    
    testBasicPlantCreation();
    testGrowthProgression();
    testHealthDegradation();
    testHealthRecovery();
    testIndividualCareActions();
    testSoldState();
    testDeadState();
    cout << "All tests completed, I AM A LEGEND" << endl;
    return 0;
}