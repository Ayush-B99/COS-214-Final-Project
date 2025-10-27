#ifndef MATURE_H
#define MATURE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GrowthState.h"
#include "Plant.h"

class Mature : public GrowthState {


public:
	void grow(Plant* plant);

	vector<string> getRequiredCare();

	string getStatusMessage(Plant* plant);

	bool isMature();

	string getName();
	
};

#endif