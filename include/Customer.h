/**
 * @file Customer.h
 * @brief Customer class representing nursery customers.
 * 
 * Customers are colleagues in the Mediator pattern who communicate with
 * staff members through the mediator rather than directly. They can ask
 * questions, request assistance, and make purchases through the mediator.
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
 * @brief Concrete colleague class representing nursery customers.
 * 
 * Customers interact with the nursery system through the communication mediator.
 * They can ask questions, request assistance, make purchases, and receive
 * responses from staff members without knowing which specific staff member
 * handles their request.
 */
class Customer {
private:
    string customerName;                ///< Customer's name
    CommMediator* commMediator;         ///< Communication mediator for staff interactions
    vector<string> purchaseHistory;     ///< History of purchases made by the customer

public:
    /**
     * @brief Construct a new Customer.
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
     * @brief Get customer discount rate (virtual for potential loyalty programs).
     * @return Discount rate as a decimal (0.0 for base customers).
     */
    virtual double getDiscount() { return 0.0; }

    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~Customer();
};

#endif