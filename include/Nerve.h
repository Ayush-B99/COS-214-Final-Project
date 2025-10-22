#ifndef NERVE_H
#define NERVE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "SmallPlant.h"

class Nerve : public SmallPlant {


public:
	Nerve();

	Nerve(Nerve& other);

	~Nerve();

	Plant* clone();
};

#endif
