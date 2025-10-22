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

class Rubber : LargePlant {


public:
	Rubber();

	Rubber(Rubber& other);

	~Rubber();

	Plant* clone();
};

#endif
