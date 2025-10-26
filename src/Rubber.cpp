#include "../include/Rubber.h"

Rubber::Rubber() : LargePlant("Rubber") {
	setPrice(110.0);
    setDescription("A robust plant with large, glossy leaves");
}

Rubber::Rubber(Rubber& other) : LargePlant(other) {
	setPrice(other.getPrice());
}

Rubber::~Rubber() {
	// leave empty for now
	
}

Plant* Rubber::clone() {
	// TODO - implement Rubber::clone
	return new Rubber(*this);
}
