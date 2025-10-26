#include "../include/PlantDecorator.h"

PlantDecorator::PlantDecorator(Plant* plant) : decoratedPlant(plant) {
	// leave empty
}

PlantDecorator::~PlantDecorator() {
	// comment out if double free happens
	delete decoratedPlant;
}

double PlantDecorator::getPrice() {
	return decoratedPlant->getPrice();
}

string PlantDecorator::getDescription() {
	return decoratedPlant->getDescription();
}
