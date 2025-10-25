#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"
#include "GrowthState.h"
#include "HealthState.h"
#include "GrowthObserver.h"

class Plant {

protected:
	string species;
	int waterLevel;
	int growthStage;
private:
	PlantCareHandler* careStrategy;
	GrowthState* growthState;
	HealthState* healthState;
	string climate;
	string description;
	double price;

public:
	Plant();

	Plant(string species);

	virtual ~Plant();

	virtual double getPrice();

	string getDescription();

	string getClimate();

	virtual Plant* clone() = 0;

	void setCareStrategy(PlantCareHandler* strategy);

	void performWatering();

	void setGrowthState(GrowthState* state);

	void grow();

	void setHealthState(HealthState* state);

	void updateHealth();

	void attach(GrowthObserver* observer);

	void detach(GrowthObserver* observer);

	void notify();

	// for decorator, since it can alter the prices and desc.
	virtual string getSpecies();
	virtual void setPrice(double newPrice);
	virtual void setDescription(string newDesc);
};

#endif
