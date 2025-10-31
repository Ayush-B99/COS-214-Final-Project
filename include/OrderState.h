#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Order;

class OrderState {


public:
	virtual ~OrderState();

	virtual void submitted(Order* order) = 0;

	virtual void paid(Order* order) = 0;

	virtual void cancelled(Order* order) = 0;

	virtual void completed(Order* order) = 0;

	virtual string const getName() = 0;

	virtual bool canEdit() = 0;

	virtual bool canCancel() = 0;
};

#endif