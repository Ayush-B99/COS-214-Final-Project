#ifndef COMMMEDIATOR_H
#define COMMMEDIATOR_H

class CommMediator {


public:
	virtual ~CommMediator();

	virtual void notify(StaffMember* sender, string event, Plant* plant) = 0;
};

#endif
