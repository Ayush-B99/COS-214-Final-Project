/**
 * @file Prune.h
 * @brief Concrete command for pruning plants.
 * 
 * The Prune command encapsulates the pruning operation, which involves
 * trimming dead or overgrown parts to promote healthy plant development.
 */

#ifndef PRUNE_H
#define PRUNE_H

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
 * @class Prune
 * @brief Concrete command that performs pruning operation on plants.
 * 
 * This command trims the plant receiver when executed. Pruning helps
 * maintain plant shape, remove dead material, and encourage new growth.
 */
class Prune : public Command {
private:
    Plant *receiver; ///< The plant that receives the pruning operation

public:
    /**
     * @brief Constructs a Prune command for the specified plant.
     * @param plant The plant to be pruned when this command executes.
     */
    Prune(Plant *plant);

    /**
     * @brief Executes the pruning operation on the plant.
     * 
     * Calls the appropriate method on the receiver plant to perform
     * pruning, which may improve plant health and appearance.
     */
    void execute();
};

#endif