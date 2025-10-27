#ifndef TEMPERATECAREHANDLER_H
#define TEMPERATECAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class TemperateCareHandler : public PlantCareHandler {


public:
	void temperateCare();

	void message();
};

#endif
