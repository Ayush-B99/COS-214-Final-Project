#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class PlantDecorator : Plant {

public:
	Plant* decoratedPlant;

	PlantDecorator(Plant* plant);

	virtual ~PlantDecorator();

	double getPrice();

	string getDescription();
};

#endif
