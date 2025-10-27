#ifndef TEMPERATEPLANTFACTORY_H
#define TEMPERATEPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GreenHouse.h"

// plants according to each category inc. here just for clean code
#include "Lilac.h"
#include "Daisy.h"
#include "WhiteOak.h"

class TemperatePlantFactory : public GreenHouse {


public:
	TemperatePlantFactory();

	~TemperatePlantFactory();

	Plant* createSmallPlant();

	Plant* createMediumPlant();

	Plant* createLargePlant();
};

#endif
