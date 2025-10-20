#ifndef PREMIUM_H
#define PREMIUM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Customer.h"

using namespace std;

class Premium : public Customer {


public:
	double getDiscount();
};

#endif
