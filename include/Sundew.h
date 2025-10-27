#ifndef SUNDEW_H
#define SUNDEW_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "SmallPlant.h"

class Sundew : public SmallPlant {


public:
	Sundew();

	Sundew(Sundew& other);

	~Sundew();

	Plant* clone();
};

#endif
