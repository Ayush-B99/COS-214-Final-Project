/**
 * @file Nepenthes.h
 * @brief Concrete product representing a Nepenthes carnivorous plant (large size).
 * 
 * Nepenthes, also known as tropical pitcher plants, are large carnivorous plants
 * known for their elaborate and often colorful pitfall traps.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */

#ifndef NEPENTHES_H
#define NEPENTHES_H

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
 * @class Nepenthes
 * @brief Concrete large carnivorous plant class representing a Nepenthes.
 * 
 * Inherits from LargePlant and implements the Prototype pattern through clone method.
 * Nepenthes are tropical pitcher plants that can grow quite large and complex traps.
 */
class Nepenthes : public LargePlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Nepenthes plant with species name and large size.
     */
    Nepenthes();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Nepenthes object to copy from.
     */
    Nepenthes(Nepenthes& other);

    /**
     * @brief Destructor.
     */
    ~Nepenthes();

    /**
     * @brief Creates a clone of the current Nepenthes object.
     * @return Pointer to a new Plant object that is a copy of this Nepenthes.
     */
    Plant* clone();
};

#endif