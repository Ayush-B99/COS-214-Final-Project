#include "../include/Daisy.h"

Daisy::Daisy() : SmallPlant("Daisy") {
	// TODO - implement Daisy::Daisy

}

Daisy::Daisy(Daisy& other) : SmallPlant(other) {
	// TODO - implement Daisy::Daisy

}

Daisy::~Daisy() {
	// TODO - implement Daisy::~Daisy
}

Plant* Daisy::clone() {
	// TODO - implement Daisy::clone
	return new Daisy(*this);
}
