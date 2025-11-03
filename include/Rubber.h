/**
 * @file Rubber.h
 * @brief Concrete product representing a Rubber tropical plant (large size).
 * 
 * Rubber plant (Ficus elastica) is a large tropical tree known for its broad,
 * glossy leaves and its historical use in rubber production.
 */

#ifndef RUBBER_H
#define RUBBER_H

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
 * @class Rubber
 * @brief Concrete large tropical plant class representing a Rubber plant.
 * 
 * Inherits from LargePlant and implements the Prototype pattern through clone method.
 * Rubber plants are popular as indoor trees and are known for their large, leathery leaves.
 */
class Rubber : public LargePlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Rubber plant with species name and large size.
     */
    Rubber();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Rubber object to copy from.
     */
    Rubber(Rubber& other);

    /**
     * @brief Destructor.
     */
    ~Rubber();

    /**
     * @brief Creates a clone of the current Rubber object.
     * @return Pointer to a new Plant object that is a copy of this Rubber.
     */
    Plant* clone();
};

#endif