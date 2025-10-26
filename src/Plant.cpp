#include "../include/Plant.h"
#include "../include/Seed.h"
#include "../include/Good.h"


Plant::Plant() : species("Unknown"), waterLevel(0), growthStage(0), careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A plant"), price(0.0), observer(NULL), currentCycleCount(0), seedCyclesNeeded(2), sproutCyclesNeeded(3), matureCyclesNeeded(4) {
	growthState = new Seed();
	healthState = new Good();
	intializeCareNeeds();
	
}

Plant::Plant(string species) : species(species), waterLevel(0), growthStage(0),careStrategy(NULL), growthState(NULL), healthState(NULL), climate("Unknown"), description("A " + species + " plant"), price(0.0), observer(NULL), currentCycleCount(0), seedCyclesNeeded(2), sproutCyclesNeeded(3), matureCyclesNeeded(4) {
	growthState = new Seed();
	healthState = new Good();
	intializeCareNeeds();
	
}

Plant::~Plant() {
	// only deallocate state and strat patterns for now
	if (growthState) {
		delete growthState;
	}
	if (healthState) {
		delete healthState;
	}
	if (careStrategy) {
		delete careStrategy;
	}
	
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


void Plant::setGrowthState(GrowthState* state) {
	if (this->growthState) {
		delete this->growthState;
	}
	this->growthState = state;
	intializeCareNeeds(); //reset care needs for new growth state
	cout << species << " has advanced to a new growth stage." << endl;
}

void Plant::grow() {
	if (growthState) {
		growthState->grow(this);
	}
	
}

void Plant::setHealthState(HealthState* state) {
	if (this->healthState) {
		delete this->healthState;
	}
	this->healthState = state;
}

// void Plant::updateHealth() { //Took this out because i need to come back to it, i dont have an update function yet and completeCareSession needs the improve and degrade functions to move from needsCare to good, I may be stupid but its probabaly something dumb asf :)
// 	if (healthState) {
// 		healthState->update(this);
// 	}
	
// }

void Plant::attach(GrowthObserver* observer) {
	this->observer = observer;
	
}

void Plant::detach(GrowthObserver* observer) {
	if (this->observer == observer) {
		this->observer = nullptr;
	}
	
}

void Plant::notify() {
	if (observer) {
		observer->onGrowthChange(this);
	}
	
}

string Plant::getSpecies() { 
	return species; 
}

void Plant::setPrice(double newPrice) { 
	price = newPrice; 
}

void Plant::setDescription(string newDesc) { 
	description = newDesc; 
}

void Plant::intializeCareNeeds() {
	carePoints.clear();
	vector<string> required = growthState->getRequiredCare();
	for (const string& care : required) {
		carePoints[care] = 0; //initialize care points to 0
	}
}

void Plant::receiveWatering() {
	if (carePoints.find("Water") != carePoints.end()) {
		carePoints["Water"] == 100; //made the point 100 to indicate care received
		cout << species << " was watered." << endl;
	}
}

void Plant::receiveSunlight() {
	if (carePoints.find("Sunlight") != carePoints.end()) {
		carePoints["Sunlight"] == 100; //made the point 100 to indicate care received
		cout << species << " received sunlight." << endl;
	}
}

void Plant::receiveFertilizing() {
	if (carePoints.find("Fertilize") != carePoints.end()) {
		carePoints["Fertilize"] == 100; //made the point 100 to indicate care received
		cout << species << " was fertilized." << endl;
	}
}

void Plant::receivePruning() {
	if (carePoints.find("Prune") != carePoints.end()) {
		carePoints["Prune"] == 100; //made the point 100 to indicate care received
		cout << species << " was pruned." << endl;
	}
}

void Plant::completeCareSession() {
	bool needsMet = true;

	cout << "\nCare session completed for " << species << ". Care summary:" << endl;

	for (const auto& need : carePoints) {
        if (need.second < 100) {
            needsMet = false;
            cout << "  Missing: " << need.first << endl;
        } else {
            cout << "  Completed: " << need.first << endl;
        }
    }

	if (needsMet) {
		cout << species << " care Cycle completed successfully." << endl;
		currentCycleCount++;
		healthState->improve(this); //restore health if it degraded
		growthState->grow(this); //check for growth advancement
	}
	else {
		cout << species << " care Cycle incomplete. Growth and health may be affected." << endl;
		healthState->degrade(this); //degrade health due to poor care
	}

	//reset care points for next cycle
	intializeCareNeeds();
	cout << endl;
}

string Plant::getsize() const {
	return size;
}

int Plant::getCurrentCycleCount() const {
	return currentCycleCount;
}

int Plant::getSeedCyclesNeeded() const {
	return seedCyclesNeeded;
}

int Plant::getSproutCyclesNeeded() const {
	return sproutCyclesNeeded;
}

int Plant::getMatureCyclesNeeded() const {
	return matureCyclesNeeded;
}

void Plant::resetCycleCount() {
	currentCycleCount = 0;
}

void Plant::printCurrentNeeds() {
    cout << "\n" << species << " Current Needs: " << endl;
    vector<string> required = growthState->getRequiredCare();
    
    if (required.empty()) {
        cout << "No care needed (Ready for stock)" << endl;
    } else {
        for (const string& care : required) {
            int points = carePoints[care];
            string status = (points >= 100) ? "Complete" : " Needed";
            cout << "  " << care << ": " << points << "/100 " << status << endl;
        }
    }
    cout << endl;
}

void Plant::printGrowthStatus() {
	cout << "\n" << species << " Growth Status: " << endl;
	cout << "  " << growthState->getStatusMessage(this) << endl << endl;
}

void Plant::printHealthStatus() {
	cout << "\n" << species << " Health Status: " << endl;
	cout << " " << healthState->getStatusMessage(this) << endl << endl;
	
}

void Plant::printFullStatus() {
	cout << "\n========================================" << endl;
    cout << "Plant: " << species << " (" << size << ", " << climate << ")" << endl;
    cout << "----------------------------------------" << endl;
    cout << growthState->getStatusMessage(this) << endl;
    cout << healthState->getStatusMessage(this) << endl;
    cout << "----------------------------------------" << endl;
    printCurrentNeeds();
    cout << "========================================\n" << endl;
}

//inventory helpers (IDK IF SHAV HAS THESE YET)
bool Plant::shouldRemoveFromInventory() {
	return growthState->isSold() || healthState->isDead();

}

bool Plant::isReadyForStock() {
	return growthState->isMature() && !healthState->isDead();
}

bool Plant::isDead() {
	return healthState->isDead();
}

void Plant::setGrowthRequirements(int seed, int sprout, int mature) {
    seedCyclesNeeded = seed;
    sproutCyclesNeeded = sprout;
    matureCyclesNeeded = mature;
}

void Plant::setSize(string s) {
    size = s;
}
