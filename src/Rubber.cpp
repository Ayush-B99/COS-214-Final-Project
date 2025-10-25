#include "../include/Rubber.h"

Rubber::Rubber() : LargePlant("Rubber") {
	// return nothing
	
}

Rubber::Rubber(Rubber& other) : LargePlant(other) {
	// return nothing
	
}

Rubber::~Rubber() {
	// leave empty for now
	
}

Plant* Rubber::clone() {
	// TODO - implement Rubber::clone
	return new Rubber(*this);
}
