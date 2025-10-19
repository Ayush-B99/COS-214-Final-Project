#ifndef POTDECORATOR_H
#define POTDECORATOR_H

class PotDecorator : PlantDecorator {

private:
	string potType;
	double potCost;

public:
	PotDecorator(Plant* plant, string type);

	double getPrice();

	string getDescription();
};

#endif
