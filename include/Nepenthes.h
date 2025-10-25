#ifndef NEPENTHES_H
#define NEPENTHES_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"

class Nepenthes : public LargePlant {


public:
	Nepenthes();

	Nepenthes(Nepenthes& other);

	~Nepenthes();

	Plant* clone();
};

#endif
