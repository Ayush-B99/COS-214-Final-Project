#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"

class HealthState {


public:
	virtual ~HealthState();

	virtual void degrade(Plant* plant) = 0;

	virtual void improve(Plant* plant) = 0;

	virtual string getStatusMessage(Plant* plant) = 0;

	virtual bool isDead();

	virtual string getName();
};

#endif
