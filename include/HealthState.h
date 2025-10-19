#ifndef HEALTHSTATE_H
#define HEALTHSTATE_H

class HealthState {


public:
	virtual ~HealthState();

	virtual void update(Plant* plant) = 0;
};

#endif
