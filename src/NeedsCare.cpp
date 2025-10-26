#include "../include/NeedsCare.h"
#include "../include/Good.h"
#include "../include/Dead.h"
#include "../include/Plant.h"


void NeedsCare::degrade(Plant* plant) {
	cout << plant->getSpecies() << " has deteriorated to poor health." << endl;
	plant->setHealthState(new Dead());
	plant->notify();
}

void NeedsCare::improve(Plant* plant) {
	cout << plant->getSpecies() << " has improved to good health." << endl;
	plant->setHealthState(new Good());
	plant->notify();
}

string NeedsCare::getStatusMessage(Plant* plant) {
	return plant->getSpecies() + "  health: NEEDS CARE! (One more failed cycle = death) ";
}

bool NeedsCare::isDead() {
	return false;
}



