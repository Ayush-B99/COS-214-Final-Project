#ifndef DEAD_H
#define DEAD_H

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

class Dead : public HealthState {


public:
	void degrade(Plant* plant);

	void improve(Plant* plant);

	string getStatusMessage(Plant* plant);

	bool isDead();

	string getName();
};

#endif
