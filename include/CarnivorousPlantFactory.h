#ifndef CARNIVOROUSPLANTFACTORY_H
#define CARNIVOROUSPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"
#include "Plant.h"

class CarnivorousPlantFactory : public GreenHouse {


public:
	CarnivorousPlantFactory();

	~CarnivorousPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
