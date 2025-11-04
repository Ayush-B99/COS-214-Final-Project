#ifndef ORDER_H
#define ORDER_H

#include "Caretaker.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "OrderState.h"
#include "PlantNode.h"
#include "Plant.h"
#include "OrderIterator.h"
#include "Submitted.h"
#include "Draft.h"
#include "PotDecorator.h"
#include "FertilizerDecorator.h"
#include "Memento.h"

class Inventory;
class Stock;

/**
 * @class Order
 * @brief Represents a customer's order containing plants and decorations.
 *
 * The Order class stores plants ready for sale, manages their decoration
 * (via the Decorator pattern), and tracks the order's lifecycle (via the
 * State pattern). Orders are composed of PlantNodes forming a tree-like
 * structure and can be iterated using the Iterator pattern.
 */
class Order : public Storage {

private:
	Caretaker<OrderState>* stateCaretaker;
    /**
     * @brief Current state of the order (Draft, Submitted, etc.).
     * @note Managed via the State pattern.
     */
    shared_ptr<OrderState> state;

    /**
     * @brief Root node of the binary tree containing ordered plants.
     */
    PlantNode* orderItems;

    /**
     * @brief Unique identifier for this order.
     */
    string id;

    /**
     * @brief Cached total value of all plants and decorations in this order.
     */
    double total;

public:
    /**
     * @brief Constructs an Order with the specified identifier.
     * @param orderId Unique string identifier for this order.
     */
    Order(string orderId);

    /**
     * @brief Destructor for the Order.
     * @details Cleans up owned resources and deletes associated tree nodes.
     */
    ~Order();

    /**
     * @brief Proceeds the order to the next state.
     * @details Transitions the order (e.g., from Draft → Submitted) using the State pattern.
     */
    void proceed();

    /**
     * @brief Cancels the order and returns all plants to the appropriate storage.
     * @param inv Pointer to the Inventory where plants can be returned.
     * @param stock Pointer to the Stock where ready plants can be returned.
     */
    void cancel(Inventory* inv, Stock* stock);

    /**
     * @brief Adds a plant to this order.
     * @param item Pointer to the plant to add.
     */
    void addPlant(Plant* item);

    /**
     * @brief Removes a specific plant from this order and returns it to inventory or stock.
     * @param item Pointer to the plant to remove.
     * @param inv Pointer to the Inventory where the plant can be returned.
     * @param stock Pointer to the Stock where the plant can be returned.
     */
    void removePlant(Plant* item, Inventory* inv, Stock* stock);

    /**
     * @brief Removes a specific plant from this order without returning it to any storage.
     * @param item Pointer to the plant to remove.
     */
    void removePlant(Plant* item);

    /**
     * @brief Retrieves all plants currently in this order.
     * @return A vector of pointers to all Plant objects in this order.
     */
    vector<Plant*> getOrderItems();

    /**
     * @brief Calculates the total cost of all plants and decorations in the order.
     * @return The calculated total cost as a double.
     */
    double calculateTotal();

    /**
     * @brief Creates an iterator for traversing the order’s plants.
     * @return Pointer to a newly created OrderIterator.
     */
    OrderIterator* createIterator();

    /**
     * @brief Gets the total cached value of this order.
     * @return Total value as a double.
     */
    double getTotal();

    /**
     * @brief Retrieves the name of the current order state.
     * @return A string containing the state's name (e.g., "Draft", "Submitted").
     */
    string getStateName();

    /**
     * @brief Returns the current OrderState object.
     * @return Pointer to the current OrderState.
     */
    OrderState* getState();

    /**
     * @brief Sets the order’s state to a new one.
     * @param state Pointer to the new OrderState object.
     */
    void setState(OrderState* state);

    /**
     * @brief Retrieves the unique identifier for this order.
     * @return Reference to the order ID string.
     */
    string& getId();

    /**
     * @brief Prints details of the order, including plants and total value.
     */
    void print();

    /**
     * @brief Returns the root node of the order’s plant tree.
     * @return Pointer to the root PlantNode.
     */
    PlantNode* getNode();

    /**
     * @brief Decorates a plant with a specific type of pot.
     * @param p Unique pointer to the plant to decorate.
     * @param potType Type of pot to apply (e.g., "Clay", "Ceramic").
     * @return A new unique pointer to the decorated plant.
     */
    static unique_ptr<Plant> decorateWithPot(unique_ptr<Plant> p, const string& potType);

    /**
     * @brief Decorates a plant with a specific type of fertilizer.
     * @param p Unique pointer to the plant to decorate.
     * @param fertilizerType Type of fertilizer to apply (e.g., "Organic", "Liquid").
     * @return A new unique pointer to the decorated plant.
     */
    static unique_ptr<Plant> decorateWithFertilizer(unique_ptr<Plant> p, const string& fertilizerType);

    /**
     * @brief Decorates a plant with a clay pot.
     * @param p Unique pointer to the plant to decorate.
     * @return Decorated plant wrapped with a clay pot.
     */
    static unique_ptr<Plant> decorateWithClayPot(unique_ptr<Plant> p) {
        return decorateWithPot(std::move(p), "Clay");
    }

    /**
     * @brief Decorates a plant with a ceramic pot.
     * @param p Unique pointer to the plant to decorate.
     * @return Decorated plant wrapped with a ceramic pot.
     */
    static unique_ptr<Plant> decorateWithCeramicPot(unique_ptr<Plant> p) {
        return decorateWithPot(std::move(p), "Ceramic");
    }

    /**
     * @brief Decorates a plant with organic fertilizer.
     * @param p Unique pointer to the plant to decorate.
     * @return Decorated plant with organic fertilizer applied.
     */
    static unique_ptr<Plant> decorateWithOrganicFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Organic");
    }

    /**
     * @brief Decorates a plant with liquid fertilizer.
     * @param p Unique pointer to the plant to decorate.
     * @return Decorated plant with liquid fertilizer applied.
     */
    static unique_ptr<Plant> decorateWithLiquidFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Liquid");
    }

    /**
     * @brief Decorates a plant with slow-release fertilizer.
     * @param p Unique pointer to the plant to decorate.
     * @return Decorated plant with slow-release fertilizer applied.
     */
    static unique_ptr<Plant> decorateWithSlowReleaseFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Slow-Release");
    }

    /**
     * @brief Restores the plant to its previous state.
     */
    void restoreToPreviousState();
};

#endif