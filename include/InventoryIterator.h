#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Iterator.h"
#include "PlantNode.h"

/**
 * @class InventoryIterator
 * 
 * 
 */
class InventoryIterator : public Iterator
{

private:
	PlantNode *root;
	PlantNode* currentNode;
	size_t indexInNode;
	stack<PlantNode *> nodeStack;

public:
	InventoryIterator(PlantNode *root);

	~InventoryIterator();

	Plant* next();

	Plant* nextFine();

	Plant* nextCoarse();

	Plant* currentPlant();

	bool hasNext();

	bool hasNextNode();

	void reset();
	
	void pushLeft(PlantNode *node);
	
	map<PlantNode*, int> getPosition();
	
	void setPosition(map<PlantNode*, int>& pos);
};

#endif