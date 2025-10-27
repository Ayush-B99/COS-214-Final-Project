#ifndef CARNIVOROUSCAREHANDLER_H
#define CARNIVOROUSCAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class CarnivorousCareHandler : public PlantCareHandler {


public:
	void carnivorousCare();

	void message();
};

#endif
