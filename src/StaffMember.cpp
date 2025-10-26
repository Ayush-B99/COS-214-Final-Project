#include "../include/StaffMember.h"

// StaffMember::StaffMember()
// {
// }

// StaffMember::~StaffMember()
// {
// }

void StaffMember::setMediator(ConcreteGrowthMediator *mediator)
{
	this->mediator = mediator;

	mediator->addStaffMember(this);
}

void StaffMember::setCommMediator(CommMediator *commMediator)
{
	this->commMediator = commMediator;
}

void StaffMember::setCommand(Command *cmd)
{
	cout << "command being set" << endl;
	commandQueue.push_back(cmd);
}

void StaffMember::executeCommand()
{
	cout << "commands being executed" << endl;
	busy = true;
	for (Command *cmd : commandQueue)
	{
		cmd->execute();
		commandHistory.push_back(cmd);
	}
	commandQueue.clear();
	busy = false;
}

void StaffMember::undoLastCommand()
{
	// TODO - implement StaffMember::undoLastCommand
	throw "Not yet implemented";

	// how do we undo the commands such as watering or sunlight?.
}

bool StaffMember::isBusy()
{
	return busy;
}
