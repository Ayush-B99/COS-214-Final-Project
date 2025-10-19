#ifndef CARNIVOROUSPLANTFACTORY_H
#define CARNIVOROUSPLANTFACTORY_H

class CarnivorousPlantFactory : GreenHouse {


public:
	CarnivorousPlantFactory();

	~CarnivorousPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
