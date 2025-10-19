#ifndef HENANDCHICKS_H
#define HENANDCHICKS_H

class HenAndChicks : SmallPlant {


public:
	HenAndChicks();

	HenAndChicks(HenAndChicks& other);

	~HenAndChicks();

	Plant* clone();
};

#endif
