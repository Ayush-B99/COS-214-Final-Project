#include "../include/MediumPlant.h"

MediumPlant::MediumPlant(string species) : Plant(species) {
	// TODO - implement MediumPlant::MediumPlant
	size = "Medium";
}

MediumPlant::~MediumPlant() {
	// TODO - implement MediumPlant::~MediumPlant
}

char MediumPlant::getSize() {
	// TODO - implement MediumPlant::getSize
	return 'M';
}
