#include "../include/FertilizerDecorator.h"

// do i add more default parameters?
FertilizerDecorator::FertilizerDecorator(Plant* plant, string type) : PlantDecorator(plant), fertilizer(type) {
	// TODO - implement FertilizerDecorator::FertilizerDecorator
	int fertilizerType = 0;
    if (type == "Organic") 
	{
		fertilizerType = 1;
	}

    else if (type == "Liquid") 
	{
		fertilizerType = 2;
	}

    else if (type == "Slow-Release") 
	{
		fertilizerType = 3;
	}
    
    switch(fertilizerType) 
	{
        case 1: 
            fertilizerCost = 50.0;
            break;
        case 2:
            fertilizerCost = 100.0;
            break;
        case 3: 
            fertilizerCost = 200.0;
            break;
        default: 
            fertilizerCost = 50.0;
            fertilizer = "Organic";
            break;
    }
}

double FertilizerDecorator::getPrice() {
	// TODO - implement FertilizerDecorator::getPrice
	return PlantDecorator::getPrice() + fertilizerCost;
}

string FertilizerDecorator::getDescription() {
	// TODO - implement FertilizerDecorator::getDescription
	return PlantDecorator::getDescription() + " with " + fertilizer + " fertilizer";
}

Plant* FertilizerDecorator::clone() {
    return new FertilizerDecorator(decoratedPlant->clone(), fertilizer);
}
