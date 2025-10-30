/**
 * @file Daisy.h
 * @brief Concrete product representing a Daisy temperate plant (small size).
 * 
 * Daisy is a common small flowering plant found in temperate regions,
 * known for its white petals and yellow center.
 */

#ifndef DAISY_H
#define DAISY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "SmallPlant.h"
#include "Plant.h"

/**
 * @class Daisy
 * @brief Concrete small temperate plant class representing a Daisy.
 * 
 * Inherits from SmallPlant and implements the Prototype pattern through clone method.
 * Daisies are cheerful, hardy flowers commonly found in temperate gardens and meadows.
 */
class Daisy : public SmallPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Daisy plant with species name and small size.
     */
    Daisy();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Daisy object to copy from.
     */
    Daisy(Daisy& other);

    /**
     * @brief Destructor.
     */
    ~Daisy();

    /**
     * @brief Creates a clone of the current Daisy object.
     * @return Pointer to a new Plant object that is a copy of this Daisy.
     */
    Plant* clone();
};

#endif