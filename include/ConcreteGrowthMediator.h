#ifndef CONCRETEGROWTHMEDIATOR_H
#define CONCRETEGROWTHMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

//#include "StaffMember.h"
#include "Plant.h"

class StaffMember;

class ConcreteGrowthMediator
{

private:
	vector<StaffMember *> staffMembers;

public:
	void notify(Plant* plant);
};

#endif
