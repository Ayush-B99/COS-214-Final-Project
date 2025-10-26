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
// #include "HealthState.h"

class ConcreteGrowthObserver;
class HealthState;

class Plant
{

protected:
	string species;
	int waterLevel;
	int growthStage;

private:
	PlantCareHandler *careStrategy;
	GrowthState *growthState;
	HealthState *healthState;
	string climate;
	string description;
	double price;
	string size; // added this "small", "medium", "large"

	// For tracking care points
	map<string, int> carePoints;
	int currentCycleCount;

	// growth cycle requirements
	int seedCyclesNeeded;
	int sproutCyclesNeeded;
	int matureCyclesNeeded;

	ConcreteGrowthObserver *observer;

public:
	Plant();

	Plant(string species);

	virtual ~Plant();

	virtual double getPrice();

	virtual string getDescription();

	virtual string getClimate();

	virtual Plant *clone() = 0;

	void setCareStrategy(PlantCareHandler *strategy);

	void setGrowthState(GrowthState *state);

	void grow();

	void setHealthState(HealthState *state);

	void updateHealth();

	void attach(ConcreteGrowthObserver *observer);

	void detach();

	void notify();

	// for decorator, since it can alter the prices and desc.
	virtual string getSpecies();
	virtual void setPrice(double newPrice);
	virtual void setDescription(string newDesc);

	GrowthState *getGrowthState();

	HealthState *getHealthState();

	void intializeCareNeeds();

	// care action methods (command)
	void receiveWatering();
	void receiveSunlight();
	void receiveFertilizing();
	void receivePruning();

	void completeCareSession(); // called by the staff after all actions for the cycle are done

	string getsize() const;
	int getCurrentCycleCount() const;
	int getSeedCyclesNeeded() const;
	int getSproutCyclesNeeded() const;
	int getMatureCyclesNeeded() const;
	void resetCycleCount();

	void printCurrentNeeds();
	void printGrowthStatus();
	void printHealthStatus();
	void printFullStatus();

	// inventory helpers
	bool shouldRemoveFromInventory();
	bool isReadyForStock();
	bool isDead();
	bool isMature();

protected:
	// subclasses set their growth requirements
	void setGrowthRequirements(int seed, int sprout, int mature);
	void setSize(string s);
};

#endif
