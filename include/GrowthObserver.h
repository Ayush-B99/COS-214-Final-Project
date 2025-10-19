#ifndef GROWTHOBSERVER_H
#define GROWTHOBSERVER_H

class GrowthObserver {


public:
	virtual GrowthObserver();

	virtual void onGrowthChange(Plant* plant) = 0;
};

#endif
