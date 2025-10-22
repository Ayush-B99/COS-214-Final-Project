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
};

#endif
