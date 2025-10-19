#ifndef SMALLPLANT_H
#define SMALLPLANT_H

class SmallPlant : Plant {

public:
	string size;

	SmallPlant(string species);

	virtual ~SmallPlant();

	char getSize();
};

#endif
