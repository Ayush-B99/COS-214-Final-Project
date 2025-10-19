#ifndef TROPICALPLANTFACTORY_H
#define TROPICALPLANTFACTORY_H

class TropicalPlantFactory : GreenHouse {


public:
	TropicalPlantFactory();

	~TropicalPlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
