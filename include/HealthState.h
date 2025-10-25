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

class HealthState {


public:
	virtual ~HealthState();

	virtual void update(Plant* plant) = 0;
};

#endif
