#ifndef GROWTHOBSERVER_H
#define GROWTHOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"

class GrowthObserver {


public:
	GrowthObserver();

	virtual void onGrowthChange(Plant* plant) = 0;
};

#endif
