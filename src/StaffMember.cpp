#include "../include/StaffMember.h"

void StaffMember::setMediator(ConcreteGrowthMediator* mediator) {
	this->mediator = mediator;
}

void StaffMember::setCommMediator(CommMediator* commMediator) {
	this->commMediator = commMediator;
}

void StaffMember::setCommand(Command* cmd) {
	// TODO - implement StaffMember::setCommand
	throw "Not yet implemented";
}

void StaffMember::executeCommand() {
	// TODO - implement StaffMember::executeCommand
	throw "Not yet implemented";
}

void StaffMember::undoLastCommand() {
	// TODO - implement StaffMember::undoLastCommand
	throw "Not yet implemented";
}

bool StaffMember::isBusy()
{
	return !commandQueue.empty();
}
