#ifndef HENANDCHICKS_H
#define HENANDCHICKS_H

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

class HenAndChicks : public SmallPlant {


public:
	HenAndChicks();

	HenAndChicks(HenAndChicks& other);

	~HenAndChicks();

	Plant* clone();
};

#endif
