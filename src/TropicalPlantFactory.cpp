#include "../include/TropicalPlantFactory.h"

TropicalPlantFactory::TropicalPlantFactory() {
	// TODO - implement TropicalPlantFactory::TropicalPlantFactory

}

TropicalPlantFactory::~TropicalPlantFactory() {
	// TODO - implement TropicalPlantFactory::~TropicalPlantFactory

}

Plant* TropicalPlantFactory::createSmallPlant() {
	// TODO - implement TropicalPlantFactory::createSmallPlant
	return new Nerve();
}

Plant* TropicalPlantFactory::createMediumPlant() {
	// TODO - implement TropicalPlantFactory::createMediumPlant
	return new BirdOfParadise();
}

Plant* TropicalPlantFactory::createLargePlant() {
	// TODO - implement TropicalPlantFactory::createLargePlant
	return new Rubber();
}
