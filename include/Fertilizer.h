#ifndef FERTILIZER_H
#define FERTILIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Command.h"

using namespace std;

class Fertilizer : public Command {

public:
	Plant* receiver;

	void FertilizerCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
