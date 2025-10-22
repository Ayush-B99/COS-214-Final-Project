#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Plant.h"

using namespace std;

class Command {


public:
	virtual ~Command();

	virtual void execute() = 0;

	virtual void undo() = 0;
};

#endif
