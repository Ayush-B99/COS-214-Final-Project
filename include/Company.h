#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Customer.h"

class Company : public Customer {

public:
	Company(const string& name, CommMediator* mediator) : Customer(name, mediator) {}
	vector<Customer*> customers;
	~Company();

	double getDiscount();

	void addCustomer(Customer* c);

	void removeCustomer(Customer* c);
};

#endif