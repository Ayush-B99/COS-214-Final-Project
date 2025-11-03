#ifndef PLANTNODE_H
#define PLANTNODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"
#include "GrowthState.h"
#include "HealthState.h"

/**
 * @file PlantNode.h
 * @brief Defines the PlantNode class, a container node for groups of Plant objects used in inventory and order BSTs.
 */

/**
 * @class PlantNode
 * @brief Represents a logical grouping of Plant objects within a binary tree structure.
 * 
 * The PlantNode class serves as a structural unit in the e-commerce system’s plant storage and order 
 * subsystems. Each node can hold multiple Plant objects belonging to a similar category or group, 
 * identified by a common @c key. The class provides basic binary tree connectivity via @c left and 
 * @c right pointers, allowing it to form inventory or order trees.
 * 
 * Although conceptually similar to the **Composite Pattern**, this implementation intentionally simplifies it:
 * - It avoids defining a shared base interface between individual @c Plant objects and composite nodes.
 * - Instead, it directly stores @c Plant pointers in a container (vector).
 * - This means @c PlantNode acts as a **grouping container** rather than a generalized hierarchical component.
 * 
 * Design Rationale
 * 
 * This class was designed as a *pragmatic adaptation* of the Composite pattern to fit the project’s domain needs:
 * 
 * - **Reduced Complexity:**  
 *   A traditional Composite pattern would introduce additional abstraction layers and polymorphic interfaces 
 *   (e.g., @c IPlantComponent or @c PlantComponent). However, this project does not require treating individual 
 *   @c Plant and grouped nodes uniformly, making that abstraction unnecessary.
 * 
 * - **Clear Ownership Semantics:**  
 *   Each node explicitly owns its @c Plant pointers and manages their lifetimes in its destructor. This 
 *   prevents ambiguous ownership hierarchies common in Composite structures and simplifies memory management.
 * 
 * - **Optimized for Performance:**  
 *   By avoiding polymorphic dispatch and virtual calls, this implementation is lightweight and efficient, 
 *   especially when constructing and traversing binary search trees for inventory or order data.
 * 
 * - **Domain-Driven Modeling:**  
 *   The @c PlantNode structure directly models logical plant groupings (e.g., by type, species, or category). 
 *   It is tailored to operations like stock lookups, low-stock detection, and order composition rather than 
 *   general-purpose hierarchical aggregation.
 *  
 *   A full Composite implementation was deemed unnecessary due to the lack of uniform operations 
 *   across @c Plant and @c PlantNode.
 * 
 * ### Example Usage
 * @code
 * // Creating a node grouping for "Succulents"
 * PlantNode* succulents = new PlantNode("Succulents");
 * succulents->addPlant(new AloeVera());
 * succulents->addPlant(new HenAndChicks());
 * 
 * // Adding to an inventory tree
 * inventoryRoot->setLeft(succulents);
 * 
 * succulents->printNode("", true);
 * @endcode
 */
class PlantNode
{
private:
    /**
     * @brief Collection of dynamically allocated Plant objects.
     * 
     * Represents all plants belonging to this node’s group. Each PlantNode
     * takes ownership of its Plant pointers and deletes them on destruction.
     */
    vector<Plant*> plants;

    /**
     * @brief Key identifying the group or category of plants.
     */
    string key;

    /**
     * @brief Left child node in the binary tree.
     */
    PlantNode* left;

    /**
     * @brief Right child node in the binary tree.
     */
    PlantNode* right;

public:
    /**
     * @brief Constructs a PlantNode with a specified group name or key.
     * @param name Descriptive name or key representing this plant group.
     */
    PlantNode(string name);

    /**
     * @brief Copy constructor used for deep or shallow duplication of nodes.
     * @param other Pointer to the PlantNode being copied.
     */
    PlantNode(PlantNode* other);

    /**
     * @brief Destructor for PlantNode.
     * 
     * Deletes all Plant pointers stored in the node’s vector and recursively
     * deletes connected child nodes if they exist.
     * 
     * @warning This assumes the node **owns** its contained Plant pointers.
     *          If plants are shared externally (e.g., shallow copies in Stock),
     *          ensure ownership is transferred or cleared before destruction
     *          to avoid double-free or segmentation faults.
     */
    ~PlantNode();

    /**
     * @brief Retrieves the node’s identifying key.
     * @return The key string representing this node’s group.
     */
    const string getKey();

    /**
     * @brief Returns all Plant pointers stored in this node.
     * @return Vector of Plant pointers.
     */
    vector<Plant*> getPlants();

    /**
     * @brief Gets the left child node.
     * @return Pointer to the left child PlantNode.
     */
    PlantNode* getLeft();

    /**
     * @brief Gets the right child node.
     * @return Pointer to the right child PlantNode.
     */
    PlantNode* getRight();

    /**
     * @brief Sets the left child node.
     * @param left Pointer to the new left PlantNode.
     */
    void setLeft(PlantNode* left);

    /**
     * @brief Sets the right child node.
     * @param right Pointer to the new right PlantNode.
     */
    void setRight(PlantNode* right);

    /**
     * @brief Adds a single Plant to this node’s collection.
     * @param plant Pointer to the Plant to add.
     */
    void addPlant(Plant* plant);

    /**
     * @brief Adds multiple Plant objects to this node’s collection.
     * @param newPlants Vector of Plant pointers to add.
     */
    void addPlants(vector<Plant*> newPlants);

    /**
     * @brief Removes a Plant from this node’s collection.
     * @param plant Pointer to the Plant to remove.
     * @return True if the plant was found and removed, false otherwise.
     */
    bool removePlant(Plant* plant);

    /**
     * @brief Removes all plants matching the specified growth state.
     * @param state Pointer to the GrowthState to match.
     * @return Vector of removed Plant pointers.
     */
    vector<Plant*> removeByGrowthState(GrowthState* state);

    /**
     * @brief Removes all plants matching the specified health state.
     * @param state Pointer to the HealthState to match.
     * @return Vector of removed Plant pointers.
     */
    vector<Plant*> removeByHealthState(HealthState* state);

    /**
     * @brief Checks if this node is a leaf (has no children).
     * @return True if both left and right are null.
     */
    bool isLeaf();

    /**
     * @brief Checks if a given Plant is stored within this node.
     * @param plant Pointer to the Plant to check for.
     * @return True if the Plant is in this node’s vector.
     */
    bool plantInNode(Plant* plant);

    /**
     * @brief Prints this node and its children in a readable tree format.
     * @param prefix Text prefix for indentation and formatting.
     * @param isLeft Whether this node is a left child (for tree alignment).
     */
    void printNode(string prefix, bool isLeft);
};

#endif