#ifndef SUNDEW_H
#define SUNDEW_H

class Sundew : SmallPlant {


public:
	Sundew();

	Sundew(Sundew& other);

	~Sundew();

	Plant* clone();
};

#endif
