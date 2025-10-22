#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class PotDecorator : PlantDecorator {

private:
	string potType;
	double potCost;

public:
	PotDecorator(Plant* plant, string type);

	double getPrice();

	string getDescription();
};

#endif
