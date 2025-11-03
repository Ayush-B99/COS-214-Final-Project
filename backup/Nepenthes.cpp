#include "../include/Nepenthes.h"

Nepenthes::Nepenthes() : LargePlant("Nepenthas") {
	// TODO - implement Nepenthes::Nepenthes
	setPrice(150.0);
    setDescription("A tropical pitcher plant with large traps");
}

Nepenthes::Nepenthes(Nepenthes& other) : LargePlant(other) {
	// TODO - implement Nepenthes::Nepenthes
	setPrice(other.getPrice());
}

Nepenthes::~Nepenthes() {
	// TODO - implement Nepenthes::~Nepenthes
	
}

Plant* Nepenthes::clone() {
	// TODO - implement Nepenthes::clone
	return new Nepenthes(*this);
}
