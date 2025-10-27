#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

// #include "CommMediator.h"
// #include "StaffMember.h"
// #include "Command.h"
// #include "ConcreteCommMediator.h"
// #include "Plant.h"
class CommMediator;
class StaffMember;
class Command;
class Plant;
using namespace std;
#include "CommMediator.h"
class Customer
{
private:
	string customerName;
	CommMediator *commMediator;
	vector<string> purchaseHistory;

public:
	Customer(const string &name, CommMediator *mediator = nullptr);
	/**
	 * @brief Construct a new Customer
	 * @param name Customer's name
	 * @param mediator Communication mediator (optional)
	 */

	string getName() const;
	/**
	 * @brief Get the customer's name
	 * @return Customer's name
	 */

	void setCommMediator(CommMediator *mediator);
	/**
	 * @brief Set the communication mediator
	 * @param mediator Pointer to communication mediator
	 */
	void askQuestion(const string &question, Plant *plant = nullptr);
	/**
	 * @brief Customer asks a question via the mediator
	 * @param question The customer's question
	 * @param plant Optional plant related to the question
	 */
	void requestAssistance();
	/**
	 * @brief Customer requests assistance via the mediator
	 */
	void requestPurchase(const string &plantType, int quantity = 1);
	/**
	 * @brief Customer requests to purchase plants via the mediator
	 * @param plantType The type of plant to purchase
	 * @param quantity Number of plants to purchase (default is 1)
	 */
	void receiveResponse(const string &response, Plant *plant = nullptr);
	/**
	 * @brief Receive a response from staff via the mediator
	 * @param response The staff's response message
	 * @param plant Optional plant related to the response
	 */
	vector<string> getPurchaseHistory() const;
	/**
	 * @brief Get the customer's purchase history
	 * @return Vector of strings representing past purchases
	 */

	virtual double getDiscount() { return 0.0; }

	// TODO: implement functions for commMediator design pattern

	virtual ~Customer();
};

#endif
