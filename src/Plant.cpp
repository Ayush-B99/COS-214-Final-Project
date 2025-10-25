#include "../include/Plant.h"

Plant::Plant() {
	// TODO - implement Plant::Plant
	
}

Plant::Plant(string species) {
	// TODO - implement Plant::Plant
	
}

Plant::~Plant() {
	// TODO - implement Plant::~Plant
	
}

double Plant::getPrice() {
	return this->price;
}

string Plant::getDescription() {
	return this->description;
}

string Plant::getClimate() {
	return this->climate;
}

void Plant::setCareStrategy(PlantCareHandler* strategy) {
	this->careStrategy = strategy;
}

void Plant::performWatering() {
	// TODO - implement Plant::performWatering
	
}

void Plant::setGrowthState(GrowthState* state) {
	this->growthState = state;
}

void Plant::grow() {
	// TODO - implement Plant::grow
	
}

void Plant::setHealthState(HealthState* state) {
	this->healthState = state;
}

void Plant::updateHealth() {
	// TODO - implement Plant::updateHealth
	
}

void Plant::attach(GrowthObserver* observer) {
	// TODO - implement Plant::attach
	
}

void Plant::detach(GrowthObserver* observer) {
	// TODO - implement Plant::detach
	
}

void Plant::notify() {
	// TODO - implement Plant::notify
	
}
