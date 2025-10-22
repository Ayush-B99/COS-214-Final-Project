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

class Submitted : OrderState {


public:
	void submitted(Order* order);

	void paid(Order* order);

	void cancelled(Order* order);

	void completed(Order* order);

	string getName();

	bool canEdit();

	bool canCancel();
};

#endif
