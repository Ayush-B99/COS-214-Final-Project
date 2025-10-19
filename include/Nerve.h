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

class Nerve : SmallPlant {


public:
	Nerve();

	Nerve(Nerve& other);

	~Nerve();

	Plant* clone();
};

#endif
