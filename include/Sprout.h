/**
 * @file Sprout.h
 * @brief Concrete state representing the sprout growth stage.
 * 
 * The Sprout state represents a plant that has germinated and begun
 * active growth, developing its first true leaves and establishing roots.
 */

#ifndef SPROUT_H
#define SPROUT_H

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
 * @class Sprout
 * @brief Concrete state representing the sprout growth stage.
 * 
 * This state represents young plants that have successfully germinated
 * and are developing their first true leaves. Sprouts require consistent
 * care to establish strong roots and grow into mature plants.
 */
class Sprout : public GrowthState {
public:
    /**
     * @brief Advances growth from Sprout to Mature stage when ready.
     * @param plant The plant that is growing from sprout to mature.
     * 
     * When a sprout receives proper care and reaches sufficient size/age,
     * it transitions to the Mature growth stage.
     */
    void grow(Plant* plant);

    /**
     * @brief Gets the care requirements for sprout-stage plants.
     * @return Vector of care actions needed for healthy sprout development.
     */
    vector<string> getRequiredCare();

    /**
     * @brief Gets a status message for sprout-stage plants.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant is in sprout stage and growing actively.
     */
    string getStatusMessage(Plant* plant);

    /**
     * @brief Gets the name of this growth state.
     * @return "Sprout" representing the young plant growth stage.
     */
    string getName();
};

#endif