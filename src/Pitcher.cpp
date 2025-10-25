#include "../include/Pitcher.h"

Pitcher::Pitcher() : MediumPlant("Pitcher") {
	// TODO - implement Pitcher::Pitcher
	
}

Pitcher::Pitcher(Pitcher& other) : MediumPlant(other) {
	// TODO - implement Pitcher::Pitcher
	
}

Pitcher::~Pitcher() {
	// TODO - implement Pitcher::~Pitcher
	
}

Plant* Pitcher::clone() {
	// TODO - implement Pitcher::clone
	return new Pitcher(*this);
}
