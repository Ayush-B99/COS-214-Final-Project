/**
 * @file GrowthState.h
 * @brief Abstract state interface for plant growth stages.
 * 
 * The GrowthState class defines the State pattern interface for managing
 * plant growth stages. Different concrete states represent various growth
 * phases of plants and define state-specific behavior for growth progression,
 * care requirements, and status reporting.
 */

#ifndef GROWTHSTATE_H
#define GROWTHSTATE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

// #include "Plant.h"

class Plant; // Forward declaration

/**
 * @class GrowthState
 * @brief Abstract state interface for plant growth stage management.
 * 
 * This class defines the interface that all concrete growth states must implement.
 * The State pattern allows a Plant object to change its behavior as it progresses
 * through different growth stages, from seed to mature plant.
 * 
 * Concrete states (Seed, Sprout, Mature) encapsulate stage-specific behavior
 * and manage transitions between growth stages based on plant development.
 */
class GrowthState {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived states.
     */
    virtual ~GrowthState();

    /**
     * @brief Gets a status message specific to the current growth stage.
     * @param plant The plant to get the status message for.
     * @return String containing a descriptive status message for the current growth stage.
     */
    virtual string getStatusMessage(Plant *plant) = 0;

    /**
     * @brief Advances the plant's growth, potentially transitioning to the next stage.
     * @param plant The plant that is growing.
     * 
     * This method handles growth progression and state transitions when the plant
     * reaches the next development threshold.
     */
    virtual void grow(Plant *plant) = 0;

    /**
     * @brief Gets the care actions required for the current growth stage.
     * @return Vector of strings describing required care actions for this growth stage.
     */
    virtual vector<string> getRequiredCare() = 0;

    /**
     * @brief Checks if the plant is ready to be sold.
     * @return true if the plant can be sold in this growth stage, false otherwise.
     */
    virtual bool isSold();

    /**
     * @brief Checks if the plant has reached maturity.
     * @return true if this state represents a mature plant, false otherwise.
     */
    virtual bool isMature();

    /**
     * @brief Gets the name of the growth state.
     * @return String representing the name of this growth stage.
     */
    virtual string getName() = 0;
};

#endif