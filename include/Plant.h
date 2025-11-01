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

class ConcreteGrowthObserver;
class HealthState;

/**
 * @file Plant.h
 * @brief Represents a plant entity in the system with full lifecycle, care, and inventory management.
 *
 * The Plant class is the core entity in the system and interacts with multiple design patterns:
 * 
 * **Design Patterns:**
 * - **Observer pattern:** ConcreteGrowthObserver observes changes in growth state and reacts accordingly.
 * - **State pattern:** GrowthState and HealthState represent dynamic states of the plant that change over time.
 * - **Command / Chain of Responsibility:** PlantCareHandler handles care requests like watering, sunlight, pruning, and fertilizing.
 * - **Prototype pattern:** clone() allows creation of deep copies of plants for inventory operations.
 * - **Decorator pattern:** getSpecies(), getPrice(), and getDescription() can be overridden or decorated to modify behavior or attributes.
 * 
 * **Responsibilities:**
 * - Track growth, health, and care levels.
 * - Support care actions via strategies.
 * - Support observer notifications for growth state changes.
 * - Integrate with inventory (ready-for-stock) and lifecycle management.
 * - Provide detailed reporting and debugging methods.
 * 
 * **Lifecycle:** Plants have seed, sprout, and mature cycles. They can die if neglected and become ready for sale when mature.
 */
class Plant
{
protected:
    /// Species of the plant
    string species;

    /// Water level (0-100)
    int waterLevel;

    /// Sunlight level (0-100)
    int sunlightLevel;

    /// Fertilizer level (0-100)
    int fertilizerLevel;

    /// Prune level (0-100)
    int pruneLevel;

    /// Current growth stage counter
    int growthStage;

private:
    /// Care strategy object (Command / Chain of Responsibility pattern)
    PlantCareHandler *careStrategy;

    /// Current growth state (State pattern)
    GrowthState *growthState;

    /// Current health state (State pattern)
    HealthState *healthState;

    /// Climate type suitable for plant
    string climate;

    /// Plant description (may be decorated)
    string description;

    /// Price of the plant (may be decorated)
    double price;

    /// Size category: "small", "medium", "large"
    string size;

    /// Current number of growth cycles completed
    int currentCycleCount;

    /// Growth requirements: number of cycles required for each stage
    int seedCyclesNeeded;
    int sproutCyclesNeeded;
    int matureCyclesNeeded;

    /// Observer object for the growth state
    ConcreteGrowthObserver *observer;

    /// Indicates whether plant is ready to be moved to Stock
    bool readyForStock;

public:
    /**
     * @brief Default constructor
     * @details Initializes a plant with default attributes.
     */
    Plant();

    /**
     * @brief Constructor specifying species
     * @param species Name of the plant species
     */
    Plant(string species);

    /**
     * @brief Copy constructor (Prototype pattern)
     * @param other Another Plant instance to copy
     */
    Plant(const Plant& other);

    /**
     * @brief Destructor
     */
    virtual ~Plant();

    /**
     * @brief Retrieves the price of the plant
     * @return Current price (double)
     */
    virtual double getPrice();

    /**
     * @brief Retrieves the description of the plant
     * @return Description string
     */
    virtual string getDescription();

    /**
     * @brief Retrieves the climate suitable for this plant
     * @return Climate string
     */
    virtual string getClimate();

    /**
     * @brief Retrieves the species of the plant
     * @return Species string
     */
    virtual string getSpecies();

    /**
     * @brief Sets the price of the plant (used by decorators)
     * @param newPrice New price value
     */
    virtual void setPrice(double newPrice);

    /**
     * @brief Sets the description of the plant (used by decorators)
     * @param newDesc New description
     */
    virtual void setDescription(string newDesc);

    /**
     * @brief Clone the plant (Prototype pattern)
     * @return Pointer to a new deep copy of this plant
     */
    virtual Plant* clone() = 0;

    /**
     * @brief Sets the care strategy (Command / Chain of Responsibility)
     * @param strategy Pointer to a PlantCareHandler
     */
    void setCareStrategy(PlantCareHandler *strategy);

    /**
     * @brief Executes care actions according to strategy
     */
    void handleCareRequest();

    /**
     * @brief Checks if the plant needs water
     * @return true if water level below threshold
     */
    bool needsWater();

    /**
     * @brief Checks if the plant needs sunlight
     * @return true if sunlight level below threshold
     */
    bool needsSun();

    /**
     * @brief Checks if the plant needs fertilizer
     * @return true if fertilizer level below threshold
     */
    bool needsFertilizer();

    /**
     * @brief Checks if the plant needs pruning
     * @return true if prune level below threshold
     */
    bool needsPrune();

    /// @name Care action methods
    void receiveWatering();
    void receiveSunlight();
    void receiveFertilizing();
    void receivePruning();
    void completeCareSession();
    /// @}

    /// @name State management
    void setGrowthState(GrowthState *state);
    void setHealthState(HealthState *state);
    void grow();
    void tick();
    void attach(ConcreteGrowthObserver *observer);
    void detach();
    void notify();
    /// @}

    /// @name Inventory helpers
    bool isReadyForStock();
    void markReadyForStock();
    bool shouldRemoveFromInventory();
    bool isDead();
    bool isMature();
    void restoreWater();
    void restoreSunlight();
    void restoreFertilizer();
    void restorePrune();
    void resetCycleCount();
    void printCurrentNeeds();
    void printGrowthStatus();
    void printHealthStatus();
    void printFullStatus();
    /// @}

protected:
    /// @name Growth and size helpers
    void setGrowthRequirements(int seed, int sprout, int mature);
    void setSize(string s);
    void updateHealth();
    /// @}
};

#endif
