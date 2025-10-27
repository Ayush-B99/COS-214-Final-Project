#include "../include/WaterHandler.h"
#include "../include/Water.h"

void WaterHandler::handleCareRequest(Plant *plant)
{
	if (plant->needsWater())
	{
		Water *waterCmd = new Water(plant);
		waterCmd->execute();
		delete waterCmd;
		message();
	}
	else if (next)
	{
		next->handleCareRequest(plant);
	}
}

void WaterHandler::message()
{
	cout << "CHAIN: Water has been provided to the plant.";
}
