#ifndef COMMMEDIATOR_H
#define COMMMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class StaffMember;
class Customer;
class Plant;

/**
 * @class CommMediator
 * @brief Mediator for handling communication between customers and staff members
 * 
 * This mediator specifically handles customer-related communications:
 * - Customer queries and requests
 * - Staff responses to customers  
 * - Customer purchase requests
 * - Staff assistance coordination for customers
 * 
 * It decouples customers from direct staff dependencies and provides
 * centralized routing of customer-staff interactions.
 */

class CommMediator 
{

public:
	virtual ~CommMediator() = default;
	/**
 	* @brief Destructor for CommMediator
 	* Clean up any resources used by the mediator.
 	* Currently implemented as default since this is an abstract class.
 	*/

	
    virtual void notifyStaff(Customer* customer, const string& query, Plant* plant = nullptr) = 0;
    /**
     * @brief Notify staff about a customer query or request
     * @param customer The customer making the request
     * @param query The customer's question or request
     * @param plant Optional plant related to the query
     */

	virtual void notifyCustomer(StaffMember* staff, Customer* customer, const string& response, Plant* plant = nullptr) = 0;
	/**
     * @brief Notify customer about staff response
     * @param staff The staff member responding
     * @param customer The customer to notify
     * @param response The staff's response message
     * @param plant Optional plant related to the response
     */

	
    virtual void addStaff(StaffMember* staff) = 0;
	  /**
     * @brief Add a staff member to the communication system
     * @param staff Pointer to the staff member to add the staff member to the system
     */

	 virtual void addCustomer(Customer* customer) = 0;
	  /**
	 * @brief Add a customer to the communication system
	 * @param customer Pointer to the customer to add the customer to the system
	 */

};


#endif
