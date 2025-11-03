/**
 * @file SmallPlant.h
 * @brief Abstract product representing small-sized plants.
 * 
 * This class serves as the base class for all small plant types
 * in the Abstract Factory pattern.
 */

#ifndef SMALLPLANT_H
#define SMALLPLANT_H

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
 * @class SmallPlant
 * @brief Abstract product class representing small-sized plants.
 * 
 * Derived from Plant, this class represents the small size variant
 * in the plant hierarchy. Concrete small plant classes should inherit from this.
 * 
 * * @note All derived classes must implement the clone() method as part of
 * the Prototype pattern, enabling factories to create new instances efficiently
 * through copying rather than construction from scratch.
 */
class SmallPlant : public Plant {
public:
    string size; ///< Size designation of the plant

    /**
     * @brief Constructs a SmallPlant with the given species.
     * @param species The species name of the plant.
     */
    SmallPlant(string species);

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~SmallPlant();

    /**
     * @brief Gets the size character identifier.
     * @return Character representing the plant size ('S' for small).
     */
    char getSize();
};

#endif