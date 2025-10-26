#ifndef SEED_H
#define SEED_H

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

class Seed : public GrowthState {


public:
	void grow(Plant* plant);

	string getStatusMessage(Plant* plant);

	vector<string> getRequiredCare();

	bool isMature();
};

#endif
