#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

// file includes here
#include "../include/TemperatePlantFactory.h"
#include "../include/TropicalPlantFactory.h"
#include "../include/CarnivorousPlantFactory.h"
#include "SucculentPlantFactory.h"
#include "../include/Plant.h"
#include "../include/PotDecorator.h"
#include "../include/FertilizerDecorator.h"

#include "../include/PlantDecorator.h"

void testAbstractFactory() {
    cout << "=== TESTING ABSTRACT FACTORY PATTERN ===" << endl;
    cout << endl;

    // Create factories
    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;

    // Test Temperate Factory
    cout << "--- Temperate Plants ---" << endl;
    Plant* temperateSmall = temperateFactory.createSmallPlant();
    Plant* temperateMedium = temperateFactory.createMediumPlant();
    Plant* temperateLarge = temperateFactory.createLargePlant();

    cout << "Small: " << temperateSmall->getDescription() << endl;
    cout << "Medium: " << temperateMedium->getDescription() << endl;
    cout << "Large: " << temperateLarge->getDescription() << endl;
    cout << endl;

    // Test Tropical Factory
    cout << "--- Tropical Plants ---" << endl;
    Plant* tropicalSmall = tropicalFactory.createSmallPlant();
    Plant* tropicalMedium = tropicalFactory.createMediumPlant();
    Plant* tropicalLarge = tropicalFactory.createLargePlant();

    if (tropicalSmall) cout << "Small: " << tropicalSmall->getDescription() << endl;
    if (tropicalMedium) cout << "Medium: " << tropicalMedium->getDescription() << endl;
    if (tropicalLarge) cout << "Large: " << tropicalLarge->getDescription() << endl;
    cout << endl;

    // Test Carnivorous Factory
    cout << "--- Carnivorous Plants ---" << endl;
    Plant* carnivorousSmall = carnivorousFactory.createSmallPlant();
    Plant* carnivorousMedium = carnivorousFactory.createMediumPlant();
    Plant* carnivorousLarge = carnivorousFactory.createLargePlant();

    if (carnivorousSmall) cout << "Small: " << carnivorousSmall->getDescription() << endl;
    if (carnivorousMedium) cout << "Medium: " << carnivorousMedium->getDescription() << endl;
    if (carnivorousLarge) cout << "Large: " << carnivorousLarge->getDescription() << endl;
    cout << endl;

    // Test cloning
    cout << "--- Testing Cloning ---" << endl;
    Plant* clonedDaisy = temperateSmall->clone();
    cout << "Original: " << temperateSmall->getDescription() << endl;
    cout << "Clone: " << clonedDaisy->getDescription() << endl;
    cout << endl;

    // Cleanup
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
}

void testDecoratorPattern() {
    cout << "=== TESTING DECORATOR PATTERN ===" << endl;
    cout << endl;

    // Create basic plants
    Plant* basicDaisy = new Daisy();
    Plant* basicAloe = new AloeVera();
    Plant* basicOak = new WhiteOak();

    cout << "--- Basic Plants (No Decorations) ---" << endl;
    cout << "Daisy: " << basicDaisy->getDescription() << " - Price: $" << basicDaisy->getPrice() << endl;
    cout << "Aloe Vera: " << basicAloe->getDescription() << " - Price: $" << basicAloe->getPrice() << endl;
    cout << "White Oak: " << basicOak->getDescription() << " - Price: $" << basicOak->getPrice() << endl;
    cout << endl;

    // Test individual decorators
    cout << "--- Individual Decorators ---" << endl;
    
    // Just a pot
    Plant* daisyInClayPot = new PotDecorator(new Daisy(), "Clay");
    cout << "Daisy in Clay Pot: " << daisyInClayPot->getDescription() << " - Price: $" << daisyInClayPot->getPrice() << endl;
    
    // Just fertilizer
    Plant* aloeWithFertilizer = new FertilizerDecorator(new AloeVera(), "Organic");
    cout << "Aloe with Fertilizer: " << aloeWithFertilizer->getDescription() << " - Price: $" << aloeWithFertilizer->getPrice() << endl;
    cout << endl;

    // Test multiple decorations
    cout << "--- Multiple Decorations ---" << endl;
    
    // Pot + Fertilizer
    Plant* premiumOak = new FertilizerDecorator(
                         new PotDecorator(
                           new WhiteOak(), "Decorative"), "Slow-Release");
    cout << "Premium Oak: " << premiumOak->getDescription() << " - Price: $" << premiumOak->getPrice() << endl;
    
    // Different pot types
    Plant* daisyCeramic = new PotDecorator(new Daisy(), "Ceramic");
    Plant* daisyPlastic = new PotDecorator(new Daisy(), "Plastic");
    cout << "Daisy Ceramic: " << daisyCeramic->getDescription() << " - Price: $" << daisyCeramic->getPrice() << endl;
    cout << "Daisy Plastic: " << daisyPlastic->getDescription() << " - Price: $" << daisyPlastic->getPrice() << endl;
    cout << endl;

    // Test different fertilizer types
    cout << "--- Different Fertilizer Types ---" << endl;
    Plant* aloeOrganic = new FertilizerDecorator(new AloeVera(), "Organic");
    Plant* aloeLiquid = new FertilizerDecorator(new AloeVera(), "Liquid");
    Plant* aloeSlowRelease = new FertilizerDecorator(new AloeVera(), "Slow-Release");
    
    cout << "Aloe Organic: " << aloeOrganic->getDescription() << " - Price: $" << aloeOrganic->getPrice() << endl;
    cout << "Aloe Liquid: " << aloeLiquid->getDescription() << " - Price: $" << aloeLiquid->getPrice() << endl;
    cout << "Aloe Slow-Release: " << aloeSlowRelease->getDescription() << " - Price: $" << aloeSlowRelease->getPrice() << endl;
    cout << endl;

    // Cleanup
    delete basicDaisy;
    delete basicAloe;
    delete basicOak;
    delete daisyInClayPot;
    delete aloeWithFertilizer;
    delete premiumOak;
    delete daisyCeramic;
    delete daisyPlastic;
    delete aloeOrganic;
    delete aloeLiquid;
    delete aloeSlowRelease;
}

