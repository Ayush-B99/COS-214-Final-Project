#include "../include/Seed.h"
#include "../include/Sprout.h"
#include "../include/Plant.h"

void Seed::grow(Plant *plant)
{
	if (plant->getCurrentCycleCount() >= plant->getSeedCyclesNeeded())
	{
		if (plant->getWaterLevel() >= 60 && plant->getSunlightLevel() >= 60 && plant->getFertilizerLevel() >= 60)
		{
			plant->setGrowthState(new Sprout());
			plant->resetCycleCount();
			// plant->notify();
			// cout << plant->getSpecies() << " has sprouted!" << endl;
		}
	}
}

string Seed::getStatusMessage(Plant *plant)
{
	int current = plant->getCurrentCycleCount();
	int needed = plant->getSeedCyclesNeeded();
	return plant->getSpecies() + " (Seed): " + to_string(current) + "/" + to_string(needed) +
		   " cycles | Water: " + to_string(plant->getWaterLevel()) + "%" +
		   " | Sun: " + to_string(plant->getSunlightLevel()) + "%" + " | fertilizer: " + to_string(plant->getFertilizerLevel()) + "%";
}

vector<string> Seed::getRequiredCare()
{
	return {"water", "sunlight", "fertilizer"};
}

string Seed::getName()
{
	return "seed";
}
