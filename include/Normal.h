#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Customer.h"

class Normal : public Customer {


public:
	double getDiscount();
};

#endif
