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

class Nepenthes : LargePlant {


public:
	Nepenthes();

	Nepenthes(Nepenthes& other);

	~Nepenthes();

	Plant* clone();
};

#endif
