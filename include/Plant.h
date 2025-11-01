#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"
#include "GrowthState.h"
// #include "HealthState.h"

class ConcreteGrowthObserver;
class HealthState;

/**
 * @class Plant
 * @brief Represents a plant entity in the system with lifecycle, care, and inventory management.
 * 
 * The Plant class is the core class in the system and participates in multiple design patterns:
 * 
 * **Design Patterns:**
 * - **Observer Pattern:** Notifies `ConcreteGrowthObserver` when growth state changes.
 * - **State Pattern:** `GrowthState` and `HealthState` dynamically control plant behavior.
 * - **Command / Chain of Responsibility Pattern:** `PlantCareHandler` handles care actions.
 * - **Prototype Pattern:** `clone()` allows deep copying of plants.
 * - **Decorator Pattern:** `getPrice()`, `getDescription()`, and `getSpecies()` can be decorated.
 * 
 * **Responsibilities:**
 * - Track plant growth, health, and care levels (water, sunlight, fertilizer, pruning).
 * - Execute care actions using strategy objects.
 * - Notify observers of state changes.
 * - Manage lifecycle: seed, sprout, mature, dead, ready-for-stock.
 * - Integrate with inventory and stock systems.
 */
class Plant
{
protected:
    string species;           /**< Species name of the plant */
    int waterLevel;           /**< Water level (0-100) */
    int sunlightLevel;        /**< Sunlight level (0-100) */
    int fertilizerLevel;      /**< Fertilizer level (0-100) */
    int pruneLevel;           /**< Pruning level (0-100) */
    int growthStage;          /**< Current growth stage */

private:
    PlantCareHandler *careStrategy; /**< Strategy for care actions (Command / Chain of Responsibility) */
    GrowthState *growthState;       /**< Current growth state (State pattern) */
    HealthState *healthState;       /**< Current health state (State pattern) */
    string climate;                 /**< Suitable climate */
    string description;             /**< Description (can be decorated) */
    double price;                   /**< Price (can be decorated) */
    string size;                    /**< Size category: small, medium, large */
    int currentCycleCount;          /**< Tracks growth cycles */

    // Growth cycle requirements
    int seedCyclesNeeded;           /**< Cycles required for seed stage */
    int sproutCyclesNeeded;         /**< Cycles required for sprout stage */
    int matureCyclesNeeded;         /**< Cycles required for mature stage */

    ConcreteGrowthObserver *observer; /**< Growth observer (Observer pattern) */

    bool readyForStock;             /**< Flag if plant is ready for stock */

public:
    /**
     * @brief Default constructor.
     */
    Plant();

    /**
     * @brief Constructs a plant with a given species.
     * @param species Species name
     */
    Plant(string species);

    /**
     * @brief Copy constructor for deep copy of a plant.
     * @param other Plant to copy from
     */
    Plant(const Plant& other);

    /**
     * @brief Destructor.
     */
    virtual ~Plant();

    /**
     * @brief Returns the price of the plant.
     * @return double Current price
     */
    virtual double getPrice();

    /**
     * @brief Returns the description of the plant.
     * @return string Description
     */
    virtual string getDescription();

    /**
     * @brief Returns the suitable climate for the plant.
     * @return string Climate
     */
    virtual string getClimate();

    /**
     * @brief Creates a deep copy of the plant (Prototype pattern).
     * @return Plant* Pointer to cloned plant
     */
    virtual Plant *clone() = 0;

    /**
     * @brief Sets the care strategy (Command pattern).
     * @param strategy Pointer to PlantCareHandler
     */
    void setCareStrategy(PlantCareHandler *strategy);

    /**
     * @brief Sets the growth state (State pattern).
     * @param state Pointer to GrowthState
     */
    void setGrowthState(GrowthState *state);

    /**
     * @brief Advances growth according to current GrowthState.
     */
    void grow();

    /**
     * @brief Sets the health state (State pattern).
     * @param state Pointer to HealthState
     */
    void setHealthState(HealthState *state);

    /**
     * @brief Attaches a growth observer (Observer pattern).
     * @param observer Pointer to ConcreteGrowthObserver
     */
    void attach(ConcreteGrowthObserver *observer);

    /**
     * @brief Detaches observer.
     */
    void detach();

    /**
     * @brief Notifies observer of growth changes.
     */
    void notify();

    /**
     * @brief Returns the species name.
     * @return string Species
     */
    virtual string getSpecies();

    /**
     * @brief Sets a new price (Decorator pattern support).
     * @param newPrice New price
     */
    virtual void setPrice(double newPrice);

