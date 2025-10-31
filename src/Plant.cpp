#include "../include/Plant.h"
#include "../include/Seed.h"
#include "../include/Good.h"
#include "../include/GrowthState.h"
#include "../include/HealthState.h"
#include "../include/ConcreteGrowthObserver.h"
#include "../include/NeedsCare.h"
#include "../include/Dead.h"

Plant::Plant() : species("Unknown"), waterLevel(100), sunlightLevel(100), fertilizerLevel(100), pruneLevel(100), growthStage(0), careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A plant"), price(0.0), observer(NULL), currentCycleCount(0), seedCyclesNeeded(2), sproutCyclesNeeded(3), matureCyclesNeeded(4), readyForStock(false)
{
	growthState = new Seed();
	healthState = new Good();
}

Plant::Plant(string species) : species(species), waterLevel(100), sunlightLevel(100), fertilizerLevel(100), pruneLevel(100), growthStage(0), careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A " + species + " plant"), price(0.0), observer(NULL), currentCycleCount(0), seedCyclesNeeded(2), sproutCyclesNeeded(3), matureCyclesNeeded(4), readyForStock(false)
{
	growthState = new Seed();
	healthState = new Good();
}

Plant::Plant(const Plant& other) : species(other.species), waterLevel(other.waterLevel), growthStage(other.growthStage), careStrategy(NULL), growthState(NULL), healthState(NULL), climate(other.climate), description(other.description), price(other.price), observer(NULL), currentCycleCount(other.currentCycleCount), seedCyclesNeeded(other.seedCyclesNeeded), sproutCyclesNeeded(other.sproutCyclesNeeded), matureCyclesNeeded(other.matureCyclesNeeded) {
	growthState = new Seed();
	healthState = new Good();
}

Plant::~Plant()
{
	// only deallocate state and strat patterns for now
	if (growthState)
	{
		delete growthState;
	}
	if (healthState)
	{
		delete healthState;
	}
}

double Plant::getPrice()
{
	return this->price;
}

string Plant::getDescription()
{
	return this->description;
}

string Plant::getClimate()
{
	return this->climate;
}

void Plant::setCareStrategy(PlantCareHandler *strategy)
{
	this->careStrategy = strategy;
}

void Plant::setGrowthState(GrowthState *state)
{
	if (this->growthState)
	{
		delete this->growthState;
	}
	this->growthState = state;
	cout << species << " has advanced to a new growth stage." << endl;
}

void Plant::grow()
{
	if (growthState)
	{
		growthState->grow(this);
	}
}

void Plant::setHealthState(HealthState *state)
{
	if (this->healthState)
	{
		delete this->healthState;
	}
	this->healthState = state;

	if (observer)
	{
		observer->onGrowthChange(); // notify observer of health state change
	}
}

// void Plant::updateHealth() { //Took this out because i need to come back to it, i dont have an update function yet and completeCareSession needs the improve and degrade functions to move from needsCare to good, I may be stupid but its probabaly something dumb asf :)
// 	if (healthState) {
// 		healthState->update(this);
// 	}

// }

void Plant::attach(ConcreteGrowthObserver *observer)
{
	this->observer = observer;
}

void Plant::detach()
{
	delete observer;
	this->observer = nullptr; // needs revisiting for memory management concerns
}

void Plant::notify()
{
	if (observer)
	{
		// observer->onGrowthChange(this);
		observer->onGrowthChange();
		// when creating the observer we must pass in the plant pointer so we dont need to pass it here
	}
}

string Plant::getSpecies()
{
	return species;
}

void Plant::setPrice(double newPrice)
{
	price = newPrice;
}

void Plant::setDescription(string newDesc)
{
	description = newDesc;
}

void Plant::receiveWatering()
{
	restoreWater();
}

void Plant::receiveSunlight()
{
	restoreSunlight();
}

void Plant::receiveFertilizing()
{
	restoreFertilizer();
}

void Plant::receivePruning()
{
	restorePrune();
}

void Plant::completeCareSession()
{
	if (healthState->getName() == "good")
	{
		return;
	}

	cout << "\nCare session completed for " << species << ". Resource levels:" << endl;
	cout << "  Water: " << waterLevel << "%" << endl;
	cout << "  Sun: " << sunlightLevel << "%" << endl;
	cout << "  Fertilizer: " << fertilizerLevel << "%" << endl;
	cout << "  Prune: " << pruneLevel << "%" << endl;

	vector<string> requiredCare = growthState->getRequiredCare();
	bool successfulCycles = true;

	for (const string &care : requiredCare)
	{
		if (care == "water" && waterLevel < 60)
			successfulCycles = false;
		if (care == "sunlight" && sunlightLevel < 60)
			successfulCycles = false;
		if (care == "fertilizer" && fertilizerLevel < 60)
			successfulCycles = false;
		if (care == "prune" && pruneLevel < 60)
			successfulCycles = false;
	}

	if (successfulCycles)
	{
		cout << species << " care cycle completed successfully!" << endl;
		currentCycleCount++;
		growthState->grow(this); // Check for growth advancement
		updateHealth();			 // Improve health if care was successful
	}
	else
	{
		cout << species << " care cycle incomplete!" << endl;
		// Health degradation is handled by updateHealthBasedOnResources()
	}

	cout << endl;
}

string Plant::getsize() const
{
	return size;
}

int Plant::getCurrentCycleCount() const
{
	return currentCycleCount;
}

int Plant::getSeedCyclesNeeded() const
{
	return seedCyclesNeeded;
}

