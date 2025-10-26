#include "../include/Sprout.h"
#include "../include/Plant.h"
#include "../include/Mature.h"

void Sprout::grow(Plant* plant) {
	if (plant->getCurrentCycleCount() >= plant->getSproutCyclesNeeded()) {
		plant->setGrowthState(new Mature());
		plant->resetCycleCount();
		plant->notify();
	}
}

vector<string> Sprout::getRequiredCare() {
	return {"Water", "sunlight", "fertilizer"};

}

string Sprout::getStatusMessage(Plant* plant) {
	int current = plant->getCurrentCycleCount();
	int needed = plant->getSproutCyclesNeeded();
	return plant->getSpecies() + " (Sprout): " + to_string(current) + "/" + to_string(needed) + " care cycles completed";
}

bool Sprout::isMature() {
	return false;
}

