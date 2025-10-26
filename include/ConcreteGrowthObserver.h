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

#include "ConcreteGrowthMediator.h"
#include "Plant.h"
#include "HealthState.h"
#include "NeedsCare.h"

/**
 * @class ConcreteGrowthObserver
 * @brief Observes changes in a Plant's growth and interacts with a GrowthMediator.
 *
 * The ConcreteGrowthObserver monitors the growth state of a Plant object and
 * communicates relevant changes to a GrowthMediator for further action.
 * This class implements part of the Observer design pattern in conjunction with Plant.
 */
class ConcreteGrowthObserver
{
private:
    /**
     * @brief The Plant being observed.
     */
    Plant *subject;

    /**
     * @brief The current health state of the observed Plant.
     */
    HealthState *state;

    /**
     * @brief Mediator responsible for coordinating growth-related communication.
     */
    ConcreteGrowthMediator *mediator;

public:
    /**
     * @brief Constructs a ConcreteGrowthObserver.
     * @param plant Pointer to the Plant being observed.
     * @param med Pointer to the GrowthMediator that will handle communication.
     */
    ConcreteGrowthObserver(Plant *plant, ConcreteGrowthMediator *med);

    /**
     * @brief Destructor for ConcreteGrowthObserver.
     */
    ~ConcreteGrowthObserver();

    /**
     * @brief Called when the observed Plant undergoes a growth change.
     *
     * This function should be triggered when the Plant's growth state changes,
     * allowing the observer to update its internal state and notify the mediator if necessary.
     */
    void onGrowthChange();

    /**
     * @brief Gets the Plant being observed.
     * @return Pointer to the observed Plant.
     */
    Plant *getPlant();
};

#endif // CONCRETEGROWTHOBSERVER_H
