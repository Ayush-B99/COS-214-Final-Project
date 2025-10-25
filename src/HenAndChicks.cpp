#include "../include/HenAndChicks.h"

HenAndChicks::HenAndChicks() : SmallPlant("Hen & Chicks") {
	// TODO - implement HenAndChicks::HenAndChicks
	
}

HenAndChicks::HenAndChicks(HenAndChicks& other) : SmallPlant(other) {
	// TODO - implement HenAndChicks::HenAndChicks
	
}

HenAndChicks::~HenAndChicks() {
	// TODO - implement HenAndChicks::~HenAndChicks
	
}

Plant* HenAndChicks::clone() {
	// TODO - implement HenAndChicks::clone
	return new HenAndChicks(*this);
}
