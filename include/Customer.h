#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Customer {


public:
	virtual double getDiscount() = 0;

	~Customer();
};

#endif
