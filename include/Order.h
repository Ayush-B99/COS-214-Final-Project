#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "OrderState.h"
#include "PlantNode.h"
#include "Plant.h"
#include "OrderIterator.h"

class Order : public Storage {

private:
	OrderState* state;
	PlantNode* orderItems;
	string id;
	double total;

public:
	Order(string& orderId);

	~Order();

	void submitted();

	void paid();

	void cancelled();

	void completed();

	void addItem(Plant* item);

	void removeItem(Plant* item);

	vector<Plant*>& getOrderItems();

	double calculateTotal();

	// possible fix -> InventoryIterator* return type
	Iterator* createIterator();

	double getTotal();

	string getStateName();

	OrderState* getState();

	void setState(OrderState* state);

	string& getId();
};

#endif
