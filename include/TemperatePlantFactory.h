/**
 * @file TemperatePlantFactory.h
 * @brief Concrete factory for creating temperate climate plants.
 * 
 * This factory creates temperate plants of different sizes including
 * Lilac, Daisy, and White Oak species.
 */

#ifndef TEMPERATEPLANTFACTORY_H
#define TEMPERATEPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"

// Temperate climate plant types
#include "Lilac.h"
#include "Daisy.h"
#include "WhiteOak.h"

/**
 * @class TemperatePlantFactory
 * @brief Concrete factory for creating temperate climate plants of various sizes.
 * 
 * Implements the GreenHouse interface to create small, medium, and large
 * temperate plants such as Lilacs, Daisies, and White Oaks.
 */
class TemperatePlantFactory : public GreenHouse {
public:
    /**
     * @brief Default constructor.
     */
    TemperatePlantFactory();

    /**
     * @brief Destructor.
     */
    ~TemperatePlantFactory();

    /**
     * @brief Creates a small temperate plant.
     * @return Pointer to a small temperate Plant object.
     */
    Plant* createSmallPlant();

    /**
     * @brief Creates a medium temperate plant.
     * @return Pointer to a medium temperate Plant object.
     */
    Plant* createMediumPlant();

    /**
     * @brief Creates a large temperate plant.
     * @return Pointer to a large temperate Plant object.
     */
    Plant* createLargePlant();
};

#endif