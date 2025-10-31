#ifndef DRAFT_H
#define DRAFT_H

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
#include "Cancelled.h"
#include "Submitted.h"

class Draft : public OrderState {


public:
	Draft();

	void proceed(Order* order);

	void cancel(Order* order);

	string const getName();
};

#endif
