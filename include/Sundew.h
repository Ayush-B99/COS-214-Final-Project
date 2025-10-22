#ifndef SUNDEW_H
#define SUNDEW_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Sundew : SmallPlant {


public:
	Sundew();

	Sundew(Sundew& other);

	~Sundew();

	Plant* clone();
};

#endif
