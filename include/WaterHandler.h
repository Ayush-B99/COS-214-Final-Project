#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class WaterHandler : public PlantCareHandler
{

public:
	~WaterHandler();
	void handleCareRequest(Plant *plant);

	void message();
};

#endif
