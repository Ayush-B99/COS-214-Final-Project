#include "../include/WhiteOak.h"

WhiteOak::WhiteOak() : LargePlant("White Oak") {
	// TODO - implement WhiteOak::WhiteOak
}

WhiteOak::WhiteOak(WhiteOak& other) : LargePlant(other) {
	// TODO - implement WhiteOak::WhiteOak
}

WhiteOak::~WhiteOak() {
	// TODO - implement WhiteOak::~WhiteOak
}

Plant* WhiteOak::clone() {
	// TODO - implement WhiteOak::clone
	return new WhiteOak(*this);
}
