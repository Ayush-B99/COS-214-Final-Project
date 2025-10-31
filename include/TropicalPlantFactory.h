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

#include "GreenHouse.h"

// specific plant types inc. here

#include "Nerve.h"
#include "BirdOfParadise.h"
#include "Rubber.h"

class TropicalPlantFactory : public GreenHouse {


public:
	TropicalPlantFactory();

	~TropicalPlantFactory();

	Plant* createSmallPlant();

	Plant* createMediumPlant();

	Plant* createLargePlant();
};

#endif
