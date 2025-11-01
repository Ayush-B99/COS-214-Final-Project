#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

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

/**
 * @file InventoryIterator.h
 * @brief Implements an iterator for traversing the Inventory BST.
 */

/**
 * @class InventoryIterator
 * @brief Concrete iterator for traversing plants in an Inventory.
 * 
 * InventoryIterator provides both fine-grained (Plant-level) and coarse-grained 
 * (Node-level) iteration over a binary search tree (BST) of PlantNode objects.
 * This allows external code to traverse the Inventory structure without directly 
 * accessing its internal BST implementation.
 * 
 * Implements the **Iterator design pattern**.
 */
class InventoryIterator : public Iterator
{
private:
    /**
     * @brief Root of the inventory BST.
     */
    PlantNode *root;

    /**
     * @brief Current node in the traversal.
     */
    PlantNode* currentNode;

    /**
     * @brief Index of the current plant inside the current node's plant vector.
     */
    size_t indexInNode;

    /**
     * @brief Stack used for iterative in-order traversal of the BST.
     */
    stack<PlantNode *> nodeStack;

public:
    /**
     * @brief Constructs an InventoryIterator starting at the root node.
     * @param root Pointer to the root PlantNode of the inventory.
     */
    InventoryIterator(PlantNode *root);

    /**
     * @brief Destructor for InventoryIterator.
     */
    ~InventoryIterator();

    /**
     * @brief Advances the iterator to the next Plant and returns it.
     * @return Pointer to the next Plant in the inventory, or nullptr if none.
     */
    Plant* next();

    /**
     * @brief Alternative fine-grained next function, allows for more precise control.
     * @return Pointer to the next Plant in the current node.
     */
    Plant* nextFine();

    /**
     * @brief Advances the iterator to the next node (PlantNode) in the BST.
     * @return Pointer to the next PlantNode, or nullptr if traversal is complete.
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
     * @return True if more PlantNodes exist, false otherwise.
     */
    bool hasNextNode();

    /**
     * @brief Resets the iterator to the beginning of the BST.
     */
    void reset();

    /**
     * @brief Helper function to push a node and all its left children onto the stack.
     * @param node Node to push onto the stack.
     */
    void pushLeft(PlantNode *node);

    /**
     * @brief Retrieves the current position of the iterator for serialization or temporary storage.
     * @return Map of PlantNode pointers to plant indices representing the iterator's position.
     */
    map<PlantNode*, int> getPosition();

    /**
     * @brief Restores the iterator's position from a saved map.
     * @param pos Map representing a previously saved iterator position.
     */
    void setPosition(map<PlantNode*, int>& pos);
};

#endif
