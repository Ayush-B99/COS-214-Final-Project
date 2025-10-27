#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

class FertilizerHandler : public PlantCareHandler
{

public:
	void handleCareRequest(Plant *plant);

	void message();
};

#endif
