#include "../include/Nerve.h"

Nerve::Nerve() : SmallPlant("Nerve") {
	// TODO - implement Nerve::Nerve

}

Nerve::Nerve(Nerve& other) : SmallPlant(other) {
	// TODO - implement Nerve::Nerve

}

Nerve::~Nerve() {
	// TODO - implement Nerve::~Nerve

}

Plant* Nerve::clone() {
	// TODO - implement Nerve::clone
	return new Nerve(*this);
}
