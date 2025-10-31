/**
 * @file PotDecorator.h
 * @brief Concrete decorator for adding pot features to plants.
 * 
 * The PotDecorator adds pot-related properties and costs to plant objects.
 * This allows plants to be placed in different types of pots that affect
 * both the aesthetic description and the total price.
 */

#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantDecorator.h"

/**
 * @class PotDecorator
 * @brief Concrete decorator that adds pot features to plants.
 * 
 * Decorates a Plant object with pot properties, modifying the price
 * and description to include pot information. Different pot types
 * can be applied with varying aesthetic appeal and costs.
 * 
 * @note Implements the Prototype pattern through the clone() method, ensuring
 * that potted plants can be properly copied along with their pot configuration.
 * This maintains Prototype pattern consistency when factories create decorated
 * plant instances.
 */
class PotDecorator : public PlantDecorator {
private:
    string potType;  ///< Type of pot used (e.g., "clay", "ceramic", "plastic")
    double potCost;  ///< Additional cost for the pot

public:
    /**
     * @brief Constructs a PotDecorator with specified pot type.
     * @param plant Unique pointer to the Plant object to be placed in a pot.
     * @param type Type of pot to use (e.g., "terracotta", "decorative", "hanging").
     */
    PotDecorator(std::unique_ptr<Plant> plant, std::string type);

    /**
     * @brief Calculates the total price including base plant and pot cost.
     * @return Total price (base plant price + pot cost).
     */
    double getPrice();

    /**
     * @brief Generates description including pot information.
     * @return Description combining plant details and pot type.
     */
    string getDescription();

    /**
     * @brief Creates a deep copy of the potted plant.
     * @return Pointer to a new Plant object with the same pot decoration.
     * 
     * @note This method implements the Prototype pattern, ensuring that both
     * the base plant and pot decoration are properly cloned to create
     * an independent copy of the decorated plant.
     */
    Plant* clone();
};

#endif