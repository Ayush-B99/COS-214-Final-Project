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

class Lilac : MediumPlant {


public:
	Lilac();

	Lilac(Lilac& other);

	~Lilac();

	Plant* clone();
};

#endif
