#include "../include/CarnivorousPlantFactory.h"

CarnivorousPlantFactory::CarnivorousPlantFactory() {
	// TODO - implement CarnivorousPlantFactory::CarnivorousPlantFactory
	throw "Not yet implemented";
}

CarnivorousPlantFactory::~CarnivorousPlantFactory() {
	// TODO - implement CarnivorousPlantFactory::~CarnivorousPlantFactory

}

Plant* CarnivorousPlantFactory::createSmallPlant() {
	// TODO - implement CarnivorousPlantFactory::createSmallPlant
	return new Sundew();
}

Plant* CarnivorousPlantFactory::createMediumPlant() {
	// TODO - implement CarnivorousPlantFactory::createMediumPlant
	return new Pitcher();
}

Plant* CarnivorousPlantFactory::createLargePlant() {
	// TODO - implement CarnivorousPlantFactory::createLargePlant
	return new Nepenthes();
}
