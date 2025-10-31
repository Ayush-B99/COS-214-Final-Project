#include "../include/Mature.h"
#include "../include/Plant.h"

void Mature::grow(Plant *plant)
{
    // Mature plants don't grow further automatically
    // They either get sold manually or die after 10 cycles (handled in Plant::tick())
    // The plant is already ready for stock at this point
}

vector<string> Mature::getRequiredCare()
{
    return {};
}

string Mature::getStatusMessage(Plant *plant)
{
        int current = plant->getCurrentCycleCount();
        string output;
        if (plant->isMature() && !plant->isDead()) {
            output = "Ready for stock!";
        }
        else {
            output = "Not ready for stock";
        }

        if (plant->isDead()) {
            output = "DEAD";
        }

    return plant->getSpecies() + " (Mature): " + to_string(current) + "/10 cycles until auto-death" +
           " | Water: " + to_string(plant->getWaterLevel()) + "%" +
           " | Sun: " + to_string(plant->getSunlightLevel()) + "%" +
           " | Fertilizer: " + to_string(plant->getFertilizerLevel()) + "%" +
           " | Prune: " + to_string(plant->getPruneLevel()) + "%" +
           " | Status: " + output;
}

bool Mature::isMature()
{
    return true;
}

string Mature::getName() {
    return "mature";
}