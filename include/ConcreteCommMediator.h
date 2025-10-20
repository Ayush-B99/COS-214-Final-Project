#ifndef CONCRETECOMMMEDIATOR_H
#define CONCRETECOMMMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "CommMediator.h"
#include "StaffMember.h"

using namespace std;

class ConcreteCommMediator : public CommMediator {

public:
	vector<StaffMember*> staffMembers;

	void notify(StaffMember* sender, string event, Plant* plant);
};

#endif
