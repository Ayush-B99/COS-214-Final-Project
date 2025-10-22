#ifndef TROPICALPLANTFACTORY_H
#define TROPICALPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class TropicalPlantFactory : GreenHouse {


public:
	TropicalPlantFactory();

	~TropicalPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
