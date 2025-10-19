#ifndef MEDIUMPLANT_H
#define MEDIUMPLANT_H

class MediumPlant : Plant {

public:
	string size;

	MediumPlant(string species);

	virtual ~MediumPlant();

	char getSize();
};

#endif
