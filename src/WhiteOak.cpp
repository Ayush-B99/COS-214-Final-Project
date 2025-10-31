#include "../include/WhiteOak.h"

WhiteOak::WhiteOak() : LargePlant("White Oak") {
	// TODO - implement WhiteOak::WhiteOak
	setPrice(180.0);
    setDescription("A majestic tree with strong, spreading branches");
}

WhiteOak::WhiteOak(WhiteOak& other) : LargePlant(other) {
	// TODO - implement WhiteOak::WhiteOak
	setPrice(other.getPrice());
}

WhiteOak::~WhiteOak() {
	// TODO - implement WhiteOak::~WhiteOak

}

Plant* WhiteOak::clone() {
	// TODO - implement WhiteOak::clone
	return new WhiteOak(*this);
}
