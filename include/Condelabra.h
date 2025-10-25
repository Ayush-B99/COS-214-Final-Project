#ifndef CONDELABRA_H
#define CONDELABRA_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"
#include "Plant.h"

class Condelabra : public LargePlant {


public:
	Condelabra();

	Condelabra(Condelabra& other);

	~Condelabra();

	Plant* clone();
};

#endif
