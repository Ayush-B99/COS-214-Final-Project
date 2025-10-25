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

class PlantNode
{

private:
	vector<Plant *> plants;
	string key;
	PlantNode *left;
	PlantNode *right;

public:
	PlantNode(string name);

	PlantNode(PlantNode *other);

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

	bool removeNode(string name);

	bool isLeaf();
};

#endif
