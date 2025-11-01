#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Iterator.h"
#include "PlantNode.h"
#include "Plant.h"

/**
 * @file OrderIterator.h
 * @brief Implements an iterator for traversing the plants in an Order.
 */

/**
 * @class OrderIterator
 * @brief Concrete iterator for iterating over plants in a single Order.
 * 
 * OrderIterator allows sequential traversal of the plants stored in an Order.
 * Provides forward and backward iteration (via `next()` and `previous()`),
 * position tracking, and reset functionality.
 * 
 * Implements the **Iterator design pattern**.
 */
class OrderIterator : public Iterator {

private:
    /**
     * @brief Vector containing all plants in the order.
     */
    vector<Plant*> order;

    /**
     * @brief Current position of the iterator in the order vector.
     */
    int position;

public:
    /**
     * @brief Constructs an OrderIterator from the root PlantNode of the order.
     * @param order Pointer to the PlantNode containing the order's plants.
     */
    OrderIterator(PlantNode* order);

    /**
     * @brief Destructor for OrderIterator.
     */
    ~OrderIterator();

    /**
     * @brief Advances the iterator and returns the next Plant.
     * @return Pointer to the next Plant, or nullptr if at the end.
     */
    Plant* next();

    /**
     * @brief Returns the current Plant without advancing the iterator.
     * @return Pointer to the current Plant.
     */
    Plant* currentPlant();

    /**
     * @brief Checks if there are more plants to iterate over.
     * @return True if more plants exist, false otherwise.
     */
    bool hasNext();

    /**
     * @brief Resets the iterator to the beginning of the order.
     */
    void reset();

    /**
     * @brief Returns the current index of the iterator.
     * @return Integer index of the current position.
     */
    int getPosition();

    /**
     * @brief Sets the iterator to a specific position in the order.
     * @param index Index to set the iterator to.
     */
    void setPosition(int index);

    /**
     * @brief Checks if there are previous plants to iterate backward over.
     * @return True if a previous plant exists, false otherwise.
     */
    bool hasPrevious();

    /**
     * @brief Moves the iterator backward and returns the previous Plant.
     * @return Pointer to the previous Plant, or nullptr if at the beginning.
     */
    Plant* previous();
};

#endif
