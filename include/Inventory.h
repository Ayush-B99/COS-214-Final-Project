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
#include "TemperatePlantFactory.h"
#include "TropicalPlantFactory.h"
#include "SucculentPlantFactory.h"
#include "CarnivorousPlantFactory.h"
#include "InventoryIterator.h"
#include "GrowthState.h"
#include "HealthState.h"
#include "Mature.h"
#include "Dead.h"

/**
 * @class Inventory
 * @brief Implements bst based storage for all plants that cannot be sold yet.
 * 
 * Also provides the user an interface for plant creation through its factories.
 * Automatically sorts and indexes plants that are added, and automatically moves them to the correct alternate structure when their conditions are met.
 */
class Inventory : public Storage {

private:

/**
 * @brief the root of the plantCatalog tree
 */
	PlantNode* plantCatalog;
/**
 * @brief stores all the greenhouses in a predetermined order, allows for easy access to them
 */
	vector<GreenHouse*> greenHouses;

	//helper functions for recursive operations
/**
 * @brief helper function for the printInventory method
 */
	void printHelper(PlantNode* node, string prefix, bool isLeft);

	PlantNode* removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

	PlantNode* removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

	void collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches);

    void collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches);

    void collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches);

public:
	Inventory();

	~Inventory();

	/**
	 * @brief simply adds a factory to the greenHouses vector
	 * @note i dont actually know why we have this, but i'm keeping it and calling it extensibility
	 */
	void setClimate(GreenHouse* factory);

	Plant* addSmallPlant(GreenHouse* house);

	Plant* addMediumPlant(GreenHouse* house);

	Plant* addLargePlant(GreenHouse* house);

	void addPlantPrototype(Plant* prototype);

	InventoryIterator* createIterator();

	int getPlantCount();

	GreenHouse* getTemperateFactory();

	GreenHouse* getCarnivorousFactory();

	GreenHouse* getSucculentFactory();

	GreenHouse* getTropicalFactory();

	void addPlant(Plant* plant);

	void removePlant(Plant* plant);

	vector<Plant*> removePlants(string key, GrowthState* state);

	vector<Plant*> removePlants(string key, HealthState* state);

	vector<Plant*> removePlants(GrowthState* state);

	vector<Plant*> removePlants(HealthState* state);

	/**
	 * @brief basically the same as getNode but returns the plants vector to make things easier
	 * @return a vector containing all of the plants under a given 
	 */
	vector<Plant*> getPlants(string key);

    vector<Plant*> getPlants(string key, GrowthState* state);

    vector<Plant*> getPlants(string key, HealthState* state);

    vector<Plant*> getPlants(GrowthState* state);

    vector<Plant*> getPlants(HealthState* state);

    vector<Plant*> getAllPlants();

	/**
	 * @brief essentially just a simplified removePlants wrapper. 
	 * moves plants that have matured to the stock pointer passed in, using the Storage interface to prevent weird dependencies.
	 * growth state needs to be mature to be moved
	 */
	void moveValidPlantsToStock(Storage* stock);

	/**
	 * @brief essentially just a simplified RemovePlants wrapper again.
	 * removes plants from the tree entirely, if their health state is dead.
	 */
	void cleanUpDeadPlants();

	/**
	 * @brief removes a node from the tree according to its key and returns it
	 * @return the node to be removed if found, otherwise a nullptr
	 */
	PlantNode* removeNode(PlantNode* root, string key);

	/**
	 * @brief will attempt to search for a node recursively, returning null if the node cannot be found
	 * @return a pointer to the node with the associated key, or null if not found
	 */
	PlantNode* findNode(PlantNode* root, string key);

	/**
	 * @brief adds a node with the specified key to the tree
	 */
	PlantNode* addNode(PlantNode* root, string key);

	/**
	 * @brief simple count of the number of nodes in the tree
	 */
	int getNodeCount();

	/**
	 * @brief prints a fancy looking representation of the tree structure, along with the contents of each node
	 */
	void printInventory();

	//getters and setters (only adding them as needed rn)

	PlantNode* getRoot();

};

#endif