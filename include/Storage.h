#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "InventoryIterator.h"

/**
 * @class Storage
 * @brief Abstract base class representing a general storage container for plants.
 * 
 * This class defines a uniform interface for different types of plant storages, 
 * such as Inventory, Stock, and Order. Each concrete subclass maintains its own 
 * internal structure (e.g., a binary search tree of PlantNodes) and provides its 
 * own iterator for traversal.
 * 
 * ### Design Notes
 * - The design follows the **Iterator pattern**, as each subclass must implement 
 *   `createIterator()` to allow external traversal without exposing internal structure.
 * - This class conceptually resembles the **Component** in a Composite pattern, 
 *   but was not implemented as a full Composite hierarchy because the system 
 *   primarily uses `PlantNode` as a flexible container that can represent both 
 *   a single node or a collection of plants.
 * - This decision simplifies the memory model and avoids the overhead of 
 *   recursive polymorphic trees for every storage type, while still maintaining 
 *   clean abstraction and extensibility.
 */
class Storage {

public:
    /**
     * @brief Creates an iterator for traversing the plants in the storage.
     * @return A pointer to an Iterator implementation specific to the storage type.
     */
    virtual Iterator* createIterator() = 0;

    /**
     * @brief Adds a plant to the storage.
     * @param plant Pointer to the Plant object to be added.
     */
    virtual void addPlant(Plant* plant) = 0;

    /**
     * @brief Removes a plant from the storage.
     * @param plant Pointer to the Plant object to be removed.
     */
    virtual void removePlant(Plant* plant) = 0;

    /**
     * @brief Prints the current contents of the storage.
     */
    virtual void print() = 0;

    /// Virtual destructor for proper cleanup of derived classes.
    virtual ~Storage() = default;
};

#endif
