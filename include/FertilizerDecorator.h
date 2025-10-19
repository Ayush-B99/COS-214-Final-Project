#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

class FertilizerDecorator : PlantDecorator {

private:
	string fertilizer;
	double fertilizerCost;

public:
	FertilizerDecorator(Plant* plant, string type);

	double getPrice();

	string getDescription();
};

#endif
