#include "../include/LargePlant.h"

LargePlant::LargePlant(string species) : Plant(species) {
	// TODO - implement LargePlant::LargePlant
	size = "Large";
}

LargePlant::~LargePlant() {
	// TODO - implement LargePlant::~LargePlant
}

char LargePlant::getSize() {
	// TODO - implement LargePlant::getSize
	return 'L';
}
