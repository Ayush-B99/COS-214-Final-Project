#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantDecorator.h"
#include "Plant.h"

class FertilizerDecorator : public PlantDecorator {

private:
	string fertilizer;
	double fertilizerCost;

public:
	//FertilizerDecorator(Plant* plant, string type);
	FertilizerDecorator(std::unique_ptr<Plant> plant, std::string type);

	double getPrice();

	string getDescription();

	Plant* clone();
};

#endif
