#include "../include/Good.h"
#include "../include/NeedsCare.h"
#include "../include/Plant.h"
#include "../include/Dead.h"

Good::~Good()
{
}

void Good::degrade(Plant *plant)
{
	cout << plant->getSpecies() << " is starting to need care." << endl;
	plant->setHealthState(new NeedsCare());

}

void Good::improve(Plant *plant)
{
	// Already in good state; no improvement needed.
	cout << plant->getSpecies() << " is already in good health." << endl;
}

string Good::getStatusMessage(Plant *plant)
{
	return plant->getSpecies() + " health: Good ";
}

bool Good::isDead()
{
	return false;
}

string Good::getName() {
	return "good";
}