#ifndef STOCKITERATOR_H
#define STOCKITERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Iterator.h"
#include "Plant.h"
#include "PlantNode.h"	

class StockIterator : public Iterator {

private:
	PlantNode *root;
	PlantNode* currentNode;
	size_t indexInNode;
	stack<PlantNode *> nodeStack;

public:
	StockIterator(PlantNode* root);

	~StockIterator();

	Plant* next();

	Plant* nextFine();

	PlantNode* nextCoarse();

	Plant* currentPlant(); // TODO: fix uml function name

	bool hasNext();

	bool hasNextNode();

	void reset();

	void pushLeft(PlantNode *node);
	
	map<PlantNode*, int> getPosition();
	
	void setPosition(map<PlantNode*, int>& pos);
};

#endif