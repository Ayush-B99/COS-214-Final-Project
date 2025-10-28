#include "../include/SunHandler.h"
#include "../include/Sun.h"

void SunHandler::handleCareRequest(Plant *plant)
{
    cout << "SunHandler checking if plant needs sunlight..." << endl;
    cout << plant->needsSun() << endl;

    if (plant->needsSun())
    {
        Sun *sunCmd = new Sun(plant);
        sunCmd->execute();
        delete sunCmd;

        message();
    }

    if (next)
    {
        next->handleCareRequest(plant);
    }
    else
    {
        plant->completeCareSession(); // complete care session if this is the last handler
    }
}

void SunHandler::message()
{
    cout << "CHAIN: Sunlight has been provided to the plant.";
}