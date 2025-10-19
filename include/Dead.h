#ifndef DEAD_H
#define DEAD_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Dead : HealthState {


public:
	void update(Plant* plant);
};

#endif
