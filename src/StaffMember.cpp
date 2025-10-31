#include "../include/StaffMember.h"
#include <iostream>
using namespace std;

StaffMember::StaffMember(const string &name, CommMediator *mediator)
	: mediator(nullptr), currentState(), commandHistory(), commMediator(mediator), staffName(name), isAvailable(true)
{
	if (commMediator)
	{
		commMediator->addStaff(this);
	}
}

void StaffMember::setCommMediator(CommMediator *commMediator)
{
	this->commMediator = commMediator;

	if (commMediator)
	{
		commMediator->addStaff(this);
	}
}

string StaffMember::getName() const
{
	return staffName;
}

bool StaffMember::getAvailability() const
{
	return isAvailable;
}

void StaffMember::setAvailability(bool available)
{
	isAvailable = available;
}

void StaffMember::respondToCustomer(Customer *customer, const string &response, Plant *plant)
{
	if (commMediator)
	{
		commMediator->notifyCustomer(this, customer, response, plant);
	}
}