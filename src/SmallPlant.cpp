#include "../include/SmallPlant.h"

SmallPlant::SmallPlant(string species) : Plant(species) {
	// TODO - implement SmallPlant::SmallPlant
	size = "Small";
}

SmallPlant::~SmallPlant() {
	// TODO - implement SmallPlant::~SmallPlant

}

char SmallPlant::getSize() {
	// TODO - implement SmallPlant::getSize
	return 'S';
}
