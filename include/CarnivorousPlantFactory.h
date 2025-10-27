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

// specific plant types inc. here
#include "Pitcher.h"
#include "Sundew.h"
#include "Nepenthes.h"

class CarnivorousPlantFactory : public GreenHouse {


public:
	CarnivorousPlantFactory();

	~CarnivorousPlantFactory();

	Plant* createSmallPlant();

	Plant* createMediumPlant();

	Plant* createLargePlant();
};

#endif
