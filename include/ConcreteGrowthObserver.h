/**
 * @file ConcreteGrowthObserver.h
 * @brief Observer that monitors plant growth changes and coordinates care.
 * 
 * The ConcreteGrowthObserver implements the Observer pattern to monitor
 * changes in plant growth states and coordinate with the care handler system.
 * It bridges the State pattern (growth states) with the Chain of Responsibility.
 */

#ifndef CONCRETEGROWTHOBSERVER_H
#define CONCRETEGROWTHOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"
#include "HealthState.h"
#include "NeedsCare.h"

/**
 * @class ConcreteGrowthObserver
 * @brief Observes changes in a Plant's growth and triggers appropriate care.
 *
 * The ConcreteGrowthObserver monitors the growth state of a Plant object and
 * coordinates with the care handler system when growth-related changes occur.
 * This class implements the Observer pattern, watching for growth state
 * transitions and ensuring plants receive appropriate care at each stage.
 */
class ConcreteGrowthObserver {
private:
    Plant *subject;      ///< The Plant being observed for growth changes
    HealthState *state;  ///< The current health state of the observed Plant

public:
    /**
     * @brief Constructs a ConcreteGrowthObserver.
     * @param plant Pointer to the Plant being observed.
     */
    ConcreteGrowthObserver(Plant *plant);

    /**
     * @brief Destructor for ConcreteGrowthObserver.
     */
    ~ConcreteGrowthObserver();

    /**
     * @brief Called when the observed Plant undergoes a growth change.
     *
     * This function is triggered when the Plant's growth state changes.
     * It updates internal state and may trigger care requests through
     * the handler chain based on the new growth requirements.
     */
    void onGrowthChange();

    /**
     * @brief Gets the Plant being observed.
     * @return Pointer to the observed Plant.
     */
    Plant *getPlant();
};

#endif // CONCRETEGROWTHOBSERVER_H