#ifndef CONCRETECOMMMEDIATOR_H
#define CONCRETECOMMMEDIATOR_H

class ConcreteCommMediator : CommMediator {

public:
	vector<StaffMember*> staffMembers;

	void notify(StaffMember* sender, string event, Plant* plant);
};

#endif
