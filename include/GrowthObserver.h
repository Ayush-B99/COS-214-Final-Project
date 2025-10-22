#ifndef GROWTHOBSERVER_H
#define GROWTHOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Plant.h"

using namespace std;

class GrowthObserver {


public:
	GrowthObserver();//uml change no virtual constructor

	virtual void onGrowthChange(Plant* plant) = 0;
};

#endif
