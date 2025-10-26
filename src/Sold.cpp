#include "../include/Sold.h"
#include "../include/Plant.h"

void Sold::grow(Plant *plant)
{
    // Sold plants do not grow further
}

vector<string> Sold::getRequiredCare()
{
    return {}; // No care needed for sold plants
}

string Sold::getStatusMessage(Plant *plant)
{
    return plant->getSpecies() + " (Sold): This plant has been sold and is no longer in the inventory.";
}

bool Sold::isSold()
{
    return true;
}