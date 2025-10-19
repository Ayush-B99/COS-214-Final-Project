#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory : Storage {

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

	const Greenhouse* getTemperateFactory();

	const Greenhouse* getCarnivorousFactory();

	const Greenhouse* getSucculentFactory();

	const Greenhouse* getTropicalFactory();

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
