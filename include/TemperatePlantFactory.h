#ifndef TEMPERATEPLANTFACTORY_H
#define TEMPERATEPLANTFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class TemperatePlantFactory : GreenHouse {


public:
	TemperatePlantFactory();

	~TemperatePlantFactory();

	vector<Plant*> createSmallPlant();

	vector<Plant*> createMediumPlant();

	vector<Plant*> createLargePlant();
};

#endif
