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
/**
 * @class Manager
 * @brief Concrete staff member responsible for oversight and coordination
 *
 * Managers handle higher-level nursery operations:
 * - Inventory management and ordering
 * - Staff coordination and assignment
 * - Scheduling and maintenance planning
 * - Problem escalation and resolution
 *
 * In the Mediator pattern, Managers are ConcreteColleagues that receive
 * notifications from Workers and provide strategic direction.
 */

class Manager : public StaffMember
{

public:
    Manager(const string &name, CommMediator *mediator = nullptr);
    /**
     * @brief Construct a new Manager with automatic mediator registration
     * @param name The manager's name
     * @param mediator Pointer to the communication mediator (optional)
     */
    void handleCustomerQuery(Customer *customer, const string &query, Plant *plant = nullptr) override;
    /**
     * @brief Handle complex customer queries and special requests
     */
    void handlePurchaseRequest(Customer *customer, const string &plantType, int quantity) override;
    /**
     * @brief Process bulk purchases and special orders
     */

    //////////////////////so the stuff below was in the uml and um i have no idea what it is so im leaving it unimplemented for now - chinmayi//////////////////////

    // getters returning void?
    void getComm() override {}
    void setComm() override {}
    void getGrowth(Plant *plant) override {}
    void setGrowth() override {}
};
#endif
