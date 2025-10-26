#ifndef NEEDSCARE_H
#define NEEDSCARE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "HealthState.h"
#include "Plant.h"

class NeedsCare : public HealthState {


public:
	void degrade(Plant* plant);

	void improve(Plant* plant);

	string getStatusMessage(Plant* plant);

	bool isDead();
};

#endif
