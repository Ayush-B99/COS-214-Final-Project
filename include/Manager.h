#ifndef MANAGER_H
#define MANAGER_H

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
 * @class Manager
 * @brief Concrete staff member responsible for oversight and coordination
 *
 * Managers handle higher-level nursery operations:
 * - Inventory management and ordering
 * - Staff coordination and assignment
 * - Scheduling and maintenance planning
 * - Problem escalation and resolution
 * - Bulk order processing and special requests
 *
 * In the Mediator pattern, Managers are ConcreteColleagues that receive
 * notifications from Workers and provide strategic direction.
 */
class Manager : public StaffMember
{
public:
    /**
     * @brief Construct a new Manager with automatic mediator registration
     * @param name The manager's name
     * @param mediator Pointer to the communication mediator (optional)
     * @param inventory Pointer to the inventory system (optional)
     */
    Manager(const string &name, CommMediator *mediator = nullptr, Inventory* inventory = nullptr);

    /**
     * @brief Handle complex customer queries and special requests
     * @param customer The customer asking the question
     * @param query The customer's question
     * @param plant Optional plant related to the query
     */
    void handleCustomerQuery(Customer *customer, const string &query, Plant *plant = nullptr) override;

    /**
     * @brief Process bulk purchases and special orders
     * @param customer The customer making the purchase request
     * @param plantType The type of plant requested
     * @param quantity Number of plants requested
     */
    void handlePurchaseRequest(Customer *customer, const string &plantType, int quantity) override;

    

    /**
     * @brief Check overall inventory status and display information
     */
    void checkInventoryStatus();

    /**
     * @brief Get total plant count in inventory
     * @return Total number of plants in inventory
     */
    int getTotalPlantCount();

    //////////////////////////////////////////////////////////////////
    // Methods from original UML - implemented as empty for now
    //////////////////////////////////////////////////////////////////
    
   
    void getComm() override {}

    
    void setComm() override {}

    
    void getGrowth(Plant *plant) override {}

    
    void setGrowth() override {}
};

#endif