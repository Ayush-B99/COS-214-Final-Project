/**
 * @file Seed.h
 * @brief Concrete state representing the seed growth stage.
 * 
 * The Seed state represents a plant in its initial germination phase.
 * Seeds require specific care conditions to sprout and begin active growth.
 */

#ifndef SEED_H
#define SEED_H

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
 * @class Seed
 * @brief Concrete state representing the initial seed growth stage.
 * 
 * This state represents the beginning of a plant's lifecycle. Seeds require
 * proper moisture, temperature, and time to germinate and transition to the
 * Sprout stage. This is the most delicate and care-intensive stage.
 */
class Seed : public GrowthState {
public:
    /**
     * @brief Advances growth from Seed to Sprout stage when conditions are met.
     * @param plant The plant that is growing from seed to sprout.
     * 
     * When a seed receives adequate care and time, it germinates and
     * transitions to the Sprout growth stage.
     */
    void grow(Plant* plant);

    /**
     * @brief Gets a status message for seed-stage plants.
     * @param plant The plant to generate the status message for.
     * @return String indicating the plant is in seed stage and needs germination care.
     */
    string getStatusMessage(Plant* plant);

    /**
     * @brief Gets the specific care requirements for seeds.
     * @return Vector of care actions needed for successful seed germination.
     */
    vector<string> getRequiredCare();

    /**
     * @brief Gets the name of this growth state.
     * @return "Seed" representing the initial growth stage.
     */
    string getName();
};

#endif