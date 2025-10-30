/**
 * @file AloeVera.h
 * @brief Concrete product representing an Aloe Vera succulent plant (medium size).
 * 
 * Aloe Vera is a medium-sized succulent known for its medicinal properties,
 * particularly the soothing gel inside its thick, fleshy leaves.
 */

#ifndef ALOEVERA_H
#define ALOEVERA_H

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
 * @class AloeVera
 * @brief Concrete medium succulent plant class representing Aloe Vera.
 * 
 * Inherits from MediumPlant and implements the Prototype pattern through clone method.
 * Aloe Vera is widely cultivated for agricultural and medicinal uses.
 */
class AloeVera : public MediumPlant {
public:
    /**
     * @brief Default constructor.
     * Initializes an Aloe Vera plant with species name and medium size.
     */
    AloeVera();

    /**
     * @brief Copy constructor.
     * @param other Reference to another AloeVera object to copy from.
     */
    AloeVera(AloeVera& other);

    /**
     * @brief Destructor.
     */
    ~AloeVera();

    /**
     * @brief Creates a clone of the current AloeVera object.
     * @return Pointer to a new Plant object that is a copy of this AloeVera.
     */
    Plant* clone();
};

#endif