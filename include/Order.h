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
#include "PotDecorator.h"
#include "FertilizerDecorator.h"

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

	void proceed();

	void cancel(Inventory* inv, Stock* stock);

	void addPlant(Plant* item);

	void removePlant(Plant* item, Inventory* inv, Stock* stock);

	void removePlant(Plant* item);

	vector<Plant*> getOrderItems();

	double calculateTotal();

	OrderIterator* createIterator();

	double getTotal();

	string getStateName();

	OrderState* getState();

	void setState(OrderState* state);

	string& getId();

	void print();

	PlantNode* getNode();

    static unique_ptr<Plant> decorateWithPot(unique_ptr<Plant> p, const string& potType);
    static unique_ptr<Plant> decorateWithFertilizer(unique_ptr<Plant> p, const string& fertilizerType);

    //prebuilt decorators for testing
    static unique_ptr<Plant> decorateWithClayPot(unique_ptr<Plant> p) {
        return decorateWithPot(std::move(p), "Clay");
    }

    static unique_ptr<Plant> decorateWithCeramicPot(unique_ptr<Plant> p) {
        return decorateWithPot(std::move(p), "Ceramic");
    }

    static unique_ptr<Plant> decorateWithOrganicFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Organic");
    }

    static unique_ptr<Plant> decorateWithLiquidFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Liquid");
    }

    static unique_ptr<Plant> decorateWithSlowReleaseFertilizer(unique_ptr<Plant> p) {
        return decorateWithFertilizer(std::move(p), "Slow-Release");
    }
};

#endif