void testPatternsTogether() {
    cout << "=== TESTING PATTERNS TOGETHER ===" << endl;
    cout << endl;

    // Create factories
    TemperatePlantFactory temperateFactory;
    TropicalPlantFactory tropicalFactory;
    CarnivorousPlantFactory carnivorousFactory;

    cout << "--- Creating Premium Plant Packages ---" << endl;
    
    // Create plants from factories and decorate them
    Plant* premiumTemperatePackage = new FertilizerDecorator(
                                      new PotDecorator(
                                        temperateFactory.createMediumPlant(), "Ceramic"), "Slow-Release");
    
    Plant* premiumTropicalPackage = new FertilizerDecorator(
                                     new PotDecorator(
                                       tropicalFactory.createSmallPlant(), "Decorative"), "Liquid");
    
    Plant* premiumCarnivorousPackage = new FertilizerDecorator(
                                        new PotDecorator(
                                          carnivorousFactory.createLargePlant(), "Clay"), "Organic");

    cout << "Premium Temperate Package: " << premiumTemperatePackage->getDescription() << " - Price: $" << premiumTemperatePackage->getPrice() << endl;
    
    if (premiumTropicalPackage) {
        cout << "Premium Tropical Package: " << premiumTropicalPackage->getDescription() << " - Price: $" << premiumTropicalPackage->getPrice() << endl;
    }
    
    if (premiumCarnivorousPackage) {
        cout << "Premium Carnivorous Package: " << premiumCarnivorousPackage->getDescription() << " - Price: $" << premiumCarnivorousPackage->getPrice() << endl;
    }
    cout << endl;

    cout << "--- Creating Multiple Decorated Plants from Factory ---" << endl;
    
    // Create multiple plants from factory and decorate differently
    vector<Plant*> decoratedPlants;
    
    // Different decoration combinations
    decoratedPlants.push_back(new PotDecorator(temperateFactory.createSmallPlant(), "Plastic"));
    decoratedPlants.push_back(new FertilizerDecorator(temperateFactory.createSmallPlant(), "Organic"));
    decoratedPlants.push_back(new FertilizerDecorator(
                               new PotDecorator(
                                 temperateFactory.createLargePlant(), "Decorative"), "Slow-Release"));

    for (int i = 0; i < decoratedPlants.size(); i++) {
        cout << "Plant " << (i + 1) << ": " << decoratedPlants[i]->getDescription() << " - Price: $" << decoratedPlants[i]->getPrice() << endl;
    }
    cout << endl;

    // Cleanup
    delete premiumTemperatePackage;
    delete premiumTropicalPackage;
    delete premiumCarnivorousPackage;
    for (int i = 0; i < decoratedPlants.size(); i++) {
        delete decoratedPlants[i];
    }
}


int main()
{
    cout << "PLANT STORE PATTERN TESTING" << endl;
    cout << "============================" << endl;
    cout << endl;

    // Test patterns separately
    testAbstractFactory();
    testDecoratorPattern();
    
    // Test patterns together
    testPatternsTogether();

    cout << "All tests completed successfully!" << endl;
    return 0;
}
