#ifndef SUBMITTED_H
#define SUBMITTED_H

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
#include "Paid.h"
class Submitted : public OrderState {


public:
	Submitted();
	
	void proceed(Order* order);

	void cancel(Order* order);

	string const getName();
}; 

#endif
