#include "../include/StaffMember.h"
#include <iostream>
using namespace std;

StaffMember::StaffMember(const string &name, CommMediator *mediator, Inventory *inventory)
	: mediator(nullptr), currentState(), commandHistory(),
	  commMediator(mediator), staffName(name), isAvailable(true), inventory(inventory)
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

void StaffMember::setInventory(Inventory *inv)
{
	this->inventory = inv;
}

string StaffMember::getName() const
{
	return staffName;
}

void StaffMember::setAvailability(bool available)
{
	isAvailable = available;
}

bool StaffMember::getAvailability() const
{
	return isAvailable;
}

void StaffMember::respondToCustomer(Customer *customer, const string &response, Plant *plant)
{
	if (commMediator)
	{
		commMediator->notifyCustomer(this, customer, response, plant);
	}
}