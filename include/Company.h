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

class Company : Customer {

public:
	vector<Customers*> customers;

	void getDiscount();

	void addCustomer(Customer* c);

	void removeCustomer(Customer* c);
};

#endif
