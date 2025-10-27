#include "../include/PotDecorator.h"

// do i add more default parameters
//PotDecorator::PotDecorator(Plant* plant, string type) : PlantDecorator(plant), potType(type) {
PotDecorator::PotDecorator(std::unique_ptr<Plant> plant, std::string type) : PlantDecorator(std::move(plant)), potType(type) {
	// TODO - implement PotDecorator::PotDecorator
    
	int potSwitch = 0;
    if (type == "Clay") 
    {
        potSwitch = 1;
    }
    else if (type == "Ceramic") 
    {
        potSwitch = 2;
    }
    else if (type == "Plastic") 
    {
        potSwitch = 3;
    }
    else if (type == "Decorative") 
    {
        potSwitch = 4;
    }
    
	// bringing back switdh case RAHHHHHHH
    switch(potSwitch) 
    {
        case 1: 
            potCost = 60.0;
            break;
        case 2:
            potCost = 70.0;
            break;
        case 3: 
            potCost = 40.0;
            break;
        case 4: 
            potCost = 120.0;
            break;
        default: 
            potCost = 40.0;
            potType = "Plastic";
            break;
    }
}


double PotDecorator::getPrice() {
	// TODO - implement PotDecorator::getPrice
	return PlantDecorator::getPrice() + potCost;
}

string PotDecorator::getDescription() {
	// TODO - implement PotDecorator::getDescription
	return PlantDecorator::getDescription() + " in a " + potType + " pot";
}

Plant* PotDecorator::clone() {
    //return new PotDecorator(decoratedPlant->clone(), potType);
    return new PotDecorator(std::unique_ptr<Plant>(decoratedPlant->clone()), potType);
}
