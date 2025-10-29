#ifndef CANCELLED_H
#define CANCELLED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Order.h"
#include "OrderState.h"

class Cancelled : public OrderState {


public:
	Cancelled();
	
	void proceed(Order* order);

	void cancel(Order* order);

	string const getName();
};

#endif
