#ifndef SMALLPLANT_H
#define SMALLPLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"

class SmallPlant : public Plant {

public:
	string size;

	SmallPlant(string species);

	virtual ~SmallPlant();

	char getSize();
};

#endif
