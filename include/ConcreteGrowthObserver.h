#ifndef CONCRETEGROWTHOBSERVER_H
#define CONCRETEGROWTHOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GrowthMediator.h"
#include "Plant.h"

class ConcreteGrowthObserver
{

public:
	void onGrowthChange(Plant *plant);
};

#endif
