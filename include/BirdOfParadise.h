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

class BirdOfParadise : MediumPlant {


public:
	BirdOfParadise();

	BirdOfParadise(BirdOfParadise& other);

	~BirdOfParadise();

	Plant* clone();
};

#endif
