#ifndef SUCCULENTCAREHANDLER_H
#define SUCCULENTCAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class SucculentCareHandler : public PlantCareHandler {


public:
	void succulentCare();

	void message();
};

#endif
