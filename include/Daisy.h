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

class Daisy : SmallPlant {


public:
	Daisy();

	Daisy(Daisy& other);

	~Daisy();

	Plant* clone();
};

#endif
