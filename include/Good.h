/**
 * @file Good.h
 * @brief Concrete state representing a healthy plant.
 * 
 * The Good state represents a plant that is in excellent health condition.
 * Plants in this state respond positively to care and can withstand some neglect
 * before transitioning to a worse state.
 */

#ifndef GOOD_H
#define GOOD_H

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
 * @class Good
 * @brief Concrete state representing optimal plant health.
 * 
 * This state indicates the plant is thriving and receiving adequate care.
 * From this state, plants can degrade to NeedsCare state with neglect,
 * or remain in Good state with continued proper care.
 */
class Good : public HealthState {
public:
    /**
     * @brief Destructor.
     */
    ~Good();

    /**
     * @brief Degrades the plant's health from Good to NeedsCare state.
     * @param plant The plant to transition to a worse health state.
     * 
     * When a plant in Good state is neglected, it transitions to NeedsCare state.
     */
    void degrade(Plant *plant);

    /**
     * @brief Maintains the plant in Good state (no improvement beyond optimal).
     * @param plant The plant being cared for.
     * 
     * Plants already in Good state remain in Good state when cared for,
     * as this is the optimal health condition.
     */
    void improve(Plant *plant);

    /**
     * @brief Gets a positive status message for healthy plants.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant is healthy and thriving.
     */
    string getStatusMessage(Plant *plant);

    /**
     * @brief Indicates the plant is not dead.
     * @return false since Good state represents living plants.
     */
    bool isDead();

    /**
     * @brief Gets the name of this health state.
     * @return "Good" representing the optimal health condition.
     */
    string getName();
};

#endif