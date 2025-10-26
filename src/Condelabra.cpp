#include "../include/Condelabra.h"

Condelabra::Condelabra() : LargePlant("Condelabra") {
	// TODO - implement Condelabra::Condelabra
}

Condelabra::Condelabra(Condelabra& other) : LargePlant(other) {
	// TODO - implement Condelabra::Condelabra
}

Condelabra::~Condelabra() {
	// TODO - implement Condelabra::~Condelabra
}

Plant* Condelabra::clone() {
	// TODO - implement Condelabra::clone
	return new Condelabra(*this);
}
