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

//#include "PlantCareHandler.h"
//#include "GrowthState.h"
//#include "HealthState.h"
#include "GrowthObserver.h"

// this is NOT CORRECT I JUST DID THIS FOR TESTING SINCE IT HASNT BEEN IMPLEMENTED YET BE AWARE
class PlantCareHandler;
class GrowthState;
class HealthState;
class GrowthObserver;

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
	string size; //added this "small", "medium", "large"

	map<string, int> carePoints;
	int currentCycleCount;

	//growth cycle requirements
	int seedCyclesNeeded;
	int sproutCyclesNeeded;
	int matureCyclesNeeded;

	GrowthObserver* observer;

public:
	Plant();

	Plant(string species);

	virtual ~Plant();
	
	Plant(const Plant& other);

	virtual string getSpecies();

    virtual void setPrice(double newPrice);

    virtual void setDescription(string newDesc);

	virtual double getPrice();

    virtual string getDescription();

    virtual string getClimate();

	GrowthState* getGrowthState();

	HealthState* getHealthState();

    virtual Plant* clone() = 0;

	void setCareStrategy(PlantCareHandler* strategy);


	void setGrowthState(GrowthState* state);

	void grow();

	void setHealthState(HealthState* state);

	void updateHealth();

	void attach(GrowthObserver* observer);

	void detach(GrowthObserver* observer);

	void notify();

	//for growth states
	void intializeCareNeeds();

	//care action methods (command)
	void receiveWatering();
	void receiveSunlight();
	void receiveFertilizing();
	void receivePruning();

	void completeCareSession(); //called by the staff after all actions for the cycle are done

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

	//inventory helpers
	bool shouldRemoveFromInventory();
	bool isReadyForStock();
	bool isDead();
	bool isMature();

protected:
	//subclasses set their growth requirements
	void setGrowthRequirements(int seed, int sprout, int mature);
	void setSize(string s);

};

#endif
