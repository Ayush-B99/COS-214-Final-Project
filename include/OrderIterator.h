#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H

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
#include "Plant.h"

class OrderIterator : public Iterator {

private:
	PlantNode* order;
	int position;

public:
	OrderIterator(PlantNode* order);

	~OrderIterator();

	// possible fix -> Plant* return type
	Plant* next();

	// possible fix -> Plant* return type
	Plant* currentPlant();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void setPosition(size_t index);
};

#endif
