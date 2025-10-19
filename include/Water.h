#ifndef WATER_H
#define WATER_H

class Water : Command {

public:
	Plant* receiver;

	void WaterCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
