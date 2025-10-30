/**
 * @file CarnivorousPlantFactory.h
 * @brief Concrete factory for creating carnivorous plants.
 * 
 * This factory creates carnivorous plants of different sizes including
 * Pitcher, Sundew, and Nepenthes species.
 */

#ifndef CARNIVOROUSPLANTFACTORY_H
#define CARNIVOROUSPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"
#include "Plant.h"

// Specific carnivorous plant types
#include "Pitcher.h"
#include "Sundew.h"
#include "Nepenthes.h"

/**
 * @class CarnivorousPlantFactory
 * @brief Concrete factory for creating carnivorous plants of various sizes.
 * 
 * Implements the GreenHouse interface to create small, medium, and large
 * carnivorous plants such as Pitcher plants, Sundews, and Nepenthes.
 */
class CarnivorousPlantFactory : public GreenHouse {
public:
    /**
     * @brief Default constructor.
     */
    CarnivorousPlantFactory();

    /**
     * @brief Destructor.
     */
    ~CarnivorousPlantFactory();

    /**
     * @brief Creates a small carnivorous plant.
     * @return Pointer to a small carnivorous Plant object.
     */
    Plant* createSmallPlant();

    /**
     * @brief Creates a medium carnivorous plant.
     * @return Pointer to a medium carnivorous Plant object.
     */
    Plant* createMediumPlant();

    /**
     * @brief Creates a large carnivorous plant.
     * @return Pointer to a large carnivorous Plant object.
     */
    Plant* createLargePlant();
};

#endif