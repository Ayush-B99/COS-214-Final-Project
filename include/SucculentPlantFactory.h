#ifndef SUCCULENTPLANTFACTORY_H
#define SUCCULENTPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"

class SucculentPlantFactory : public GreenHouse {


public:
	SucculentPlantFactory();

	~SucculentPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
