#ifndef SUCCULENTPLANTFACTORY_H
#define SUCCULENTPLANTFACTORY_H

class SucculentPlantFactory : GreenHouse {


public:
	SucculentPlantFactory();

	~SucculentPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
