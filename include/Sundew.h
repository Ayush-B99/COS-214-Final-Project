/**
 * @file Sundew.h
 * @brief Concrete product representing a Sundew carnivorous plant (small size).
 * 
 * Sundew is a small carnivorous plant that traps insects with sticky tentacles.
 * Part of the carnivorous plant family in the Abstract Factory pattern.
 */

#ifndef SUNDEW_H
#define SUNDEW_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "SmallPlant.h"

/**
 * @class Sundew
 * @brief Concrete small carnivorous plant class representing a Sundew.
 * 
 * Inherits from SmallPlant and implements the Prototype pattern through clone method.
 * Sundews are known for their glistening, sticky tentacles that trap insects.
 */
class Sundew : public SmallPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Sundew plant with species name and small size.
     */
    Sundew();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Sundew object to copy from.
     */
    Sundew(Sundew& other);

    /**
     * @brief Destructor.
     */
    ~Sundew();

    /**
     * @brief Creates a clone of the current Sundew object.
     * @return Pointer to a new Plant object that is a copy of this Sundew.
     */
    Plant* clone();
};

#endif