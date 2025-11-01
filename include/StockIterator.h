#ifndef STOCKITERATOR_H
#define STOCKITERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Iterator.h"
#include "Plant.h"
#include "PlantNode.h"	

/**
 * @file StockIterator.h
 * @brief Implements an iterator for traversing plants in Stock.
 */

/**
 * @class StockIterator
 * @brief Concrete iterator for traversing plants in a Stock structure.
 * 
 * StockIterator allows sequential traversal of the plants stored in a Stock BST.
 * Supports both fine-grained (individual plant) and coarse-grained (node-level) iteration,
 * as well as position tracking and reset functionality.
 * 
 * Implements the **Iterator design pattern**.
 */
class StockIterator : public Iterator {

private:
    /**
     * @brief Root of the Stock BST.
     */
    PlantNode *root;

    /**
     * @brief Current node being traversed.
     */
    PlantNode* currentNode;

    /**
     * @brief Index within the current node's plant vector.
     */
    size_t indexInNode;

    /**
     * @brief Stack of nodes for depth-first traversal.
     */
    stack<PlantNode *> nodeStack;

public:
    /**
     * @brief Constructs a StockIterator from the root PlantNode.
     * @param root Pointer to the root PlantNode of the Stock tree.
     */
    StockIterator(PlantNode* root);

    /**
     * @brief Destructor for StockIterator.
     */
    ~StockIterator();

    /**
     * @brief Advances the iterator and returns the next Plant.
     * @return Pointer to the next Plant, or nullptr if at the end.
     */
    Plant* next();

    /**
     * @brief Alternative next function for fine-grained traversal.
     * @return Pointer to the next Plant in fine-grained order.
     */
    Plant* nextFine();

    /**
     * @brief Advances the iterator at node-level granularity.
     * @return Pointer to the next PlantNode.
     */
    PlantNode* nextCoarse();

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
     * @brief Checks if there are more nodes to iterate over.
     * @return True if additional nodes exist, false otherwise.
     */
    bool hasNextNode();

    /**
     * @brief Resets the iterator to the beginning of the Stock tree.
     */
    void reset();

    /**
     * @brief Pushes a node and all its left children onto the stack.
     * @param node Node to push onto the stack.
     */
    void pushLeft(PlantNode *node);
    
    /**
     * @brief Returns the current iterator position as a map of nodes and indices.
     * @return Map of PlantNode pointers to indices representing the iterator's position.
     */
    map<PlantNode*, int> getPosition();
    
    /**
     * @brief Sets the iterator position from a previously saved map.
     * @param pos Map of PlantNode pointers to indices representing the desired position.
     */
    void setPosition(map<PlantNode*, int>& pos);
};

#endif
