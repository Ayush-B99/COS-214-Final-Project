#ifndef COMPLETED_H
#define COMPLETED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "OrderState.h"
#include "Order.h"

class Completed : public OrderState {


public:
	Completed();
	
	void proceed(Order* order);

	void cancel(Order* order);

	string const getName();
};

#endif
