#include "../include/Sundew.h"

Sundew::Sundew() : SmallPlant("Sundew") {
	// TODO - implement Sundew::Sundew
}

Sundew::Sundew(Sundew& other) : SmallPlant(other) {
	// TODO - implement Sundew::Sundew
	
}

Sundew::~Sundew() {
	// TODO - implement Sundew::~Sundew
	
}

Plant* Sundew::clone() {
	// TODO - implement Sundew::clone
	return new Sundew(*this);
}
