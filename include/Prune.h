#ifndef PRUNE_H
#define PRUNE_H

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

class Prune : public Command
{

private:
	Plant *receiver;

public:
	Prune(Plant *plant);

	void execute();
};

#endif
