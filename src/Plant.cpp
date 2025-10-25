#include "../include/Plant.h"

Plant::Plant() {
	// TODO - implement Plant::Plant
	throw "Not yet implemented";
}

Plant::Plant(string species) {
	// TODO - implement Plant::Plant
	throw "Not yet implemented";
}

Plant::~Plant() {
	// TODO - implement Plant::~Plant
	throw "Not yet implemented";
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
	throw "Not yet implemented";
}

void Plant::setGrowthState(GrowthState* state) {
	this->growthState = state;
}

void Plant::grow() {
	// TODO - implement Plant::grow
	throw "Not yet implemented";
}

void Plant::setHealthState(HealthState* state) {
	this->healthState = state;
}

void Plant::updateHealth() {
	// TODO - implement Plant::updateHealth
	throw "Not yet implemented";
}

void Plant::attach(GrowthObserver* observer) {
	// TODO - implement Plant::attach
	throw "Not yet implemented";
}

void Plant::detach(GrowthObserver* observer) {
	// TODO - implement Plant::detach
	throw "Not yet implemented";
}

void Plant::notify() {
	// TODO - implement Plant::notify
	throw "Not yet implemented";
}
