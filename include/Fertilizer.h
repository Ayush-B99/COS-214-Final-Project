#ifndef FERTILIZER_H
#define FERTILIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantDecorator.h"
#include "Command.h"
#include "Plant.h"

class Fertilizer : public PlantDecorator, public Command {

public:
	Plant* receiver;

	void FertilizerCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
