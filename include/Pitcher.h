#ifndef PITCHER_H
#define PITCHER_H

class Pitcher : MediumPlant {


public:
	Pitcher();

	Pitcher(Pitcher& other);

	~Pitcher();

	Plant* clone();
};

#endif
