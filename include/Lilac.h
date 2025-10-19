#ifndef LILAC_H
#define LILAC_H

class Lilac : MediumPlant {


public:
	Lilac();

	Lilac(Lilac& other);

	~Lilac();

	Plant* clone();
};

#endif
