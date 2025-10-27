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

	Plant* currentPlant(); // TODO: fix uml function name

	bool hasNext();

	bool hasNextNode();

	void reset();

	map<PlantNode*, int> getPosition();

	void pushLeft(PlantNode *node);

	Plant* nextFine();

	Plant* nextCoarse();

	void setPosition(map<PlantNode*, int>& pos);
};

#endif
