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
 * @brief Concrete implementation of the communication mediator
 * This class coordinates communication between staff members by maintaining a registry of all staff and routing messages appropriately.
 */

class ConcreteCommMediator : public CommMediator
{
private:
	vector<StaffMember *> allStaff; // these are basically all the registered stagff members in the nursery
	vector<StaffMember *> availableStaff;
	vector<Customer *> registeredCustomers;
	map<Customer *, StaffMember *> assignments;

public:
	void notifyStaff(Customer *customer, const string &query, Plant *plant = nullptr) override;
	/**
	 * @brief Notify the mediator about an event from a staff member class
	 * @param sender this is a pointer to the staff member who put the start to the event
	 * @param event String which desdcribes the event which had occurred
	 * @param plant Pointer to the plant related to the event (this can be nullptr)
	 */
	void notifyCustomer(StaffMember *staff, Customer *customer, const string &response, Plant *plant = nullptr) override;

	void addStaff(StaffMember *staff) override;
	/**
	 * @brief Add a staff member to the communication system
	 * @param staff Pointer to the staff member to add the staff member to the system
	 *
	 * This method:
	 * Adds staff to internal registry if not already present
	 * Prevents duplicate registrations and gives a proper feedback on the status of what has happened.
	 */
	void addCustomer(Customer *customer) override;
	/**
	 * @brief Add a customer to the communication system
	 * @param customer Pointer to the customer to add the customer to the system
	 *
	 * This method:
	 * Adds customer to internal registry if not already present
	 * Prevents duplicate registrations and gives a proper feedback on the status of what has happened.
	 */
	void assignStaffToCustomer(StaffMember *staff, Customer *customer);
	/**
	 * @brief Assign a specific staff member to help a customer
	 * @param staff Staff member to assign
	 * @param customer Customer to be helped
	 */
	StaffMember *getAssignedStaff(Customer *customer) const;
	/**
	 * @brief Get staff assigned to a customer
	 * @param customer The customer to check
	 * @return Pointer to assigned staff, or nullptr if none
	 */
};

#endif
