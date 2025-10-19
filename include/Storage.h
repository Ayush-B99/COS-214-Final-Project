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

class Storage {


public:
	virtual InventoryIterator* createIterator() = 0;
};

#endif
