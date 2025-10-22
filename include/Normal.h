#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Customer.h"

using namespace std;

class Normal :public Customer {


public:
	double getDiscount();
};

#endif
