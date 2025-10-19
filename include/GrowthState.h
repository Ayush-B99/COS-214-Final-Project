#ifndef GROWTHSTATE_H
#define GROWTHSTATE_H

class GrowthState {


public:
	virtual ~GrowthState();

	virtual void grow(Plant* plant) = 0;
};

#endif
