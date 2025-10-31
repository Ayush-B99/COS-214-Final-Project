#include "../include/Lilac.h"

Lilac::Lilac() : MediumPlant("Lilac") {
	// TODO - implement Lilac::Lilac
	setPrice(75.0);
    setDescription("A fragrant shrub with purple blossoms");
}

Lilac::Lilac(Lilac& other) : MediumPlant(other) {
	// TODO - implement Lilac::Lilac
	setPrice(other.getPrice());
}

Lilac::~Lilac() {
	// TODO - implement Lilac::~Lilac
	
}

Plant* Lilac::clone() {
	// TODO - implement Lilac::clone
	return new Lilac(*this);
}
