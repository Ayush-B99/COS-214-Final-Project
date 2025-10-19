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

class Prune : Command {

public:
	Plant* receiver;

	void PruneCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
