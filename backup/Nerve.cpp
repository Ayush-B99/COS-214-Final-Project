#include "../include/Nerve.h"

Nerve::Nerve() : SmallPlant("Nerve") {
	// TODO - implement Nerve::Nerve
	setPrice(45.0);
    setDescription("A tropical plant with intricate vein patterns");
}

Nerve::Nerve(Nerve& other) : SmallPlant(other) {
	// TODO - implement Nerve::Nerve
	setPrice(other.getPrice());
}

Nerve::~Nerve() {
	// TODO - implement Nerve::~Nerve

}

Plant* Nerve::clone() {
	// TODO - implement Nerve::clone
	return new Nerve(*this);
}
