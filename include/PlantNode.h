#ifndef PLANTNODE_H
#define PLANTNODE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"
#include "GrowthState.h"
#include "HealthState.h"

/**
 * @class PlantNode
 * @brief Basic structure to make up inventory BSTs and orders 
 * 
 * stores a vector of plants, which can either be random, or, more conventionally 
 * belong to some sort of 'group' indicated by the key field.
 * allows the class to be used both for logical groupings of plants,
 * or simple collections of plants, such as an order
 */
class PlantNode
{

private:
	/**
	 * @brief vector of dynamic plants, 
	 */
	vector<Plant*> plants;
	string key;
	PlantNode* left;
	PlantNode* right;

public:
	PlantNode(string name);

	PlantNode(PlantNode *other);

	/**
	 * @brief destructor for the PlantNode.
	 * @note assumes that the node owns the plants stored inside, meaning that it will delete all plants in its vector. 
	 * change if this causes seg faults, the idea is that this is easiest since we wont be calling this destructor very often.
	 */
	~PlantNode();

	const string getKey();

	vector<Plant *> getPlants();

	PlantNode *getLeft();

	PlantNode *getRight();

	void setLeft(PlantNode *left);

	void setRight(PlantNode *right);

	void addPlant(Plant *plant);

	void addPlants(vector<Plant *> newPlants);

	bool removePlant(Plant *plant);

	vector<Plant*> removeByGrowthState(GrowthState* state);

	vector<Plant*> removeByHealthState(HealthState* state);

	bool isLeaf();

	bool plantInNode(Plant* plant);

	void printNode(string prefix, bool isLeft);
};

#endif
