#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Storage.h"
#include "Plant.h"
#include "PlantNode.h"
#include "GreenHouse.h"
#include "InventoryIterator.h"

class Inventory : public Storage {

private:
	PlantNode* plantCatalog;
	vector<GreenHouse*> greenHouse;

public:
	Inventory();

	~Inventory();

	void setClimate(GreenHouse* factory);

	Plant* addSmallPlant(GreenHouse* type);

	Plant* addMediumPlant(GreenHouse* type);

	Plant* addLargePlant(GreenHouse* type);

	void addPlantPrototype(Plant* prototype);

	InventoryIterator* createIterator();

	int getPlantCount();

	const GreenHouse* getTemperateFactory();

	const GreenHouse* getCarnivorousFactory();

	const GreenHouse* getSucculentFactory();

	const GreenHouse* getTropicalFactory();

	void addPlant(Plant* plant);

	void removePlant(Plant* plant);

	Plant* findPlant(string key, string growthStage);

	bool removeNode(string key);

	PlantNode* findNode(string key);

	PlantNode* addNode(string key);

	int getNodeCount();

	void printInventory();
};

#endif
