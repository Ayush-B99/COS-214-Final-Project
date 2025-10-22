#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "StockIterator.h"

class Stock : public Storage {

private:
	PlantNode* stockCatalog;
	PlantNode* state;

public:
	Stock();

	~Stock();

	vector<Plant*> getLowStockItems();

	bool needsRestock(Plant* plant);

	double getTotalStockValue();

	string generateStockReport();

	// possible fix -> InventoryIterator* return type
	StockIterator* createIterator();

	void addPlant(Plant* plant);

	void removePlant(Plant* plant);

	Plant* findPlant(string key, string growthStage);

	PlantNode* findNode(string key);

	PlantNode* addNode(string key);

	int getNodeCount();

	void printStock();
};

#endif
