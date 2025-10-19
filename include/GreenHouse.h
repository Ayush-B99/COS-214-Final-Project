#ifndef GREENHOUSE_H
#define GREENHOUSE_H

class GreenHouse {


public:
	virtual vector<Plant*> createSmallPlant() = 0;

	virtual vector<Plant*> createMediumPlant() = 0;

	virtual vector<Plant*> createLargePlant() = 0;

	virtual ~GreenHouse();
};

#endif
