#ifndef WATER_H
#define WATER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Command.h"

using namespace std;

class Water :public Command {

public:
	Plant* receiver;

	void WaterCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
