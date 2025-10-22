#ifndef PITCHER_H
#define PITCHER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "MediumPlant.h"

class Pitcher : public MediumPlant {


public:
	Pitcher();

	Pitcher(Pitcher& other);

	~Pitcher();

	Plant* clone();
};

#endif
