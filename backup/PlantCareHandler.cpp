#include "../include/PlantCareHandler.h"
#include "../include/Plant.h"

PlantCareHandler::~PlantCareHandler()
{
}

void PlantCareHandler::setNext(PlantCareHandler *nextHandler)
{
	this->next = nextHandler;
}
