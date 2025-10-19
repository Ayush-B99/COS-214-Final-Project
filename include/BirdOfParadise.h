#ifndef BIRDOFPARADISE_H
#define BIRDOFPARADISE_H

class BirdOfParadise : MediumPlant {


public:
	BirdOfParadise();

	BirdOfParadise(BirdOfParadise& other);

	~BirdOfParadise();

	Plant* clone();
};

#endif
