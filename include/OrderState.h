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

	virtual void proceed(Order* order) = 0;

	virtual void cancel(Order* order) = 0;

	virtual string const getName() = 0;
};

#endif