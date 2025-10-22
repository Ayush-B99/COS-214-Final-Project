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

class Stock : Storage {

private:
	PlantNode* stockCatalog;
	PlantNode* state;

public:
	Stock();

	~Stock();

	vector<Plant*> getLowStockItems();

	bool needsRestock(Plant* plant);

	double getTotalStockValue();

	String generateStockReport();

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
