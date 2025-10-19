#ifndef GROWTHMEDIATOR_H
#define GROWTHMEDIATOR_H

class GrowthMediator : ConcreteGrowthMediator {


public:
	virtual ~GrowthMediator();

	virtual void notify(StaffMember* sender, string event) = 0;
};

#endif
