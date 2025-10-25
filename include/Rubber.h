#ifndef RUBBER_H
#define RUBBER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"

class Rubber : public LargePlant {


public:
	Rubber();

	Rubber(Rubber& other);

	~Rubber();

	Plant* clone();
};

#endif
