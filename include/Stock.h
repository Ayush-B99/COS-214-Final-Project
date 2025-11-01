#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "StockIterator.h"
#include "HealthState.h"
#include "GrowthState.h"
#include "Dead.h"

// Forward declarations
class Inventory;
class Order;

/**
 * @class Stock
 * @brief Represents the storage structure for mature, sellable plants.
 *
 * The `Stock` class maintains a Binary Search Tree (BST) of @ref PlantNode objects,
 * similar to @ref Inventory, but it exclusively holds plants that have matured and are
 * ready for sale. Once plants are transferred here, `Stock` assumes **full ownership**,
 * making it responsible for their memory lifecycle and removal.
 *
 * ### Design Overview
 * - **Primary Pattern:** Part of the **Iterator** and **Factory Method** ecosystem, 
 *   complementing `Inventory` in the storage hierarchy.
 * - **Ownership Transfer:** Plants are moved from `Inventory` to `Stock` by pointer transfer, 
 *   not cloning. This ensures continuity of identity (state, growth, and metadata) across systems.
 * - **Structural Design:** Implements a **lightweight Composite**-like model through 
 *   recursive `PlantNode` trees. Full polymorphic composites were avoided for simplicity 
 *   and performance.
 * - **Automatic Cleanup:** Handles removal of dead plants (`HealthState = Dead`) and 
 *   supports live queries for low-stock detection and valuation.
 * - **Collaborators:**
 *   - `Inventory` – Source of mature plants.
 *   - `Order` – Destination for sold or reserved plants.
 *   - `StockIterator` – Provides traversal support for the stored structure.
 */
class Stock : public Storage {

private:
    /** @brief Root of the BST catalog for stocked plants. */
    PlantNode* stockCatalog;

    // ===== Recursive helpers =====
    /** @brief Helper for tree printing. */
    void printHelper(PlantNode* node, string prefix, bool isLeft);

    /** @brief Recursive helper to remove plants by health state. */
    PlantNode* removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

    /** @brief Recursive helper to remove plants by growth state. */
    PlantNode* removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    /** @brief Recursively collects plants matching a given health state. */
    void collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

    /** @brief Recursively collects plants matching a given growth state. */
    void collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    /** @brief Collects all plants recursively. */
    void collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches);

    /** @brief Counts nodes recursively. */
    int countNodesRecursive(PlantNode* node);

    /** @brief Counts plants recursively within all nodes. */
    int countPlantsRecursive(PlantNode* node);

    /** @brief Computes the total value of plants in the stock recursively. */
    double calculateValueRecursive(PlantNode* node);

public:
    Stock();
    ~Stock();

    /**
     * @brief Retrieves and prints plants with low quantities in stock.
     * 
     * Intended for inventory monitoring — helps trigger restock operations or greenhouse production.
     */
    void getLowStockItems();

    /**
     * @brief Calculates the total value of all plants currently in stock.
     * @return The cumulative monetary value of all stocked plants.
     */
    double getTotalStockValue();

    /** @brief Creates a stock-specific iterator for tree traversal. */
    StockIterator* createIterator();

    /** @brief Adds a plant to the BST structure (takes ownership). */
    void addPlant(Plant* plant) override;

    /** @brief Removes a plant from stock by pointer reference. */
    void removePlant(Plant* plant) override;

    // ===== BST Structure Management =====
    PlantNode* findNode(PlantNode* root, string key);
    PlantNode* addNode(PlantNode* root, string key);
    PlantNode* removeNode(PlantNode* root, string key);

    // ===== Filtering and Retrieval =====
    vector<Plant*> removePlants(string key, GrowthState* state);
    vector<Plant*> removePlants(string key, HealthState* state);
    vector<Plant*> removePlants(GrowthState* state);
    vector<Plant*> removePlants(HealthState* state);

    vector<Plant*> getPlants(string key);
    vector<Plant*> getPlants(string key, GrowthState* state);
    vector<Plant*> getPlants(string key, HealthState* state);
    vector<Plant*> getPlants(GrowthState* state);
    vector<Plant*> getPlants(HealthState* state);
    vector<Plant*> getAllPlants();

    /**
     * @brief Removes all plants that are dead (`HealthState = Dead`).
     *
     * Ensures stock consistency by removing plants that have expired or deteriorated.
     */
    void cleanUpDeadPlants();

    /** @brief Returns the number of nodes currently in the BST. */
    int getNodeCount();

    /** @brief Returns the total number of plants in all nodes. */
    int getPlantCount();

    /** @brief Prints the tree structure and plant contents. */
    void print() override;

    /** @brief Returns the root node of the BST. */
    PlantNode* getRoot();

    /**
     * @brief Moves a plant from stock into an order.
     * 
     * Used when plants are sold or reserved for dispatch.
     * @param plant Pointer to the plant being moved.
     * @param order Pointer to the target order receiving the plant.
     */
    void moveToOrder(Plant* plant, Order* order);

    /**
     * @brief Checks whether a plant currently exists in stock.
     * @param plant Pointer to the plant to check.
     * @return `true` if the plant is in stock, otherwise `false`.
     */
    bool plantInTree(Plant* plant);
};

#endif
