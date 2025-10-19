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

class GrowthState {


public:
	virtual ~GrowthState();

	virtual void grow(Plant* plant) = 0;
};

#endif
