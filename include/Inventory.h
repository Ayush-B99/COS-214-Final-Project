#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "Plant.h"
#include "PlantNode.h"
#include "GreenHouse.h"
#include "InventoryIterator.h"
#include "TemperatePlantFactory.h"
#include "TropicalPlantFactory.h"
#include "SucculentPlantFactory.h"
#include "CarnivorousPlantFactory.h"
#include "InventoryIterator.h"
#include "GrowthState.h"
#include "HealthState.h"
#include "Mature.h"
#include "Dead.h"

class Stock;
class Order;

/**
 * @class Inventory
 * @brief Implements binary search tree (BST)-based storage for all plants that are not yet ready for sale.
 *
 * The Inventory class serves as the central data structure for managing plants before they are mature.
 * It owns a tree of @ref PlantNode objects, where each node groups plants by a logical key (such as
 * type, category, or other grouping strategy).
 *
 * The class also provides a high-level interface for plant creation and management through its
 * greenhouse factories. These factories abstract away the creation logic for plants of different climates
 * (Temperate, Tropical, Succulent, Carnivorous).
 *
 * ### Design Notes
 * - **Primary Pattern:** This class embodies aspects of both the **Composite** and **Iterator** patterns.
 *   While `PlantNode` can act as a recursive structure similar to a composite, the design here uses a 
 *   lightweight single-level tree node rather than full polymorphic composites to minimize overhead.
 * - **Reasoning:** Using a `PlantNode` tree instead of a formal Composite hierarchy keeps memory ownership
 *   predictable and simplifies traversal logic while still maintaining hierarchical structure.
 * - **Factories:** Each `GreenHouse` subclass acts as a **Factory Method** provider for plant creation,
 *   encapsulating environment-specific creation logic.
 * - **Ownership:** The Inventory owns its `PlantNode` objects and is responsible for cleanup, making it 
 *   the authoritative structure for memory management of pre-sale plants.
 * - **Automation:** Automatically promotes mature plants to the Stock and removes dead plants from storage,
 *   reinforcing real-time consistency.
 */
class Inventory : public Storage {

private:

    /** @brief Root of the plant catalog BST. */
    PlantNode* plantCatalog;

    /** 
     * @brief Collection of all greenhouse factories.
     * 
     * These are stored in a fixed order to simplify lookup and iteration.
     * Each greenhouse is responsible for producing plants suited to its climate.
     */
    vector<GreenHouse*> greenHouses;

    // ===== Recursive helper functions =====

    /** @brief Helper for pretty-printing the inventory tree. */
    void printHelper(PlantNode* node, string prefix, bool isLeft);

    /** @brief Helper for recursively removing plants by growth state. */
    PlantNode* removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    /** @brief Helper for recursively removing plants by health state. */
    PlantNode* removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

    /** @brief Recursively collects plants matching a growth state. */
    void collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    /** @brief Recursively collects plants matching a health state. */
    void collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

    /** @brief Collects all plants in the tree recursively. */
    void collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches);

    /** @brief Counts all nodes in the tree recursively. */
    int countNodesRecursive(PlantNode* node);

public:
    Inventory();
    ~Inventory();

    /**
     * @brief Adds a greenhouse factory to the internal list.
     * @note Primarily used for extensibility or testing; factories are usually fixed.
     */
    void setClimate(GreenHouse* factory);

    /** @brief Creates and adds a small plant using the specified greenhouse. */
    Plant* addSmallPlant(GreenHouse* house, PlantCareHandler* handler);

    /** @brief Creates and adds a medium plant using the specified greenhouse. */
    Plant* addMediumPlant(GreenHouse* house, PlantCareHandler* handler);

    /** @brief Creates and adds a large plant using the specified greenhouse. */
    Plant* addLargePlant(GreenHouse* house, PlantCareHandler* handler);

    /** @brief Adds a prototype plant to the inventory (used for cloning). */
    void addPlantPrototype(Plant *prototype);

    /** @brief Creates an iterator for traversing the inventory. */
    InventoryIterator *createIterator();

    /** @brief Returns the total count of plants in the inventory. */
    int getPlantCount();

    // ===== Factory Accessors =====
    GreenHouse* getTemperateFactory();
    GreenHouse* getCarnivorousFactory();
    GreenHouse* getSucculentFactory();
    GreenHouse* getTropicalFactory();

    // ===== Storage Interface Implementations =====
    void addPlant(Plant *plant) override;
    void removePlant(Plant* plant) override;

    // ===== Plant Management =====
    vector<Plant*> removePlants(string key, GrowthState* state);
    vector<Plant*> removePlants(string key, HealthState* state);
    vector<Plant*> removePlants(GrowthState* state);
    vector<Plant*> removePlants(HealthState* state);

    /**
     * @brief Retrieves plants grouped under a specific key.
     * @return Vector of Plant pointers belonging to the specified node.
     */
    vector<Plant*> getPlants(string key);

    vector<Plant*> getPlants(string key, GrowthState* state);
    vector<Plant*> getPlants(string key, HealthState* state);
    vector<Plant*> getPlants(GrowthState* state);
    vector<Plant*> getPlants(HealthState* state);
    vector<Plant*> getAllPlants();

    /**
     * @brief Moves mature plants (GrowthState = Mature) to Stock.
     * 
     * This uses the @ref Storage interface rather than a direct dependency on Stock
     * to promote loose coupling.
     */
    void moveValidPlantsToStock(Stock* stock);

    /**
     * @brief Removes all plants that are dead (HealthState = Dead) from the tree.
     */
    void cleanUpDeadPlants();

    // ===== BST Structure Management =====
    PlantNode* removeNode(PlantNode* root, string key);
    PlantNode* findNode(PlantNode* root, string key);
    PlantNode* addNode(PlantNode* root, string key);

    /** @brief Returns the number of nodes in the BST. */
    int getNodeCount();

    /** @brief Prints a structured visualization of the inventory tree. */
    void print() override;

    /** @brief Returns the root node of the inventory tree. */
    PlantNode* getRoot();

    /** @brief Updates plant states or transitions as time passes. */
    void tick();

    /** @brief Checks whether a specific plant exists in the tree. */
    bool plantInTree(Plant* plant);
};

#endif
