#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

class PlantDecorator : Plant {

public:
	Plant* decoratedPlant;

	PlantDecorator(Plant* plant);

	virtual ~PlantDecorator();

	double getPrice();

	string getDescription();
};

#endif
