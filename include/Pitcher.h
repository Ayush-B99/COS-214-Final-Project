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

class Pitcher : MediumPlant {


public:
	Pitcher();

	Pitcher(Pitcher& other);

	~Pitcher();

	Plant* clone();
};

#endif
