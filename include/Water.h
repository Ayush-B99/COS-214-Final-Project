/**
 * @file Water.h
 * @brief Concrete command for watering plants.
 * 
 * The Water command encapsulates the watering operation, providing
 * hydration to plants when executed.
 */

#ifndef WATER_H
#define WATER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Command.h"
#include "Plant.h"

/**
 * @class Water
 * @brief Concrete command that performs watering operation on plants.
 * 
 * This command hydrates the plant receiver when executed. Watering is
 * a fundamental care operation that affects plant health and growth.
 */
class Water : public Command {
private:
    Plant *receiver; ///< The plant that receives the watering operation

public:
    /**
     * @brief Constructs a Water command for the specified plant.
     * @param plant The plant to be watered when this command executes.
     */
    Water(Plant *plant);

    /**
     * @brief Executes the watering operation on the plant.
     * 
     * Calls the appropriate watering method on the receiver plant,
     * potentially improving the plant's health and hydration status.
     */
    void execute();
};

#endif