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
#include "Submitted.h"
#include "Draft.h"

class Inventory;
class Stock;

class Order : public Storage {

private:
	OrderState* state;
	PlantNode* orderItems;
	string id;
	double total;

public:
	Order(string orderId);

	~Order();

	void submitted();

	void paid();

	void cancelled();

	void completed();

	void addPlant(Plant* item);

	void removePlant(Plant* item, Inventory* inv, Stock* stock);

	void removePlant(Plant* item);

	vector<Plant*>& getOrderItems();

	double calculateTotal();

	OrderIterator* createIterator();

	double getTotal();

	string getStateName();

	OrderState* getState();

	void setState(OrderState* state);

	string& getId();

	void print();
};

#endif
