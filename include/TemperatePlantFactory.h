#ifndef TEMPERATEPLANTFACTORY_H
#define TEMPERATEPLANTFACTORY_H

class TemperatePlantFactory : GreenHouse {


public:
	TemperatePlantFactory();

	~TemperatePlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
