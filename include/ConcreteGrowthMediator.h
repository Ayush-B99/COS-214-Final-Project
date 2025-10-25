#ifndef CONCRETEGROWTHMEDIATOR_H
#define CONCRETEGROWTHMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "GrowthMediator.h"

using namespace std;

//#include "StaffMember.h"

class StaffMember;

class ConcreteGrowthMediator : public GrowthMediator
{

private:
	vector<StaffMember *> staffMembers;

public:
	void notify(StaffMember *sender, string event);
};

#endif
