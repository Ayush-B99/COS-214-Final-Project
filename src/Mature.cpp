#include "../include/Mature.h"
#include "../include/Plant.h"

void Mature::grow(Plant *plant)
{
    if (plant->getCurrentCycleCount() >= plant->getMatureCyclesNeeded())
    {
        plant->resetCycleCount(); // TODO: add logic to make a plant die after 10 cycles in mature growth state
        plant->notify();
    }
}

vector<string> Mature::getRequiredCare()
{
    return {"Water", "sunlight", "fertilizer", "prune"};
}

string Mature::getStatusMessage(Plant *plant)
{
    int current = plant->getCurrentCycleCount();
    int needed = plant->getMatureCyclesNeeded();
    return plant->getSpecies() + " (Mature): " + to_string(current) + "/" + to_string(needed) + " care cycles completed";
}

bool Mature::isMature()
{
    return true;
}
