#ifndef BIRDOFPARADISE_H
#define BIRDOFPARADISE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "MediumPlant.h"

class BirdOfParadise : public MediumPlant {


public:
	BirdOfParadise();

	BirdOfParadise(BirdOfParadise& other);

	~BirdOfParadise();

	Plant* clone();
};

#endif
