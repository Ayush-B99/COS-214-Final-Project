#ifndef RUBBER_H
#define RUBBER_H

class Rubber : LargePlant {


public:
	Rubber();

	Rubber(Rubber& other);

	~Rubber();

	Plant* clone();
};

#endif
