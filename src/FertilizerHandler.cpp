#include "../include/FertilizerHandler.h"
#include "../include/Fertilizer.h"

FertilizerHandler::~FertilizerHandler()
{
}

void FertilizerHandler::handleCareRequest(Plant *plant)
{
    cout << "FertilizerHandler checking if plant needs fertilizer..." << endl;
    cout << plant->needsFertilizer() << endl;

    if (plant->needsFertilizer())
    {
        Fertilizer *fertilizerCmd = new Fertilizer(plant);
        fertilizerCmd->execute();
        delete fertilizerCmd;

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

void FertilizerHandler::message()
{
    cout << "CHAIN: Fertilizer has been provided to the plant." << endl;
}