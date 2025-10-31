/**
 * @file ConcreteCommMediator.h
 * @brief Concrete implementation of the communication mediator.
 * 
 * The ConcreteCommMediator coordinates communication between staff members
 * and customers by maintaining registries and routing messages appropriately.
 * It implements the actual logic for staff assignment and message routing.
 */

#ifndef CONCRETECOMMMEDIATOR_H
#define CONCRETECOMMMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "CommMediator.h"
#include "StaffMember.h"
#include "Customer.h"

using namespace std;

/**
 * @class ConcreteCommMediator
 * @brief Concrete mediator implementation for customer-staff communication.
 * 
 * This class maintains registries of all staff members and customers,
 * manages staff availability, handles customer-staff assignments,
 * and routes messages between colleagues. It implements the core
 * coordination logic for the nursery communication system.
 */
class ConcreteCommMediator : public CommMediator {
private:
    vector<StaffMember *> allStaff;           ///< All registered staff members in the nursery
    vector<StaffMember *> availableStaff;     ///< Currently available staff members
    vector<Customer *> registeredCustomers;   ///< All registered customers
    map<Customer *, StaffMember *> assignments; ///< Customer-staff assignment mappings

public:
    /**
     * @brief Notify staff about a customer query or request.
     * @param customer The customer making the request.
     * @param query The customer's question or request text.
     * @param plant Optional plant related to the query.
     * 
     * Routes customer queries to available staff members. If the customer
     * already has an assigned staff member, the query goes to them.
     * Otherwise, it finds an available staff member and creates an assignment.
     */
    void notifyStaff(Customer *customer, const string &query, Plant *plant = nullptr) override;

    /**
     * @brief Notify customer about staff response.
     * @param staff The staff member providing the response.
     * @param customer The customer to receive the response.
     * @param response The staff's response message.
     * @param plant Optional plant related to the response.
     * 
     * Delivers staff responses to customers through the mediator,
     * ensuring proper message routing and maintaining communication history.
     */
    void notifyCustomer(StaffMember *staff, Customer *customer, const string &response, Plant *plant = nullptr) override;

    /**
     * @brief Add a staff member to the communication system.
     * @param staff Pointer to the staff member to register.
     * 
     * Adds staff to internal registry if not already present.
     * Prevents duplicate registrations and maintains staff availability lists.
     */
    void addStaff(StaffMember *staff) override;

    /**
     * @brief Add a customer to the communication system.
     * @param customer Pointer to the customer to register.
     * 
     * Adds customer to internal registry if not already present.
     * Prevents duplicate registrations and enables customer tracking.
     */
    void addCustomer(Customer *customer) override;

    /**
     * @brief Assign a specific staff member to help a customer.
     * @param staff Staff member to assign.
     * @param customer Customer to be helped.
     * 
     * Creates a direct assignment between a staff member and customer
     * for ongoing assistance and personalized service.
     */
    void assignStaffToCustomer(StaffMember *staff, Customer *customer);

    /**
     * @brief Get staff assigned to a customer.
     * @param customer The customer to check.
     * @return Pointer to assigned staff member, or nullptr if no assignment exists.
     */
    StaffMember *getAssignedStaff(Customer *customer) const;
};

#endif