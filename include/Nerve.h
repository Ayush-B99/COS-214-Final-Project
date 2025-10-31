/**
 * @file Nerve.h
 * @brief Concrete product representing a Nerve tropical plant (small size).
 * 
 * Nerve plant (Fittonia) is a small tropical plant known for its striking
 * veined patterns on its leaves, typically in pink, white, or red.
 */

#ifndef NERVE_H
#define NERVE_H

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
 * @class Nerve
 * @brief Concrete small tropical plant class representing a Nerve plant.
 * 
 * Inherits from SmallPlant and implements the Prototype pattern through clone method.
 * Nerve plants are prized for their decorative foliage with intricate vein patterns.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */
class Nerve : public SmallPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Nerve plant with species name and small size.
     */
    Nerve();

    /**
     * @brief Copy constructor.
     * @param other Reference to another Nerve object to copy from.
     */
    Nerve(Nerve& other);

    /**
     * @brief Destructor.
     */
    ~Nerve();

    /**
     * @brief Creates a clone of the current Nerve object.
     * @return Pointer to a new Plant object that is a copy of this Nerve.
     */
    Plant* clone();
};

#endif