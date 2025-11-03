/**
 * @file Dead.h
 * @brief Concrete state representing a deceased plant.
 * 
 * The Dead state represents a plant that has died due to neglect or poor care.
 * This is a terminal state with no transitions to other states.
 */

#ifndef DEAD_H
#define DEAD_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "HealthState.h"
#include "Plant.h"

/**
 * @class Dead
 * @brief Concrete state representing a dead plant (terminal state).
 * 
 * This state indicates the plant has died and cannot be revived.
 * It serves as a terminal state in the state machine with no outgoing transitions.
 * All health management operations have no effect in this state.
 */
class Dead : public HealthState {
public:
    /**
     * @brief No operation - dead plants cannot degrade further.
     * @param plant The dead plant (no state change occurs).
     */
    void degrade(Plant* plant);

    /**
     * @brief No operation - dead plants cannot be improved.
     * @param plant The dead plant (no state change occurs).
     */
    void improve(Plant* plant);

    /**
     * @brief Gets a status message indicating the plant is dead.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant has died.
     */
    string getStatusMessage(Plant* plant);

    /**
     * @brief Confirms the plant is dead.
     * @return true since this state represents dead plants.
     */
    bool isDead();

    /**
     * @brief Gets the name of this health state.
     * @return "Dead" representing the terminal state.
     */
    string getName();
};

#endif