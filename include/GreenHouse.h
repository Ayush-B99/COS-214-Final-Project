/**
 * @file GreenHouse.h
 * @brief Abstract factory for creating plants of different sizes.
 * 
 * The GreenHouse class serves as the abstract factory in the Abstract Factory pattern.
 * It defines the interface for creating families of related plant objects (small, medium, large)
 * without specifying their concrete classes.
 */

#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;
#include "Plant.h"

/**
 * @class GreenHouse
 * @brief Abstract factory class for creating plant objects of different sizes.
 * 
 * This class defines the interface that concrete factory classes must implement
 * to create small, medium, and large plant objects specific to their plant category.
 * 
 * @note Concrete factories utilize the Prototype pattern through the clone() method
 * available on all Plant objects, allowing efficient object creation by copying
 * prototype instances rather than constructing from scratch.
 */

class GreenHouse {
public:
    /**
     * @brief Creates a small plant object.
     * @return Pointer to the created small Plant object.
     */
    virtual Plant* createSmallPlant() = 0;

    /**
     * @brief Creates a medium plant object.
     * @return Pointer to the created medium Plant object.
     */
    virtual Plant* createMediumPlant() = 0;

    /**
     * @brief Creates a large plant object.
     * @return Pointer to the created large Plant object.
     */
    virtual Plant* createLargePlant() = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~GreenHouse();
};

#endif