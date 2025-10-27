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
	PlantNode* root;
	map<PlantNode*, size_t> current;
	stack<PlantNode*> nodeStack;

public:
	StockIterator(PlantNode* root);

	~StockIterator();

	Plant* next();

	Plant* currentPlant();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void pushLeft(PlantNode* node);

	Plant* nextFine();

	PlantNode* nextCoarse();

	void setPosition(map<PlantNode*, size_t> pos);
};

#endif
