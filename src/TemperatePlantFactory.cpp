#include "../include/TemperatePlantFactory.h"

TemperatePlantFactory::TemperatePlantFactory() {
	// empty constructor
	
}

TemperatePlantFactory::~TemperatePlantFactory() {
	// no mem management needed for now
}

Plant* TemperatePlantFactory::createSmallPlant() {
	// TODO - implement TemperatePlantFactory::createSmallPlant
	return new Daisy();
}

Plant* TemperatePlantFactory::createMediumPlant() {
	return new Lilac();
}

Plant* TemperatePlantFactory::createLargePlant() {
	return new WhiteOak();
}
