#ifndef MATURE_H
#define MATURE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Mature : GrowthState {


public:
	void grow(Plant* plant);
};

#endif
