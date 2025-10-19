#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class StaffMember {

private:
	GrowthMediator* mediator;
	CommMediator* commMediator;
	vector<Plant*> currentState;
	vector<Command*> commandHistory;

public:
	void setMediator(GrowthMediator* mediator);

	void setCommMediator(CommMediator* commMediator);

	void setCommand(Command* cmd);

	void executeCommand();

	void undoLastCommand();

	virtual void getComm() = 0;

	virtual Void setComm() = 0;

	virtual void getGrowth() = 0;

	virtual void setGrowth() = 0;
};

#endif
