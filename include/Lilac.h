/**
 * @file Lilac.h
 * @brief Concrete product representing a Lilac temperate plant (medium size).
 * 
 * Lilac is a medium-sized temperate shrub known for its fragrant purple, pink,
 * or white flower clusters that bloom in spring.
 */

#ifndef LILAC_H
#define LILAC_H

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
 * @class Lilac
 * @brief Concrete medium temperate plant class representing a Lilac.
 * 
 * Inherits from MediumPlant and implements the Prototype pattern through clone method.
 * Lilacs are beloved for their sweet fragrance and beautiful spring blooms.
 */
class Lilac : public MediumPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Lilac plant with species name and medium size.
     */
    Lilac();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Lilac object to copy from.
     */
    Lilac(Lilac& other);

    /**
     * @brief Destructor.
     */
    ~Lilac();

    /**
     * @brief Creates a clone of the current Lilac object.
     * @return Pointer to a new Plant object that is a copy of this Lilac.
     */
    Plant* clone();
};

#endif