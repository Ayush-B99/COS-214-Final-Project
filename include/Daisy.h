#ifndef DAISY_H
#define DAISY_H

class Daisy : SmallPlant {


public:
	Daisy();

	Daisy(Daisy& other);

	~Daisy();

	Plant* clone();
};

#endif
