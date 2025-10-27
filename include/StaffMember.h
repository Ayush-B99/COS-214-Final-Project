#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

// #include "GrowthMediator.h"
// //#include "CommMediator.h"
// //#include "Plant.h"
// #include "Command.h"
// #include "CommMediator.h"
// #include "Customer.h"
class GrowthMediator;
class CommMediator;
class Command;
class Customer;
class Plant;

#include "CommMediator.h"
#include "Customer.h"


/**
 * @class StaffMember
 * @brief Abstract base class for all staff members in the nursery
 * The class basically represents the "Colleague" in the Mediator pattern.
 * the staff members knows about the mediator but not about other staff members directly which was the ewhole point.
 * all the communication happens through the commMediator to the staffs.
 */



using namespace std;

class CommMediator;

class StaffMember {

private:
	GrowthMediator* mediator;
	vector<Plant*> currentState;
	vector<Command*> commandHistory;
	CommMediator* commMediator;
	string staffName;
	bool isAvailable; 

protected:
    const string& getStaffName() const { return staffName; }
    void setStaffName(const string& name) 
	{ 
        if (!name.empty()) staffName = name; 
    }

public:
	virtual ~StaffMember() = default;//note that the destructor was added by me(chinmayi)...@jaitin, change if needed man

	StaffMember(const string& name, CommMediator* mediator = nullptr);//constructor addedddd
	/**
     * @brief Construct a new Staff Member with automatic mediator registration
     * @param name The staff member's name
     * @param mediator Pointer to the communication mediator (optional)
     * 
     * If a mediator is provided during construction, the staff member
     * automatically registers itself with that mediator. This ensures
     * they can immediately participate in the communication system.
     */

	void setCommMediator(CommMediator* mediator);


	virtual string getName() const;
	/**
     * @brief Get the staff member's name
     * @return String containing the staff member's name
    */

    bool getAvailability() const;
	 /**
     * @brief Check if staff is available for customer assistance
     * @return true if available, false otherwise
     */

    void setAvailability(bool available);
	 /**
     * @brief Set staff availability for customer assistance
     * @param available New availability status
     */

	virtual void handleCustomerQuery(Customer* customer, const string& query, Plant* plant = nullptr) = 0;
	/**
     * @brief Handle customer query (pure virtual - must be implemented by derived classes)
     * @param customer The customer asking the question
     * @param query The customer's question
     * @param plant Optional plant related to the query
     */

    virtual void handlePurchaseRequest(Customer* customer, const string& plantType, int quantity) = 0;
	/**
	 * @brief Handle customer purchase request (pure virtual - must be implemented by derived classes)
	 * @param customer The customer making the purchase request
	 * @param plantType The type of plant requested
	 * @param quantity Number of plants requested
	 */
	void respondToCustomer(Customer* customer, const string& response, Plant* plant = nullptr);
	/**
	 * @brief Send a response to a customer via the mediator
	 * @param customer The customer to respond to
	 * @param response The response message
	 * @param plant Optional plant related to the response
	*/



    
	/////////////////////////////////////////////////not my stuff below this line - chinmayi//////////////////////////////////////////////////////
	void setMediator(GrowthMediator* mediator);

	void setCommand(Command* cmd);

	void executeCommand();

	void undoLastCommand();

	virtual void getComm() = 0;

	virtual void setComm() = 0;

	virtual void getGrowth() = 0;

	virtual void setGrowth() = 0;
};

#endif
