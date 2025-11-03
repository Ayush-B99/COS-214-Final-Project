/**
 * @file Sun.h
 * @brief Concrete command for providing sunlight to plants.
 * 
 * The Sun command encapsulates the sunlight exposure operation,
 * essential for plant photosynthesis and growth.
 */

#ifndef SUN_H
#define SUN_H

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
 * @class Sun
 * @brief Concrete command that provides sunlight exposure to plants.
 * 
 * This command exposes the plant receiver to sunlight when executed.
 * Sunlight is crucial for photosynthesis and overall plant development.
 */
class Sun : public Command {
private:
    Plant *receiver; ///< The plant that receives the sunlight exposure

public:
    /**
     * @brief Constructs a Sun command for the specified plant.
     * @param plant The plant to receive sunlight when this command executes.
     */
    Sun(Plant *plant);

    /**
     * @brief Executes the sunlight exposure operation on the plant.
     * 
     * Calls the appropriate method on the receiver plant to provide
     * sunlight, supporting photosynthesis and growth processes.
     */
    void execute();
};

#endif