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

class ConcreteGrowthObserver : GrowthObserver {


public:
	void onGrowthChange(Plant* plant);
};

#endif
