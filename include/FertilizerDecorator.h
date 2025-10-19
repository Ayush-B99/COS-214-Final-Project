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

class FertilizerDecorator : PlantDecorator {

private:
	string fertilizer;
	double fertilizerCost;

public:
	FertilizerDecorator(Plant* plant, string type);

	double getPrice();

	string getDescription();
};

#endif
