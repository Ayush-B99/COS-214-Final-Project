#include "../include/PruneHandler.h"
#include "../include/Prune.h"

PruneHandler::~PruneHandler()
{
}

void PruneHandler::handleCareRequest(Plant *plant)
{
    cout << "PruneHandler checking if plant is mature..." << endl;
    cout << plant->needsPrune() << endl;

    if (plant->needsPrune())
    {
        Prune *pruneCmd = new Prune(plant);
        pruneCmd->execute();
        delete pruneCmd;

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

void PruneHandler::message()
{
    cout << "CHAIN: Pruning has been provided to the plant.";
}
