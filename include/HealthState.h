/**
 * @file HealthState.h
 * @brief Abstract state interface for plant health states.
 * 
 * The HealthState class defines the State pattern interface for managing
 * plant health states. Different concrete states represent various health
 * conditions of plants and define state-specific behavior for health
 * degradation, improvement, and status reporting.
 */

#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

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
 * @class HealthState
 * @brief Abstract state interface for plant health management.
 * 
 * This class defines the interface that all concrete health states must implement.
 * The State pattern allows a Plant object to change its behavior when its
 * health state changes, without requiring complex conditional logic in the Plant class.
 * 
 * Concrete states (Good, NeedsCare, Dead) encapsulate state-specific behavior
 * and manage transitions between states based on plant care actions.
 */
class HealthState {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived states.
     */
    virtual ~HealthState();

    /**
     * @brief Degrades the plant's health, potentially transitioning to a worse state.
     * @param plant The plant whose health is being degraded.
     */
    virtual void degrade(Plant *plant) = 0;

    /**
     * @brief Improves the plant's health, potentially transitioning to a better state.
     * @param plant The plant whose health is being improved.
     */
    virtual void improve(Plant *plant) = 0;

    /**
     * @brief Gets a status message specific to the current health state.
     * @param plant The plant to get the status message for.
     * @return String containing a descriptive status message for the current state.
     */
    virtual string getStatusMessage(Plant *plant) = 0;

    /**
     * @brief Checks if the plant is in a dead state.
     * @return true if the state represents a dead plant, false otherwise.
     */
    virtual bool isDead() = 0;

    /**
     * @brief Gets the name of the health state.
     * @return String representing the name of this health state.
     */
    virtual string getName() = 0;
};

#endif