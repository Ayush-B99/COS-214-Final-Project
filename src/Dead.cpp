#include "../include/Dead.h"
#include "../include/Plant.h"
#include "../include/Good.h"
#include "../include/NeedsCare.h"

void Dead::degrade(Plant* plant) {
	// Already dead; no further degradation.
	cout << plant->getSpecies() << " is already dead." << endl;
}

void Dead::improve(Plant* plant) {
	cout << plant->getSpecies() << " cannot be revived from death." << endl;
}

string Dead::getStatusMessage(Plant* plant) {
	return plant->getSpecies() + " health: DEAD (remove from inventory) ";
}

bool Dead::isDead() {
	return true;
}

string Dead::getName() {
	return "dead";
}