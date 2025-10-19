#ifndef ALOEVERA_H
#define ALOEVERA_H

class AloeVera : MediumPlant {


public:
	AloeVera();

	AloeVera(AloeVera& other);

	~AloeVera();

	Plant* clone();
};

#endif
