#ifndef GROWTHSTATE_H
#define GROWTHSTATE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

// #include "Plant.h"

class Plant; // Forward declaration

class GrowthState
{

public:
	virtual ~GrowthState();

	virtual string getStatusMessage(Plant *plant) = 0; // returns the status message of the plant

	virtual void grow(Plant *plant) = 0; // checks the growth advancement

	virtual vector<string> getRequiredCare() = 0; // returns the required care actions for the current growth state

	virtual bool isSold();

	virtual bool isMature();

	virtual string getName() = 0;
};

#endif
