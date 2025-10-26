#ifndef DAISY_H
#define DAISY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "SmallPlant.h"
#include "Plant.h"

class Daisy : public SmallPlant {


public:
	Daisy();

	Daisy(Daisy& other);

	~Daisy();

	Plant* clone();
};

#endif
