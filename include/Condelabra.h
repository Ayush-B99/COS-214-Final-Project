/**
 * @file Condelabra.h
 * @brief Concrete product representing a Condelabra succulent plant (large size).
 * 
 * Condelabra (likely referring to Euphorbia species) is a large succulent
 * with distinctive candelabra-like branching patterns.
 */

#ifndef CONDELABRA_H
#define CONDELABRA_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"
#include "Plant.h"

/**
 * @class Condelabra
 * @brief Concrete large succulent plant class representing a Condelabra plant.
 * 
 * Inherits from LargePlant and implements the Prototype pattern through clone method.
 * Condelabra plants are characterized by their tree-like growth and candelabra branching.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */
class Condelabra : public LargePlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Condelabra plant with species name and large size.
     */
    Condelabra();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Condelabra object to copy from.
     */
    Condelabra(Condelabra& other);

    /**
     * @brief Destructor.
     */
    ~Condelabra();

    /**
     * @brief Creates a clone of the current Condelabra object.
     * @return Pointer to a new Plant object that is a copy of this Condelabra.
     */
    Plant* clone();
};

#endif