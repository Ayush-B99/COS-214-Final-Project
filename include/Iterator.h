#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Plant;

/**
 * @class Iterator
 * @brief Abstract base class defining the interface for plant iterators.
 * 
 * This class is part of the **Iterator design pattern**, allowing traversal
 * of different plant collections (e.g., Inventory, Stock, Orders) without
 * exposing their underlying data structures.
 * 
 * Concrete subclasses (such as `InventoryIterator`, `StockIterator`, and 
 * `OrderIterator`) implement traversal logic specific to their respective
 * storage types.
 */
class Iterator
{

public:
    /**
     * @brief Virtual destructor for the Iterator interface.
     * @details Ensures derived iterator destructors are called properly.
     */
    virtual ~Iterator();

    /**
     * @brief Retrieves the next plant in the collection.
     * @return Pointer to the next Plant object, or nullptr if no more elements remain.
     */
    virtual Plant* next() = 0;

    /**
     * @brief Checks if more plants are available to iterate over.
     * @return True if additional plants exist, false otherwise.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Retrieves the current plant in the iteration without advancing.
     * @return Pointer to the current Plant object.
     */
    virtual Plant* currentPlant() = 0;

    /**
     * @brief Resets the iterator to the start of the collection.
     * @details Allows iteration from the beginning again.
     */
    virtual void reset() = 0;
};

#endif
