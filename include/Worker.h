#ifndef WORKER_H
#define WORKER_H

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
 * @class Worker
 * @brief Concrete staff member responsible for plant care and customer assistance
 *
 * Workers are the frontline staff in the nursery. They handle:
 * - Daily plant care (watering, pest control)
 * - Customer assistance and guidance
 * - Basic maintenance tasks
 * - Reporting issues to managers
 *
 * In the Mediator pattern, Workers are ConcreteColleagues that communicate
 * through the mediator rather than directly with Managers or other Workers.
 */

class Worker : public StaffMember
{

public:
	Worker(const string &name, CommMediator *mediator = nullptr);
	/**
	 * @brief Construct a new Worker with automatic mediator registration
	 * @param name The worker's name
	 * @param mediator Pointer to the communication mediator (optional)
	 */

	void handleCustomerQuery(Customer *customer, const string &query, Plant *plant = nullptr) override;
	/**
	 * @brief Handle customer queries about plant care and basic information
	 */

	void handlePurchaseRequest(Customer *customer, const string &plantType, int quantity) override;
	/**
	 * @brief Handle customer purchase requests for plants
	 */

	void providePlantCareAdvice(Customer *customer, const string &plantType);
	void checkInventory(const string &plantType);

	//////////////////////so the stuff below was in the uml and um i have no idea what it is so im leaving it unimplemented for now - chinmayi//////////////////////
	// void getComm();

	// void setComm();
	////////////////////////////////////////////////////////////////////////////////

	// void getGrowth();

	// void setGrowth();
	void getComm() override {}
	void setComm() override {}
	void getGrowth(Plant *plant) override {}
	void setGrowth() override {}
};

#endif
