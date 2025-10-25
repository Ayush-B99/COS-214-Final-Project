#ifndef LILAC_H
#define LILAC_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "MediumPlant.h"	

class Lilac : public MediumPlant {


public:
	Lilac();

	Lilac(Lilac& other);

	~Lilac();

	Plant* clone();
};

#endif
