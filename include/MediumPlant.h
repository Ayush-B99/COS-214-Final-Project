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

class MediumPlant : Plant {

public:
	string size;

	MediumPlant(string species);

	virtual ~MediumPlant();

	char getSize();
};

#endif
