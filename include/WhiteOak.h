/**
 * @file WhiteOak.h
 * @brief Concrete product representing a White Oak temperate plant (large size).
 * 
 * White Oak is a large deciduous tree native to temperate regions of North America,
 * known for its strong wood and distinctive lobed leaves.
 */

#ifndef WHITEOAK_H
#define WHITEOAK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"

/**
 * @class WhiteOak
 * @brief Concrete large temperate plant class representing a White Oak tree.
 * 
 * Inherits from LargePlant and implements the Prototype pattern through clone method.
 * White Oaks are majestic trees that provide important habitat and are valued for their timber.
 */
class WhiteOak : public LargePlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a White Oak plant with species name and large size.
     */
    WhiteOak();

    /**
     * @brief Copy constructor.
     * @param other Reference to another WhiteOak object to copy from.
     */
    WhiteOak(WhiteOak& other);

    /**
     * @brief Destructor.
     */
    ~WhiteOak();

    /**
     * @brief Creates a clone of the current WhiteOak object.
     * @return Pointer to a new Plant object that is a copy of this WhiteOak.
     */
    Plant* clone();
};

#endif