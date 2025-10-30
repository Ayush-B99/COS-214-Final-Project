/**
 * @file HenAndChicks.h
 * @brief Concrete product representing a Hen and Chicks succulent plant (small size).
 * 
 * Hen and Chicks (Sempervivum) is a small succulent plant that forms rosettes
 * and produces numerous offsets ("chicks") around the main plant ("hen").
 */

#ifndef HENANDCHICKS_H
#define HENANDCHICKS_H

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
 * @class HenAndChicks
 * @brief Concrete small succulent plant class representing Hen and Chicks.
 * 
 * Inherits from SmallPlant and implements the Prototype pattern through clone method.
 * These succulents are known for their ability to form dense mats of rosettes.
 * 
 * @note This class serves as both a Concrete Product in the Abstract Factory pattern
 * and a Prototype in the Prototype pattern, enabling efficient object creation
 * through cloning in the factory classes.
 */
class HenAndChicks : public SmallPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes a Hen and Chicks plant with species name and small size.
     */
    HenAndChicks();

    /**
     * @brief Copy constructor.
     * @param other Reference to another HenAndChicks object to copy from.
     */
    HenAndChicks(HenAndChicks& other);

    /**
     * @brief Destructor.
     */
    ~HenAndChicks();

    /**
     * @brief Creates a clone of the current HenAndChicks object.
     * @return Pointer to a new Plant object that is a copy of this HenAndChicks.
     */
    Plant* clone();
};

#endif