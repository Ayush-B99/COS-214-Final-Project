#ifndef SUN_H
#define SUN_H

class Sun : Command {

public:
	Plant* receiver;

	void SunCommand(Plant* plant);

	void execute();

	void undo();
};

#endif
