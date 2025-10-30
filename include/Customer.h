/**
 * @file Customer.h
 * @brief Abstract component in the Composite pattern for customer hierarchy.
 * 
 * Customer serves as the Component interface in the Composite pattern, defining
 * common operations for both individual customers (leaves) and customer groups (composites).
 * It also functions as a Colleague in the Mediator pattern for communication.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

// Forward declarations
class CommMediator;
class StaffMember;
class Command;
class Plant;

using namespace std;

#include "CommMediator.h"

/**
 * @class Customer
 * @brief Abstract component interface in the Composite pattern.
 * 
 * This class defines the common interface for all customer types in the
 * customer hierarchy. It supports both individual customers (Normal, Premium)
 * and composite customer groups (Company) through the Composite pattern.
 * 
 * As a Component, it declares operations that are applicable to both
 * individual customers and customer composites, enabling uniform treatment
 * of simple and complex customer structures.
 */
class Customer {
private:
    string customerName;                ///< Customer's name
    CommMediator* commMediator;         ///< Communication mediator for staff interactions
    vector<string> purchaseHistory;     ///< History of purchases made by the customer

public:
    /**
     * @brief Construct a new Customer component.
     * @param name Customer's name.
     * @param mediator Communication mediator (optional).
     */
    Customer(const string& name, CommMediator* mediator = nullptr);

    /**
     * @brief Get the customer's name.
     * @return Customer's name.
     */
    string getName() const;
    
    /**
     * @brief Set the communication mediator.
     * @param mediator Pointer to communication mediator.
     */
    void setCommMediator(CommMediator* mediator);

    /**
     * @brief Customer asks a question via the mediator.
     * @param question The customer's question.
     * @param plant Optional plant related to the question.
     */
    void askQuestion(const string& question, Plant* plant = nullptr);

    /**
     * @brief Customer requests assistance via the mediator.
     */
    void requestAssistance();

    /**
     * @brief Customer requests to purchase plants via the mediator.
     * @param plantType The type of plant to purchase.
     * @param quantity Number of plants to purchase (default is 1).
     */
    void requestPurchase(const string& plantType, int quantity = 1);

    /**
     * @brief Receive a response from staff via the mediator.
     * @param response The staff's response message.
     * @param plant Optional plant related to the response.
     */
    void receiveResponse(const string& response, Plant* plant = nullptr);

    /**
     * @brief Get the customer's purchase history.
     * @return Vector of strings representing past purchases.
     */
    vector<string> getPurchaseHistory() const;

    /**
     * @brief Get customer discount rate (Component operation).
     * @return Discount rate as a decimal.
     * 
     * This is a key Composite pattern operation that must be implemented
     * by all concrete components (both leaves and composites).
     */
    virtual double getDiscount() { return 0.0; }

    /**
     * @brief Virtual destructor for proper cleanup in derived components.
     */
    virtual ~Customer();
};

#endif