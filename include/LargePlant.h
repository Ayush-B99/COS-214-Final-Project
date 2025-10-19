#ifndef LARGEPLANT_H
#define LARGEPLANT_H

class LargePlant : Plant {

public:
	string size;

	LargePlant(string species);

	~LargePlant();

	char getSize();
};

#endif
