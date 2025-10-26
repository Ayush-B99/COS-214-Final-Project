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
#include "../include/SucculentPlantFactory.h"
#include "../include/Plant.h"
#include "../include/PotDecorator.h"
#include "../include/FertilizerDecorator.h"
#include "../include/PlantDecorator.h"

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
}

void testDecoratorPattern() {
    cout << "=== TESTING DECORATOR PATTERN ===" << endl;
    cout << endl;

    // create a small mediium & large plant
    Plant* daisy = new Daisy();
    Plant* aloe = new AloeVera();
    Plant* nepenthes = new Nepenthes();

    cout << "--- Basic Plantswith no decoration ---" << endl;
    cout << "Daisy: " << daisy->getDescription() << " - Price: R" << daisy->getPrice() << endl;
    cout << "Aloe Vera: " << aloe->getDescription() << " - Price: R" << aloe->getPrice() << endl;
    cout << "White Oak: " << nepenthes->getDescription() << " - Price: R" << nepenthes->getPrice() << endl;
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

int main()
{
    try {
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