#ifndef CONCRETEGROWTHMEDIATOR_H
#define CONCRETEGROWTHMEDIATOR_H

class ConcreteGrowthMediator {

private:
	vector<StaffMember*> staffMembers;

public:
	void notify(StaffMember* sender, string event);
};

#endif
