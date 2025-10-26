#include "../include/ConcreteGrowthMediator.h"

ConcreteGrowthMediator::ConcreteGrowthMediator()
{
	this->staffMembers = {}; // creates an empty vector
}

ConcreteGrowthMediator::~ConcreteGrowthMediator()
{
	// no need to deallocate a vector and staff members must be deallocated seperately
}

bool ConcreteGrowthMediator::addStaffMember(StaffMember *bob)
{
	for (StaffMember *duplicate : staffMembers)
	{
		if (duplicate == bob) // comparison of memory addresses as a duplicate staff member will have the same address
		{
			return false; // prevents adding duplicate staff members
		}
	}

	staffMembers.push_back(bob);
	return true;
}

bool ConcreteGrowthMediator::removeStaffMember(StaffMember *bob)
{
	for (auto it = staffMembers.begin(); it != staffMembers.end(); ++it)
	{
		if (*it == bob)
		{
			staffMembers.erase(it);
			return true;
		}
	}

	return false;
}

void ConcreteGrowthMediator::notify(Plant *plant)
{

	cout << "Mediator notifying available staff members about plant needing care." << endl;

	for (StaffMember *bob : staffMembers)
	{
		if (!bob->isBusy())
		{
			cout << "Staff member has been notified" << endl;

			bob->getGrowth(plant); // staff member bob gets the plant

			return;
		}
	}
}
