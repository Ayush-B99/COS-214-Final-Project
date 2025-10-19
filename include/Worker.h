#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Worker : StaffMember {


public:
	void getComm();

	void setComm();

	void getGrowth();

	void setGrowth();
};

#endif
