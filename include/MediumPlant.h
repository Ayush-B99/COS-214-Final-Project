#ifndef MEDIUMPLANT_H
#define MEDIUMPLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"

class MediumPlant : public Plant {

public:
	string size;

	MediumPlant(string species);

	virtual ~MediumPlant();

	char getSize();
};

#endif
