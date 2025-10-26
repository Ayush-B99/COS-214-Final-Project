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

#include "ConcreteGrowthMediator.h"
// #include "CommMediator.h"
// #include "Plant.h"
#include "Command.h"

using namespace std;

class CommMediator;
class ConcreteGrowthMediator;

class StaffMember
{

private:
	ConcreteGrowthMediator *mediator;
	CommMediator *commMediator;
	vector<Plant *> currentState;
	vector<Command *> commandHistory;
	vector<Command *> commandQueue;

public:
	void setMediator(ConcreteGrowthMediator *mediator);

	void setCommMediator(CommMediator *commMediator);

	void setCommand(Command *cmd);

	void executeCommand();

	void undoLastCommand();

	virtual void getComm() = 0;

	virtual void setComm() = 0;

	virtual void getGrowth() = 0;

	virtual void setGrowth() = 0;

	bool isBusy();
};

#endif
