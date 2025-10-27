#ifndef TROPICALCAREHANDLER_H
#define TROPICALCAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class TropicalCareHandler : public PlantCareHandler {


public:
	void tropicalCare();

	void message();
};

#endif
