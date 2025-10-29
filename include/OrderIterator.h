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
	vector<Plant*> order;
	int position;

public:
	OrderIterator(PlantNode* order);

	~OrderIterator();

	Plant* next();

	Plant* currentPlant();

	bool hasNext();

	void reset();

	int getPosition();

	void setPosition(int index);

	bool hasPrevious();

	Plant* previous();
};

#endif
