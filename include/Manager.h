#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Manager : StaffMember {


public:
	void getComm();

	void setComm();

	void getGrowth();

	void setGrowth();
};

#endif
