#include "../include/BirdOfParadise.h"

BirdOfParadise::BirdOfParadise() : MediumPlant("Bird Of Paradise") {
	setPrice(85.0);
    setDescription("An exotic plant with bird-like flowers");
}

BirdOfParadise::BirdOfParadise(BirdOfParadise& other) : MediumPlant(other) {
	setPrice(other.getPrice());
}

BirdOfParadise::~BirdOfParadise() {
	// leae emtpy for now
	
}

Plant* BirdOfParadise::clone() {
	// TODO - implement BirdOfParadise::clone
	return new BirdOfParadise(*this);
}
