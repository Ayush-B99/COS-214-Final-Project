/**
 * @file FertilizerDecorator.h
 * @brief Concrete decorator for adding fertilizer features to plants.
 * 
 * The FertilizerDecorator adds fertilizer-related properties and costs to plant objects.
 * This allows plants to be enhanced with different types of fertilizers that affect
 * both the description and price of the plant.
 */

#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantDecorator.h"
#include "Plant.h"

/**
 * @class FertilizerDecorator
 * @brief Concrete decorator that adds fertilizer features to plants.
 * 
 * Decorates a Plant object with fertilizer properties, modifying the price
 * and description to include fertilizer information. Different fertilizer types
 * can be applied with varying costs.
 */
class FertilizerDecorator : public PlantDecorator {
private:
    string fertilizer;     ///< Type of fertilizer applied
    double fertilizerCost; ///< Additional cost for the fertilizer

public:
    /**
     * @brief Constructs a FertilizerDecorator with specified fertilizer type.
     * @param plant Unique pointer to the Plant object to be decorated with fertilizer.
     * @param type Type of fertilizer to apply (e.g., "organic", "slow-release", "liquid").
     */
    FertilizerDecorator(std::unique_ptr<Plant> plant, std::string type);

    /**
     * @brief Calculates the total price including base plant and fertilizer cost.
     * @return Total price (base plant price + fertilizer cost).
     */
    double getPrice();

    /**
     * @brief Generates description including fertilizer information.
     * @return Description combining plant details and fertilizer type.
     */
    string getDescription();

    /**
     * @brief Creates a deep copy of the fertilized plant.
     * @return Pointer to a new Plant object with the same fertilizer decoration.
     */
    Plant* clone();
};

#endif