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

class ConcreteGrowthMediator {

private:
	vector<StaffMember*> staffMembers;

public:
	void notify(StaffMember* sender, string event);
};

#endif
