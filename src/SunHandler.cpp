#include "../include/SunHandler.h"
#include "../include/Sun.h"

void SunHandler::handleCareRequest(Plant *plant)
{
    if (plant->needsSun())
    {
        Sun *sunCmd = new Sun(plant);
        sunCmd->execute();
        delete sunCmd;

        message();
    }
    else if (next)
    {
        next->handleCareRequest(plant);
    }
}

void SunHandler::message()
{
    cout << "CHAIN: Sunlight has been provided to the plant.";
}