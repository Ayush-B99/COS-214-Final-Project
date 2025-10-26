#include "../include/StaffMember.h"

void StaffMember::setMediator(ConcreteGrowthMediator *mediator)
{
	this->mediator = mediator;
}

void StaffMember::setCommMediator(CommMediator *commMediator)
{
	this->commMediator = commMediator;
}

void StaffMember::setCommand(Command *cmd)
{
	// TODO - implement StaffMember::setCommand
	throw "Not yet implemented";
}

void StaffMember::executeCommand()
{
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
