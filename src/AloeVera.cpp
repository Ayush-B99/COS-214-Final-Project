#include "../include/AloeVera.h"

AloeVera::AloeVera() : MediumPlant("Aloe Vera") {
	// leave empty

}

AloeVera::AloeVera(AloeVera& other) : MediumPlant(other) {
	// leave empty
}

AloeVera::~AloeVera() {
	// leave empty for now
}

Plant* AloeVera::clone() {
	// TODO - implement AloeVera::clone
	return new AloeVera(*this);
}
