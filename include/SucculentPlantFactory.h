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

// specific plant types inc. here
#include "Condelabra.h"
#include "HenAndChicks.h"
#include "AloeVera.h"

class SucculentPlantFactory : public GreenHouse {


public:
	SucculentPlantFactory();

	~SucculentPlantFactory();

	Plant* createSmallPlant();

	Plant* createMediumPlant();

	Plant* createLargePlant();
};

#endif
