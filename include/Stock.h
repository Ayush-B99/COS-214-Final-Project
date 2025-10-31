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
#include "HealthState.h"
#include "GrowthState.h"
#include "Dead.h"

//forward declarations
class Inventory;
class Order;

/**
 * @class Stock
 * @brief A BST structure similar to Inventory. Holds plants that are ready to be sold.
 * 
 * Stock NOW OWNS the plants it contains (not shallow copies). Plants are moved from 
 * Inventory to Stock, transferring ownership.
 */
class Stock : public Storage {

private:
	PlantNode* stockCatalog;

	void printHelper(PlantNode* node, string prefix, bool isLeft);

	PlantNode* removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

	PlantNode* removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    void collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

	void collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    void collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches);

	int countNodesRecursive(PlantNode* node);

	int countPlantsRecursive(PlantNode* node);
	
	double calculateValueRecursive(PlantNode* node);

	
public:

	Stock();

	~Stock();

	void getLowStockItems();

	double getTotalStockValue();

	StockIterator* createIterator();

	void addPlant(Plant* plant);

	void removePlant(Plant* plant);

	PlantNode* findNode(PlantNode* root, string key);

	PlantNode* addNode(PlantNode* root, string key);

	vector<Plant*> removePlants(string key, GrowthState* state);

	vector<Plant*> removePlants(string key, HealthState* state);

	vector<Plant*> removePlants(GrowthState* state);

	vector<Plant*> removePlants(HealthState* state);

	vector<Plant*> getPlants(string key);

    vector<Plant*> getPlants(string key, GrowthState* state);

    vector<Plant*> getPlants(string key, HealthState* state);

    vector<Plant*> getPlants(GrowthState* state);

    vector<Plant*> getPlants(HealthState* state);

    vector<Plant*> getAllPlants();

	PlantNode* removeNode(PlantNode* root, string key);

	void cleanUpDeadPlants();

	int getNodeCount();

	int getPlantCount();

	void print();

	PlantNode* getRoot();

	void moveToOrder(Plant* plant, Order* order);

	bool plantInTree(Plant* plant);
};

#endif