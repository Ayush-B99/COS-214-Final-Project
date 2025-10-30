/**
 * @file Pitcher.h
 * @brief Concrete product representing a Pitcher carnivorous plant (medium size).
 * 
 * Pitcher plants are medium-sized carnivorous plants that use pitfall traps
 * filled with digestive fluids to capture prey.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */

#ifndef PITCHER_H
#define PITCHER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "MediumPlant.h"

/**
 * @class Pitcher
 * @brief Concrete medium carnivorous plant class representing a Pitcher plant.
 * 
 * Inherits from MediumPlant and implements the Prototype pattern through clone method.
 * Pitcher plants are characterized by their deep cavity traps that drown and digest insects.
 */
class Pitcher : public MediumPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Pitcher plant with species name and medium size.
     */
    Pitcher();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Pitcher object to copy from.
     */
    Pitcher(Pitcher& other);

    /**
     * @brief Destructor.
     */
    ~Pitcher();

    /**
     * @brief Creates a clone of the current Pitcher object.
     * @return Pointer to a new Plant object that is a copy of this Pitcher.
     */
    Plant* clone();
};

#endif