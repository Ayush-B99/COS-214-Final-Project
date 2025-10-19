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

class Sun : Command {

public:
	Plant* receiver;

	void SunCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
