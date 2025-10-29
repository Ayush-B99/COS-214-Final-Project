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

#include "Command.h"
#include "Plant.h"

class Water : public Command
{

private:
	Plant *receiver;

public:
	Water(Plant *plant);

	void execute();
};

#endif
