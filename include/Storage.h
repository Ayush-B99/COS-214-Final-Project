#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "InventoryIterator.h"

class Storage {


public:
	virtual Iterator* createIterator() = 0;

	virtual void addPlant(Plant* plant)=0;

	virtual void removePlant(Plant* plant)=0;

	virtual void print()=0;
};

#endif