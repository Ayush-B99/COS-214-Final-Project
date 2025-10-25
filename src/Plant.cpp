#include "../include/Plant.h"

Plant::Plant() : species("Unknown"), waterLevel(0), growthStage(0), careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A plant"), price(0.0){
	
}

Plant::Plant(string species) : species(species), waterLevel(0), growthStage(0),careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A " + species + " plant"), price(0.0) {
	// TODO - implement Plant::Plant
	
}

Plant::~Plant() {
	// only deallocate state and strat patterns for now
	
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
