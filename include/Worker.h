/**
 * @file Worker.h
 * @brief Concrete staff member responsible for plant care and customer assistance.
 * 
 * Workers are frontline staff in the nursery who handle daily plant care,
 * customer assistance, basic maintenance, and inventory checking.
 * They communicate through the mediator rather than directly with managers or customers.
 */

#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "StaffMember.h"
#include "Inventory.h"

/**
 * @class Worker
 * @brief Concrete staff member for frontline nursery operations.
 * 
 * Workers handle:
 * - Daily plant care (watering, pest control)
 * - Customer assistance and guidance
 * - Basic maintenance tasks
 * - Reporting issues to managers
 * - Inventory checking and basic sales
 * 
 * In the Mediator pattern, Workers are ConcreteColleagues that communicate
 * through the mediator rather than directly with Managers or other Workers.
 */
class Worker : public StaffMember {
public:
    /**
     * @brief Construct a new Worker with automatic mediator registration.
     * @param name The worker's name.
     * @param mediator Pointer to the communication mediator (optional).
     * @param inventory Pointer to the inventory system (optional).
     */
    Worker(const string &name, CommMediator *mediator = nullptr, Inventory* inventory = nullptr);

    /**
     * @brief Handle customer queries about plant care and basic information.
     * @param customer The customer asking the question.
     * @param query The customer's question.
     * @param plant Optional plant related to the query.
     */
    void handleCustomerQuery(Customer *customer, const string &query, Plant *plant = nullptr) override;

    /**
     * @brief Handle customer purchase requests for plants.
     * @param customer The customer making the purchase request.
     * @param plantType The type of plant requested.
     * @param quantity Number of plants requested.
     */
    void handlePurchaseRequest(Customer *customer, const string &plantType, int quantity) override;

    /**
     * @brief Provide plant care advice to customers.
     * @param customer The customer receiving advice.
     * @param plantType The type of plant for care advice.
     */
    void providePlantCareAdvice(Customer *customer, const string &plantType);

    /**
     * @brief Check inventory for a specific plant type.
     * @param plantType The type of plant to check.
     */
    void checkInventory(const string &plantType);

    /**
     * @brief Check if a specific plant type is available in required quantity.
     * @param plantType The type of plant to check.
     * @param quantity The required quantity (default: 1).
     * @return true if available, false otherwise.
     */
    bool checkPlantAvailability(const string& plantType, int quantity = 1);

    /**
     * @brief Get the stock count for a specific plant type.
     * @param plantType The type of plant to check.
     * @return Number of available plants of the specified type.
     */
    int getPlantStockCount(const string& plantType);

    /**
     * @brief Get list of available plant types.
     * @return Vector of available plant type names.
     */
    vector<string> getAvailablePlantTypes();
};

#endif