#include "../include/PruneHandler.h"
#include "../include/Prune.h"

void PruneHandler::handleCareRequest(Plant *plant)
{
    if (plant->isMature())
    {
        Prune *pruneCmd = new Prune(plant);
        pruneCmd->execute();
        delete pruneCmd;

        message();
    }
    else if (next)
    {
        next->handleCareRequest(plant);
    }
}

void PruneHandler::message()
{
    cout << "CHAIN: Pruning has been provided to the plant.";
}
