#ifndef SEED_H
#define SEED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Seed : GrowthState {


public:
	void grow(Plant* plant);
};

#endif
