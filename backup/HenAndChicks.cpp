#include "../include/HenAndChicks.h"

HenAndChicks::HenAndChicks() : SmallPlant("Hen & Chicks") {
	// TODO - implement HenAndChicks::HenAndChicks
	setPrice(35.0);
    setDescription("A succulent with mother and baby rosettes");
}

HenAndChicks::HenAndChicks(HenAndChicks& other) : SmallPlant(other) {
	// TODO - implement HenAndChicks::HenAndChicks
	setPrice(other.getPrice());
}

HenAndChicks::~HenAndChicks() {
	// TODO - implement HenAndChicks::~HenAndChicks
	
}

Plant* HenAndChicks::clone() {
	// TODO - implement HenAndChicks::clone
	return new HenAndChicks(*this);
}
