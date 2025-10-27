#include "../include/StaffMember.h"

void StaffMember::setMediator(CommMediator* mediator) {
	this->commMediator = mediator;
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
