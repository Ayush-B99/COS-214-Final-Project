#include "../include/NeedsCare.h"
#include "../include/Good.h"
#include "../include/Dead.h"
#include "../include/Plant.h"


void NeedsCare::degrade(Plant* plant) {
 	cout << plant->getSpecies() << " health is critical! Resources very low." << endl;
	plant->setHealthState(new Dead());
}

void NeedsCare::improve(Plant* plant) {
	cout << plant->getSpecies() << " has improved to good health." << endl;
	plant->setHealthState(new Good());

}

string NeedsCare::getStatusMessage(Plant* plant) {
	return plant->getSpecies() + "  health: NEEDS CARE! Resources are low! ";
}

bool NeedsCare::isDead() {
	return false;
}

string NeedsCare::getName() {
	return "needsCare";
}


