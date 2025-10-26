#include "../include/Seed.h"
#include "../include/Sprout.h"
#include "../include/Plant.h"

void Seed::grow(Plant* plant) {
	if (plant->getCurrentCycleCount() >= plant->getSeedCyclesNeeded()) {
		plant->setGrowthState(new Sprout());
		plant->resetCycleCount();
		plant->notify();
	}
}

string Seed::getStatusMessage(Plant* plant) {
	int current = plant->getCurrentCycleCount();
    int needed = plant->getSeedCyclesNeeded();
    return plant->getSpecies() + " (Seed): " + to_string(current) + "/" + to_string(needed) + " care cycles completed";
}

vector<string> Seed::getRequiredCare() {
	return {"Water", "sunlight"};
}


string Seed::getName() {
	return "seed";
}