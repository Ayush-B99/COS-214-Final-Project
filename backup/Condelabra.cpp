#include "../include/Condelabra.h"

Condelabra::Condelabra() : LargePlant("Condelabra") {
	// TODO - implement Condelabra::Condelabra
	setPrice(120.0);
    setDescription("A tall succulent with candelabra-like branches");
}

Condelabra::Condelabra(Condelabra& other) : LargePlant(other) {
	// TODO - implement Condelabra::Condelabra
	setPrice(other.getPrice());
}

Condelabra::~Condelabra() {
	// TODO - implement Condelabra::~Condelabra
}

Plant* Condelabra::clone() {
	// TODO - implement Condelabra::clone
	return new Condelabra(*this);
}
