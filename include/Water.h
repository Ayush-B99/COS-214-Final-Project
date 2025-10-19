#ifndef WATER_H
#define WATER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Water : Command {

public:
	Plant* receiver;

	void WaterCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
