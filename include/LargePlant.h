#ifndef LARGEPLANT_H
#define LARGEPLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class LargePlant : Plant {

public:
	string size;

	LargePlant(string species);

	~LargePlant();

	char getSize();
};

#endif
