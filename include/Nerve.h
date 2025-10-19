#ifndef NERVE_H
#define NERVE_H

class Nerve : SmallPlant {


public:
	Nerve();

	Nerve(Nerve& other);

	~Nerve();

	Plant* clone();
};

#endif
