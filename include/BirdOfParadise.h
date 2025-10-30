/**
 * @file BirdOfParadise.h
 * @brief Concrete product representing a Bird of Paradise tropical plant (medium size).
 * 
 * Bird of Paradise is a medium-sized tropical plant known for its exotic,
 * bird-like flowers that resemble tropical birds in flight.
 */

#ifndef BIRDOFPARADISE_H
#define BIRDOFPARADISE_H

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
 * @class BirdOfParadise
 * @brief Concrete medium tropical plant class representing a Bird of Paradise.
 * 
 * Inherits from MediumPlant and implements the Prototype pattern through clone method.
 * Bird of Paradise plants produce spectacular flowers that look like colorful birds.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */
class BirdOfParadise : public MediumPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Bird of Paradise plant with species name and medium size.
     */
    BirdOfParadise();

    /**
     * @brief Copy constructor.
     * @param other Reference to another BirdOfParadise object to copy from.
     */
    BirdOfParadise(BirdOfParadise& other);

    /**
     * @brief Destructor.
     */
    ~BirdOfParadise();

    /**
     * @brief Creates a clone of the current BirdOfParadise object.
     * @return Pointer to a new Plant object that is a copy of this BirdOfParadise.
     */
    Plant* clone();
};

#endif