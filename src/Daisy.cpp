#include "../include/Daisy.h"

Daisy::Daisy() : SmallPlant("Daisy") {
	// TODO - implement Daisy::Daisy
	setPrice(25.0);
    setDescription("A cheerful Daisy with white petals");
}

Daisy::Daisy(const Daisy& other) : SmallPlant(other) {
	// TODO - implement Daisy::Daisy
	// setPrice(other.getPrice());
}

Daisy::~Daisy() {
	// TODO - implement Daisy::~Daisy
}

Plant* Daisy::clone() {
	// TODO - implement Daisy::clone
	Plant* newDaisy = new Daisy(*this);
	return newDaisy;
}
