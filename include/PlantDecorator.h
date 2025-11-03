/**
 * @file PlantDecorator.h
 * @brief Abstract decorator class for adding responsibilities to Plant objects dynamically.
 * 
 * The PlantDecorator class follows the Decorator pattern, allowing additional features
 * like pots and fertilizers to be added to plant objects without modifying their core structure.
 * This enables flexible composition of plant features at runtime.
 */

#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"

/**
 * @class PlantDecorator
 * @brief Abstract base class for all plant decorators.
 * 
 * Inherits from Plant and serves as the base class for concrete decorators.
 * Maintains a reference to a decorated Plant object and delegates core operations
 * to it while adding new functionality. Uses smart pointers for automatic memory management.
 * 
 * @note All concrete decorators must implement the clone() method as part of the
 * Prototype pattern, ensuring that decorated plants can be properly copied along
 * with their decorations. This maintains the Prototype pattern consistency throughout
 * the entire plant hierarchy.
 */
class PlantDecorator : public Plant {
public:
    std::unique_ptr<Plant> decoratedPlant; ///< Smart pointer to the plant being decorated

    /**
     * @brief Constructs a PlantDecorator wrapping the specified plant.
     * @param plant Unique pointer to the Plant object to be decorated.
     */
    PlantDecorator(std::unique_ptr<Plant> plant);

    /**
     * @brief Gets the total price including the base plant and decorator additions.
     * @return Total price of the plant with all decorator additions.
     */
    double getPrice();

    /**
     * @brief Gets the description including the base plant and decorator features.
     * @return Comprehensive description of the plant with all decorator features.
     */
    string getDescription();

    /**
     * @brief Pure virtual clone method for creating copies of decorated plants.
     * @return Pointer to a new Plant object that is a copy of this decorated plant.
     * 
     * @note Concrete decorators must implement this to ensure proper deep copying
     * of both the decoration and the decorated plant, maintaining the Prototype pattern.
     */
    virtual Plant* clone() = 0;

    /**
     * @brief Gets the species of the decorated plant.
     * @return Species name of the underlying plant.
     */
    virtual string getSpecies();
};

#endif