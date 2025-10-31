#include "../include/AloeVera.h"

AloeVera::AloeVera() : MediumPlant("Aloe Vera") {
	setPrice(65.0);
    setDescription("A healing succulent with gel-filled leaves");
}

AloeVera::AloeVera(AloeVera& other) : MediumPlant(other) {
	setPrice(other.getPrice());
}

AloeVera::~AloeVera() {
	// leave empty for now
}

Plant* AloeVera::clone() {
	// TODO - implement AloeVera::clone
	return new AloeVera(*this);
}
