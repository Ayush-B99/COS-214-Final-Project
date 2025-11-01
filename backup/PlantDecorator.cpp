#include "../include/PlantDecorator.h"

/* testing w smart pointer because of mem leaks
PlantDecorator::PlantDecorator(Plant* plant) : decoratedPlant(plant) {
	// leave empty
}
*/

PlantDecorator::PlantDecorator(std::unique_ptr<Plant> plant) 
    : decoratedPlant(std::move(plant)) {
}

// PlantDecorator::~PlantDecorator() {
// 	// comment out if double free happens
// 	delete decoratedPlant;
// }

double PlantDecorator::getPrice() {
	return decoratedPlant->getPrice();
}

string PlantDecorator::getDescription() {
	return decoratedPlant->getDescription();
}

string PlantDecorator::getSpecies()  {
    return decoratedPlant->getSpecies();
}
