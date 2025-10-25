#include "../include/SucculentPlantFactory.h"

SucculentPlantFactory::SucculentPlantFactory() {
	// TODO - implement SucculentPlantFactory::SucculentPlantFactory
	throw "Not yet implemented";
}

SucculentPlantFactory::~SucculentPlantFactory() {
	// TODO - implement SucculentPlantFactory::~SucculentPlantFactory
	throw "Not yet implemented";
}

Plant* SucculentPlantFactory::createSmallPlant() {
	// TODO - implement SucculentPlantFactory::createSmallPlant
	return new HenAndChicks();
}

Plant* SucculentPlantFactory::createMediumPlant() {
	// TODO - implement SucculentPlantFactory::createMediumPlant
	return new AloeVera();
}

Plant* SucculentPlantFactory::createLargePlant() {
	// TODO - implement SucculentPlantFactory::createLargePlant
	return new Condelabra();
}
