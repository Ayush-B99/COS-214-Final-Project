#ifndef PRUNE_H
#define PRUNE_H

class Prune : Command {

public:
	Plant* receiver;

	void PruneCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
