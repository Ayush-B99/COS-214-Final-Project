/**
 * @file Fertilizer.h
 * @brief Concrete command for fertilizing plants.
 * 
 * The Fertilizer command encapsulates the fertilization operation,
 * providing essential nutrients to support plant growth and health.
 */

#ifndef FERTILIZER_H
#define FERTILIZER_H

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
 * @class Fertilizer
 * @brief Concrete command that applies fertilizer to plants.
 * 
 * This command provides nutrients to the plant receiver when executed.
 * Fertilization enhances plant growth and supports overall health.
 */
class Fertilizer : public Command {
private:
    Plant *receiver; ///< The plant that receives the fertilizer application

public:
    /**
     * @brief Constructs a Fertilizer command for the specified plant.
     * @param plant The plant to be fertilized when this command executes.
     */
    Fertilizer(Plant *plant);

    /**
     * @brief Executes the fertilization operation on the plant.
     * 
     * Calls the appropriate method on the receiver plant to apply
     * fertilizer, providing essential nutrients for growth.
     */
    void execute();
};

#endif