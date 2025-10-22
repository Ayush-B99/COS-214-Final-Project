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

#include "Plant.h"

class PlantDecorator : public Plant {

public:
	Plant* decoratedPlant;

	PlantDecorator(Plant* plant);

	virtual ~PlantDecorator();

	double getPrice();

	string getDescription();
};

#endif
