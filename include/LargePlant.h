/**
 * @file LargePlant.h
 * @brief Abstract product representing large-sized plants.
 * 
 * This class serves as the base class for all large plant types
 * in the Abstract Factory pattern.
 */

#ifndef LARGEPLANT_H
#define LARGEPLANT_H

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
 * @class LargePlant
 * @brief Abstract product class representing large-sized plants.
 * 
 * Derived from Plant, this class represents the large size variant
 * in the plant hierarchy. Concrete large plant classes should inherit from this.
 */
class LargePlant : public Plant {
public:
    string size; ///< Size designation of the plant

    /**
     * @brief Constructs a LargePlant with the given species.
     * @param species The species name of the plant.
     */
    LargePlant(string species);

    /**
     * @brief Destructor.
     */
    ~LargePlant();

    /**
     * @brief Gets the size character identifier.
     * @return Character representing the plant size ('L' for large).
     */
    char getSize();
};

#endif