#ifndef PAID_H
#define PAID_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "OrderState.h"
#include "Cancelled.h"
#include "Completed.h"

class Paid : public  OrderState {


public:
	Paid();
	
	void proceed(Order* order);

	void cancel(Order* order);

	string const getName();
};

#endif
