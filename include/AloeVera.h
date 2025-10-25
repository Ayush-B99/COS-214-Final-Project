#ifndef ALOEVERA_H
#define ALOEVERA_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Plant.h"
#include "MediumPlant.h"

class AloeVera : public MediumPlant {


public:
	AloeVera();

	AloeVera(AloeVera& other);

	~AloeVera();

	Plant* clone();
};

#endif
