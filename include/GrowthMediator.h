#ifndef GROWTHMEDIATOR_H
#define GROWTHMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class GrowthMediator : ConcreteGrowthMediator {


public:
	virtual ~GrowthMediator();

	virtual void notify(StaffMember* sender, string event) = 0;
};

#endif
