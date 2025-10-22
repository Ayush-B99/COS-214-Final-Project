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
	void submitted(Order* order);

	void paid(Order* order);

	void cancelled(Order* order);

	void completed(Order* order);

	const string getName();

	bool canEdit();

	bool canCancel();
};

#endif
