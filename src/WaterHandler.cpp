#include "../include/WaterHandler.h"
#include "../include/Water.h"

WaterHandler::~WaterHandler()
{
}

void WaterHandler::handleCareRequest(Plant *plant)
{
	// cout<< "WaterHandler checking if plant needs water..." << endl;
	// cout<< plant->needsWater() << endl;
	if (plant->needsWater())
	{
		// cout<< "WaterHandler: Plant needs water. Executing watering command." << endl;
		Water *waterCmd = new Water(plant);
		waterCmd->execute();
		delete waterCmd;
		//  message();
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

void WaterHandler::message()
{
	// cout<< "CHAIN: Water has been provided to the plant.";
}
