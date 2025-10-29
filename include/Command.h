#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Command
{

public:
	virtual ~Command();

	virtual void execute() = 0;
};

#endif
