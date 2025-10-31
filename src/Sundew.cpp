#include "../include/Sundew.h"

Sundew::Sundew() : SmallPlant("Sundew") {
	// TODO - implement Sundew::Sundew
	setPrice(55.0);
    setDescription("A carnivorous plant with sticky tentacles");
}

Sundew::Sundew(Sundew& other) : SmallPlant(other) {
	// TODO - implement Sundew::Sundew
	setPrice(other.getPrice());
}

Sundew::~Sundew() {
	// TODO - implement Sundew::~Sundew
	
}

Plant* Sundew::clone() {
	// TODO - implement Sundew::clone
	return new Sundew(*this);
}
