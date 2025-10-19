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

class Condelabra : LargePlant {


public:
	Condelabra();

	Condelabra(Condelabra& other);

	~Condelabra();

	Plant* clone();
};

#endif
