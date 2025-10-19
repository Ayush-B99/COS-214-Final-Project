#ifndef NEEDSCARE_H
#define NEEDSCARE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class NeedsCare : HealthState {


public:
	void update(Plant* plant);
};

#endif
