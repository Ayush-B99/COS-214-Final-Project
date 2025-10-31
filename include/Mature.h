/**
 * @file Mature.h
 * @brief Concrete state representing the mature growth stage.
 * 
 * The Mature state represents a fully developed plant that has reached
 * its adult size and may be ready for sale or reproduction.
 */

#ifndef MATURE_H
#define MATURE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GrowthState.h"
#include "Plant.h"

/**
 * @class Mature
 * @brief Concrete state representing the final mature growth stage.
 * 
 * This state represents plants that have completed their growth cycle
 * and reached full size. Mature plants are typically ready for sale
 * and require maintenance care rather than developmental care.
 */
class Mature : public GrowthState {
public:
    /**
     * @brief No further growth - mature plants don't transition to other stages.
     * @param plant The mature plant (no state change occurs).
     * 
     * Mature plants have reached their final growth stage and do not
     * transition to other growth states through the grow() method.
     */
    void grow(Plant* plant);

    /**
     * @brief Gets the maintenance care requirements for mature plants.
     * @return Vector of care actions needed to maintain mature plant health.
     */
    vector<string> getRequiredCare();

    /**
     * @brief Gets a status message for mature plants.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant is fully mature and may be ready for sale.
     */
    string getStatusMessage(Plant* plant);

    /**
     * @brief Confirms the plant is mature.
     * @return true since this state represents mature plants.
     */
    bool isMature();

    /**
     * @brief Gets the name of this growth state.
     * @return "Mature" representing the final growth stage.
     */
    string getName();
};

#endif