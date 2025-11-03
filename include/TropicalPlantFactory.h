/**
 * @file TropicalPlantFactory.h
 * @brief Concrete factory for creating tropical plants.
 * 
 * This factory creates tropical plants of different sizes including
 * Nerve plants, Birds of Paradise, and Rubber plants.
 */

#ifndef TROPICALPLANTFACTORY_H
#define TROPICALPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"

// Tropical plant types
#include "Nerve.h"
#include "BirdOfParadise.h"
#include "Rubber.h"

/**
 * @class TropicalPlantFactory
 * @brief Concrete factory for creating tropical plants of various sizes.
 * 
 * Implements the GreenHouse interface to create small, medium, and large
 * tropical plants such as Nerve plants, Birds of Paradise, and Rubber plants.
 * 
 *  @note This factory leverages the Prototype pattern through the clone() method
 * to efficiently create new plant instances by copying existing prototypes.
 * 
 * * @note This factory leverages the Prototype pattern through the clone() method
 * to efficiently create new plant instances by copying existing prototypes.
 */
class TropicalPlantFactory : public GreenHouse {
public:
    /**
     * @brief Default constructor.
     */
    TropicalPlantFactory();

    /**
     * @brief Destructor.
     */
    ~TropicalPlantFactory();

    /**
     * @brief Creates a small tropical plant.
     * @return Pointer to a small tropical Plant object.
     */
    Plant* createSmallPlant();

    /**
     * @brief Creates a medium tropical plant.
     * @return Pointer to a medium tropical Plant object.
     */
    Plant* createMediumPlant();

    /**
     * @brief Creates a large tropical plant.
     * @return Pointer to a large tropical Plant object.
     */
    Plant* createLargePlant();
};

#endif