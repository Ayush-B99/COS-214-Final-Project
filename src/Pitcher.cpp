#include "../include/Pitcher.h"

Pitcher::Pitcher() : MediumPlant("Pitcher") {
	// TODO - implement Pitcher::Pitcher
	setPrice(95.0);
    setDescription("A carnivorous plant with pitcher-shaped traps");
}

Pitcher::Pitcher(Pitcher& other) : MediumPlant(other) {
	// TODO - implement Pitcher::Pitcher
	setPrice(other.getPrice());
}

Pitcher::~Pitcher() {
	// TODO - implement Pitcher::~Pitcher
	
}

Plant* Pitcher::clone() {
	// TODO - implement Pitcher::clone
	return new Pitcher(*this);
}
