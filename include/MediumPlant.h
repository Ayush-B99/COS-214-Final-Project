/**
 * @file MediumPlant.h
 * @brief Abstract product representing medium-sized plants.
 * 
 * This class serves as the base class for all medium plant types
 * in the Abstract Factory pattern.
 */

#ifndef MEDIUMPLANT_H
#define MEDIUMPLANT_H

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
 * @class MediumPlant
 * @brief Abstract product class representing medium-sized plants.
 * 
 * Derived from Plant, this class represents the medium size variant
 * in the plant hierarchy. Concrete medium plant classes should inherit from this.
 */
class MediumPlant : public Plant {
public:
    string size; ///< Size designation of the plant

    /**
     * @brief Constructs a MediumPlant with the given species.
     * @param species The species name of the plant.
     */
    MediumPlant(string species);

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~MediumPlant();

    /**
     * @brief Gets the size character identifier.
     * @return Character representing the plant size ('M' for medium).
     */
    char getSize();
};

#endif