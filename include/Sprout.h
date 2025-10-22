#ifndef SPROUT_H
#define SPROUT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Sprout : GrowthState {


public:
	void grow(Plant* plant);
};

#endif
