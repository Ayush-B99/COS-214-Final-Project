#ifndef SUNHANDLER_H
#define SUNHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class SunHandler : public PlantCareHandler
{

public:
	~SunHandler();
	void handleCareRequest(Plant *plant);

	void message();
};

#endif