int Plant::getSproutCyclesNeeded() const
{
	return sproutCyclesNeeded;
}

int Plant::getMatureCyclesNeeded() const
{
	return matureCyclesNeeded;
}

void Plant::resetCycleCount()
{
	currentCycleCount = 0;
}

void Plant::printCurrentNeeds()
{
	cout << "\n"
		 << species << " Current Resource Levels: " << endl;
	cout << "  Water: " << waterLevel << "%" << endl;
	cout << "  Sun: " << sunlightLevel << "%" << endl;
	cout << "  Fertilizer: " << fertilizerLevel << "%" << endl;
	cout << "  Prune: " << pruneLevel << "%" << endl;

	vector<string> required = growthState->getRequiredCare();
	if (!required.empty())
	{
		cout << "Required care actions: ";
		for (const string &care : required)
		{
			cout << care << " ";
		}
		cout << endl;
	}

	cout << "Ready for stock: " << (readyForStock ? "Yes" : "No") << endl;
	cout << endl;
}

void Plant::printGrowthStatus()
{
	cout << "\n"
		 << species << " Growth Status: " << endl;
	cout << "  " << growthState->getStatusMessage(this) << endl
		 << endl;
}

void Plant::printHealthStatus()
{
	cout << "\n"
		 << species << " Health Status: " << endl;
	cout << " " << healthState->getStatusMessage(this) << endl
		 << endl;
}

void Plant::printFullStatus()
{
	cout << "\n========================================" << endl;
	cout << "Plant: " << species << " (" << size << ", " << climate << ")" << endl;
	cout << "----------------------------------------" << endl;
	cout << growthState->getStatusMessage(this) << endl;
	cout << healthState->getStatusMessage(this) << endl;
	cout << "----------------------------------------" << endl;
	printCurrentNeeds();
	cout << "========================================\n"
		 << endl;
}

// inventory helpers (IDK IF SHAV HAS THESE YET)
bool Plant::shouldRemoveFromInventory()
{
	return growthState->isSold() || healthState->isDead();
}

bool Plant::isReadyForStock()
{
	return readyForStock && growthState->isMature() && !healthState->isDead();
}

void Plant::markReadyForStock()
{
	readyForStock = true;
	cout << species << " is ready to be moved to stock" << endl;
}

bool Plant::isDead()
{
	return healthState->isDead();
}

void Plant::setGrowthRequirements(int seed, int sprout, int mature)
{
	seedCyclesNeeded = seed;
	sproutCyclesNeeded = sprout;
	matureCyclesNeeded = mature;
}

void Plant::setSize(string s)
{
	size = s;
}

HealthState *Plant::getHealthState()
{
	return healthState;
}

GrowthState *Plant::getGrowthState()
{
	return growthState;
}

int Plant::getWaterLevel() const
{
	return waterLevel;
}

int Plant::getSunlightLevel() const
{
	return sunlightLevel;
}
int Plant::getFertilizerLevel() const
{
	return fertilizerLevel;
}

int Plant::getPruneLevel() const
{
	return pruneLevel;
}

void Plant::tick()
{

	if (healthState->isDead())
	{
		return;
	}

	waterLevel = max(0, waterLevel - 1);
	sunlightLevel = max(0, sunlightLevel - 1);
	fertilizerLevel = max(0, fertilizerLevel - 1);

	if (growthState->getName() == "sprout" || growthState->getName() == "mature")
	{
		pruneLevel = max(0, pruneLevel - 1);
	}

	updateHealth();

	if (growthState->isMature() && !healthState->isDead())
	{
		if (currentCycleCount >= 10)
		{
			setHealthState(new Dead());
		}
	}
}

void Plant::updateHealth()
{
	if (healthState->isDead())
	{
		return;
	}

	int avgLevel = (waterLevel + sunlightLevel + fertilizerLevel + pruneLevel) / 4;

	string currentHealth = healthState->getName();

	if (avgLevel <= 20)
	{ // below 20%
		if (currentHealth != "dead")
		{
			setHealthState(new Dead());
		}
	}
	else if (avgLevel <= 60)
	{ // below 60% - move to needsCare
		if (currentHealth == "good")
		{
			setHealthState(new NeedsCare());
		}
	}
	else
	{ // above 60% - move to good
		if (currentHealth == "needsCare")
		{
			setHealthState(new Good());
		}
	}
}

void Plant::restoreWater()
{
	waterLevel = 100;
	cout << species << " Water has been restored to 100%" << endl;
}

void Plant::restoreSunlight()
{
	sunlightLevel = 100;
	cout << species << " Sunlight has been restored to 100%" << endl;
}

void Plant::restoreFertilizer()
{
	fertilizerLevel = 100;
	cout << species << " Fertilizer has been restored to 100%" << endl;
}

void Plant::restorePrune()
{
	pruneLevel = 100;
	cout << species << " Prune has been restored to 100%" << endl;
}

void Plant::handleCareRequest()
{
	if (careStrategy)
	{
		careStrategy->handleCareRequest(this);
	}
	else
	{
		cout << "No care strategy set for " << species << endl;
	}
}

bool Plant::needsWater()
{
	return waterLevel <= 60;
}

bool Plant::needsSun()
{
	return sunlightLevel <= 60;
}

bool Plant::needsFertilizer()
{
	return fertilizerLevel <= 60;
}
bool Plant::needsPrune()
{
	return pruneLevel <= 60;
}

bool Plant::isMature()
{
	return growthState->isMature();
}