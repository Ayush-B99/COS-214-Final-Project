#include "../include/FertilizerHandler.h"
#include "../include/Fertilizer.h"

void FertilizerHandler::handleCareRequest(Plant *plant)
{
    if (plant->needsFertilizer())
    {
        Fertilizer *fertilizerCmd = new Fertilizer(plant);
        fertilizerCmd->execute();
        delete fertilizerCmd;

        message();
    }
    else if (next)
    {
        next->handleCareRequest(plant);
    }
}

void FertilizerHandler::message()
{
    cout << "CHAIN: Fertilizer has been provided to the plant.";
}