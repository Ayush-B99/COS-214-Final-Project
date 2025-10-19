#ifndef CONDELABRA_H
#define CONDELABRA_H

class Condelabra : LargePlant {


public:
	Condelabra();

	Condelabra(Condelabra& other);

	~Condelabra();

	Plant* clone();
};

#endif
