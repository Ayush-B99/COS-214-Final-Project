#include "../include/Sprout.h"
#include "../include/Plant.h"
#include "../include/Mature.h"

void Sprout::grow(Plant *plant)
{
    if (plant->getCurrentCycleCount() >= plant->getSproutCyclesNeeded())
    {
        // Check if required resources are adequate AND plant is ready for stock
        if (plant->getWaterLevel() >= 60 && plant->getSunlightLevel() >= 60 && plant->getFertilizerLevel() >= 60)
        {
            plant->setGrowthState(new Mature());
            plant->resetCycleCount();
            // plant->notify();
            cout << plant->getSpecies() << " has matured!" << endl;
        }
    }
}

vector<string> Sprout::getRequiredCare()
{
    return {"water", "sunlight", "fertilizer", "prune"};
}

string Sprout::getStatusMessage(Plant *plant)
{
    int current = plant->getCurrentCycleCount();
    int needed = plant->getSproutCyclesNeeded();
    return plant->getSpecies() + " (Sprout): " + to_string(current) + "/" + to_string(needed) +
           " cycles | Water: " + to_string(plant->getWaterLevel()) + "%" +
           " | Sun: " + to_string(plant->getSunlightLevel()) + "%" +
           " | Fertilizer: " + to_string(plant->getFertilizerLevel()) + "%" +
           " | Prune: " + to_string(plant->getPruneLevel()) + "%" +
           " | Ready for Stock: " + (plant->isReadyForStock() ? "Yes" : "No");
}

string Sprout::getName()
{
    return "sprout";
}
