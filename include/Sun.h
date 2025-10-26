#ifndef SUN_H
#define SUN_H

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

class Sun : public Command
{

private:
	Plant *receiver;

public:
	Sun(Plant *plant);

	void execute();

	void undo();
};

#endif
