#ifndef NEPENTHES_H
#define NEPENTHES_H

class Nepenthes : LargePlant {


public:
	Nepenthes();

	Nepenthes(Nepenthes& other);

	~Nepenthes();

	Plant* clone();
};

#endif
