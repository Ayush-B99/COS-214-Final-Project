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

class InventoryIterator : public Iterator {

private:
	PlantNode* root;
	map<PlantNode*, size_t> current;
	stack<PlantNode*> nodeStack;

public:
	InventoryIterator(PlantNode* root);

	~InventoryIterator();

	Plant* next();

	Plant* current();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void pushLeft(PlantNode* node);

	Plant* nextFine();

	PlantNode* nextCoarse();

	// error here -> too few arguments for class template "std::__1::map"
	void setPosition(map<PlantNode*> pos);
};

#endif
