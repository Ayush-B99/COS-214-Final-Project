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

/**
 * @class Stock
 * @brief A BST structure similar to Inventory. the main difference is that this structure only holds plants that are ready to be sold
 * 
 * Plants are stored as a shallow copy of items already in inventory, so Stock does not own any plants itself, rather it is simply an interface to view and access plants that already are owned by Inventory
 * Is the interface for addint plants to an Order.
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

	
public:

	Stock();

	~Stock();

	vector<Plant*> getLowStockItems();

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
};

#endif
