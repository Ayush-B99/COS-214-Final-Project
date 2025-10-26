#include "../include/BirdOfParadise.h"

BirdOfParadise::BirdOfParadise() : MediumPlant("Bird Of Paradise") {
	// leave empty

}

BirdOfParadise::BirdOfParadise(BirdOfParadise& other) : MediumPlant(other) {
	// leave emtpy
	
}

BirdOfParadise::~BirdOfParadise() {
	// leae emtpy for now
	
}

Plant* BirdOfParadise::clone() {
	// TODO - implement BirdOfParadise::clone
	return new BirdOfParadise(*this);
}
