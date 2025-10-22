#ifndef CONCRETEGROWTHOBSERVER_H
#define CONCRETEGROWTHOBSERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "GrowthObserver.h"

using namespace std;

class ConcreteGrowthObserver : public GrowthObserver {


public:
	void onGrowthChange(Plant* plant);
};

#endif
