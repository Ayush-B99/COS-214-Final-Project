/**
 * @file NeedsCare.h
 * @brief Concrete state representing a plant that requires attention.
 * 
 * The NeedsCare state represents a plant that is showing signs of neglect
 * and requires immediate care to prevent further deterioration.
 */

#ifndef NEEDSCARE_H
#define NEEDSCARE_H

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
 * @class NeedsCare
 * @brief Concrete state representing a plant needing attention.
 * 
 * This state indicates the plant has been neglected and requires care.
 * From this state, plants can improve to Good state with proper care,
 * or degrade to Dead state with continued neglect.
 */
class NeedsCare : public HealthState {
public:
    /**
     * @brief Degrades the plant's health from NeedsCare to Dead state.
     * @param plant The plant to transition to a worse health state.
     * 
     * When a plant in NeedsCare state is further neglected, it dies and
     * transitions to Dead state.
     */
    void degrade(Plant* plant);

    /**
     * @brief Improves the plant's health from NeedsCare to Good state.
     * @param plant The plant to transition to a better health state.
     * 
     * When a plant in NeedsCare state receives proper care, it recovers
     * and transitions to Good state.
     */
    void improve(Plant* plant);

    /**
     * @brief Gets a warning status message for neglected plants.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant needs immediate care.
     */
    string getStatusMessage(Plant* plant);

    /**
     * @brief Indicates the plant is not dead yet.
     * @return false since NeedsCare state represents struggling but living plants.
     */
    bool isDead();

    /**
     * @brief Gets the name of this health state.
     * @return "NeedsCare" representing the warning state.
     */
    string getName();
};

#endif