    /**
     * @brief Sets a new description (Decorator pattern support).
     * @param newDesc New description
     */
    virtual void setDescription(string newDesc);

    /**
     * @brief Returns the current growth state.
     * @return GrowthState* Current growth state
     */
    GrowthState *getGrowthState();

    /**
     * @brief Returns the current health state.
     * @return HealthState* Current health state
     */
    HealthState *getHealthState();

    /**
     * @brief Updates resource decay each tick.
     */
    void tick();

    /**
     * @brief Checks if plant is ready for stock.
     * @return true if ready, false otherwise
     */
    bool isReadyForStock();

    /**
     * @brief Marks plant as ready for stock.
     */
    void markReadyForStock();

    /**
     * @brief Returns water level.
     * @return int Water level
     */
    int getWaterLevel() const;

    /**
     * @brief Returns sunlight level.
     * @return int Sunlight level
     */
    int getSunlightLevel() const;

    /**
     * @brief Returns fertilizer level.
     * @return int Fertilizer level
     */
    int getFertilizerLevel() const;

    /**
     * @brief Returns prune level.
     * @return int Prune level
     */
    int getPruneLevel() const;

    /**
     * @brief Restores water to maximum.
     */
    void restoreWater();

    /**
     * @brief Restores sunlight to maximum.
     */
    void restoreSunlight();

    /**
     * @brief Restores fertilizer to maximum.
     */
    void restoreFertilizer();

    /**
     * @brief Restores pruning to maximum.
     */
    void restorePrune();

    /**
     * @brief Receives watering action (Command pattern).
     */
    void receiveWatering();

    /**
     * @brief Receives sunlight action (Command pattern).
     */
    void receiveSunlight();

    /**
     * @brief Receives fertilizing action (Command pattern).
     */
    void receiveFertilizing();

    /**
     * @brief Receives pruning action (Command pattern).
     */
    void receivePruning();

    /**
     * @brief Completes care session after all actions.
     */
    void completeCareSession();

    /**
     * @brief Returns size of plant.
     * @return string Size
     */
    string getsize() const;

    /**
     * @brief Returns current growth cycle count.
     * @return int Current cycle count
     */
    int getCurrentCycleCount() const;

    /**
     * @brief Returns cycles needed for seed stage.
     * @return int Seed cycles
     */
    int getSeedCyclesNeeded() const;

    /**
     * @brief Returns cycles needed for sprout stage.
     * @return int Sprout cycles
     */
    int getSproutCyclesNeeded() const;

    /**
     * @brief Returns cycles needed for mature stage.
     * @return int Mature cycles
     */
    int getMatureCyclesNeeded() const;

    /**
     * @brief Resets growth cycle count.
     */
    void resetCycleCount();

    /**
     * @brief Prints current needs for debugging.
     */
    void printCurrentNeeds();

    /**
     * @brief Prints growth status.
     */
    void printGrowthStatus();

    /**
     * @brief Prints health status.
     */
    void printHealthStatus();

    /**
     * @brief Prints full plant status.
     */
    void printFullStatus();

    /**
     * @brief Determines if plant should be removed from inventory.
     * @return true if it should be removed
     */
    bool shouldRemoveFromInventory();

    /**
     * @brief Checks if plant is dead.
     * @return true if dead
     */
    bool isDead();

    /**
     * @brief Checks if plant is mature.
     * @return true if mature
     */
    bool isMature();

    /**
     * @brief Handles care request via chain of responsibility.
     */
    void handleCareRequest();

    /**
     * @brief Checks if plant needs watering.
     * @return true if water is needed
     */
    bool needsWater();

    /**
     * @brief Checks if plant needs sunlight.
     * @return true if sunlight is needed
     */
    bool needsSun();

    /**
     * @brief Checks if plant needs fertilizer.
     * @return true if fertilizer is needed
     */
    bool needsFertilizer();

    /**
     * @brief Checks if plant needs pruning.
     * @return true if pruning is needed
     */
    bool needsPrune();

protected:
    /**
     * @brief Sets growth requirements.
     * @param seed Cycles for seed stage
     * @param sprout Cycles for sprout stage
     * @param mature Cycles for mature stage
     */
    void setGrowthRequirements(int seed, int sprout, int mature);

    /**
     * @brief Sets plant size.
     * @param s Size ("small", "medium", "large")
     */
    void setSize(string s);

    /**
     * @brief Updates health state based on resource levels.
     */
    void updateHealth();
};

#endif
