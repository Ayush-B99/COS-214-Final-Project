#ifndef FERTILIZER_H
#define FERTILIZER_H

class Fertilizer : PlantDecorator, Command {

public:
	Plant* receiver;

	void FertilizerCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
