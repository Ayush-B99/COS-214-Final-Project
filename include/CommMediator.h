#ifndef COMMMEDIATOR_H
#define COMMMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "StaffMember.h"
#include "Plant.h"

class CommMediator {


public:
	virtual ~CommMediator();

	virtual void notify(StaffMember* sender, string event, Plant* plant) = 0;
};

#endif
