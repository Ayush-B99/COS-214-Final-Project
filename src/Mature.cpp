#include "../include/Mature.h"
#include "../include/Plant.h"
#include "../include/Sold.h"

void Mature::grow(Plant* plant) {
	if (plant->getCurrentCycleCount() >= plant->getMatureCyclesNeeded()) {
    	plant->setGrowthState(new Sold());
        plant->resetCycleCount();
        plant->notify();
    }
}

vector<string> Mature::getRequiredCare() {
	return {"Water", "sunlight", "fertilizer", "prune"};
}

string Mature::getStatusMessage(Plant* plant) {
    int current = plant->getCurrentCycleCount();
    int needed = plant->getMatureCyclesNeeded();
    return plant->getSpecies() + " (Mature): " + to_string(current) + "/" + to_string(needed) + " care cycles completed";
}

bool Mature::isMature() {
	return true;
}

string Mature::getName() {
    return "mature";
}

