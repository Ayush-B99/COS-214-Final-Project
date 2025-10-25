#ifndef GROWTHMEDIATOR_H
#define GROWTHMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

//#include "StaffMember.h"
#include "Plant.h"

using namespace std;

class StaffMember;

class GrowthMediator
{

public:
	virtual ~GrowthMediator();

	virtual void notify(Plant* plant) = 0;
};

#endif
