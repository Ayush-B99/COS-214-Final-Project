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
	//Plant* decoratedPlant;
	std::unique_ptr<Plant> decoratedPlant;

	//PlantDecorator(Plant* plant);
	PlantDecorator(std::unique_ptr<Plant> plant);

	//virtual ~PlantDecorator();

	double getPrice();

	string getDescription();

	virtual Plant* clone() = 0;

	virtual string getSpecies();
};

#endif
