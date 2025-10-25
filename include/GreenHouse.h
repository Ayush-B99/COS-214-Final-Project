#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;
#include "Plant.h"

class GreenHouse {


public:
	virtual vector<Plant*> createSmallPlant() = 0;

	virtual vector<Plant*> createMediumPlant() = 0;

	virtual vector<Plant*> createLargePlant() = 0;

	virtual ~GreenHouse();
};

#endif
