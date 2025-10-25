#include "../include/Nepenthes.h"

Nepenthes::Nepenthes() : LargePlant("Nepenthas") {
	// TODO - implement Nepenthes::Nepenthes
	
}

Nepenthes::Nepenthes(Nepenthes& other) : LargePlant(other) {
	// TODO - implement Nepenthes::Nepenthes
	
}

Nepenthes::~Nepenthes() {
	// TODO - implement Nepenthes::~Nepenthes
	
}

Plant* Nepenthes::clone() {
	// TODO - implement Nepenthes::clone
	return new Nepenthes(*this);
}
