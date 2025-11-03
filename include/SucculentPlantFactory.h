/**
 * @file SucculentPlantFactory.h
 * @brief Concrete factory for creating succulent plants.
 * 
 * This factory creates succulent plants of different sizes including
 * Condelabra, Hen and Chicks, and Aloe Vera species.
 */

#ifndef SUCCULENTPLANTFACTORY_H
#define SUCCULENTPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"

// Specific succulent plant types
#include "Condelabra.h"
#include "HenAndChicks.h"
#include "AloeVera.h"

/**
 * @class SucculentPlantFactory
 * @brief Concrete factory for creating succulent plants of various sizes.
 * 
 * Implements the GreenHouse interface to create small, medium, and large
 * succulent plants such as Hen and Chicks, Aloe Vera, and Condelabra.
 * Succulent plants are known for their water-storing capabilities and
 * drought resistance.
 * 
 * @note This factory uses the Prototype pattern internally by calling clone()
 * on prototype plant objects to create new instances efficiently.
 */
class SucculentPlantFactory : public GreenHouse {
public:
    /**
     * @brief Default constructor.
     * Initializes the succulent plant factory with prototype instances.
     */
    SucculentPlantFactory();

    /**
     * @brief Destructor.
     * Cleans up any resources used by the factory.
     */
    ~SucculentPlantFactory();

    /**
     * @brief Creates a small succulent plant.
     * @return Pointer to a small succulent Plant object (Hen and Chicks).
     */
    Plant* createSmallPlant();

    /**
     * @brief Creates a medium succulent plant.
     * @return Pointer to a medium succulent Plant object (Aloe Vera).
     */
    Plant* createMediumPlant();

    /**
     * @brief Creates a large succulent plant.
     * @return Pointer to a large succulent Plant object (Condelabra).
     */
    Plant* createLargePlant();
};

#endif