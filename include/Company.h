#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Customer.h"

using namespace std;

class Company :public Customer {

public:
	vector<Customer*> customers;

	virtual double getDiscount();

	void addCustomer(Customer* c);

	void removeCustomer(Customer* c);
};

#endif
