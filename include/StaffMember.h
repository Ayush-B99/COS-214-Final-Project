/**
 * @file StaffMember.h
 * @brief Abstract base class for all staff members in the nursery.
 * 
 * StaffMember represents the "Colleague" in the Mediator pattern.
 * Staff members know about the mediator but not about other staff members directly.
 * All communication happens through the commMediator to maintain loose coupling.
 */

#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

// Forward declarations
class GrowthMediator;
class CommMediator;
class Command;
class Customer;
class Plant;
class Inventory;

#include "CommMediator.h"
#include "Customer.h"

/**
 * @class StaffMember
 * @brief Abstract colleague class representing nursery staff members.
 * 
 * This class serves as the base for all staff types (Worker, Manager, etc.).
 * Staff members communicate through the mediator rather than directly with
 * each other or customers, reducing dependencies and centralizing communication logic.
 */
class StaffMember {
private:
    GrowthMediator *mediator;           ///< Growth mediator for plant-related coordination
    vector<Plant *> currentState;       ///< Current plants being handled
    vector<Command *> commandHistory;   ///< History of commands executed
    CommMediator *commMediator;         ///< Communication mediator for customer interactions
    string staffName;                   ///< Name of the staff member
    bool isAvailable;                   ///< Availability status for customer assistance
    Inventory* inventory;               ///< Inventory system reference

protected:
    /**
     * @brief Get the staff member's name.
     * @return Constant reference to the staff name string.
     */
    const string &getStaffName() const { return staffName; }
    
    /**
     * @brief Set the staff member's name.
     * @param name New name for the staff member.
     */
    void setStaffName(const string &name) {
        if (!name.empty())
            staffName = name;
    }

    /**
     * @brief Get the inventory system pointer.
     * @return Pointer to the inventory system.
     */
    Inventory* getInventory() const { return inventory; }

public:
    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~StaffMember() = default;

    /**
     * @brief Construct a new Staff Member with automatic mediator registration.
     * @param name The staff member's name.
     * @param mediator Pointer to the communication mediator (optional).
     * @param inventory Pointer to the inventory system (optional).
     * 
     * If a mediator is provided during construction, the staff member
     * automatically registers itself with that mediator, enabling
     * immediate participation in the communication system.
     */
    StaffMember(const string &name, CommMediator *mediator = nullptr, Inventory* inventory = nullptr);

    /**
     * @brief Set the communication mediator.
     * @param mediator Pointer to the communication mediator.
     */
    void setCommMediator(CommMediator *mediator);

    /**
     * @brief Set the inventory system.
     * @param inv Pointer to the inventory system.
     */
    void setInventory(Inventory* inv);

    /**
     * @brief Get the staff member's name.
     * @return String containing the staff member's name.
     */
    virtual string getName() const;

    /**
     * @brief Check if staff is available for customer assistance.
     * @return true if available, false otherwise.
     */
    bool getAvailability() const;

    /**
     * @brief Set staff availability for customer assistance.
     * @param available New availability status.
     */
    void setAvailability(bool available);

    /**
     * @brief Handle customer query (pure virtual - must be implemented by derived classes).
     * @param customer The customer asking the question.
     * @param query The customer's question.
     * @param plant Optional plant related to the query.
     */
    virtual void handleCustomerQuery(Customer *customer, const string &query, Plant *plant = nullptr) = 0;

    /**
     * @brief Handle customer purchase request (pure virtual - must be implemented by derived classes).
     * @param customer The customer making the purchase request.
     * @param plantType The type of plant requested.
     * @param quantity Number of plants requested.
     */
    virtual void handlePurchaseRequest(Customer *customer, const string &plantType, int quantity) = 0;

    /**
     * @brief Send a response to a customer via the mediator.
     * @param customer The customer to respond to.
     * @param response The response message.
     * @param plant Optional plant related to the response.
     */
    void respondToCustomer(Customer *customer, const string &response, Plant *plant = nullptr);
};

#endif