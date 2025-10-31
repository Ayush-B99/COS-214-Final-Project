#include "../include/Stock.h"
#include "../include/Inventory.h"
#include "../include/Order.h" 

Stock::Stock() {
	stockCatalog = nullptr;

	cout << "A new instance of Stock has been created!\n";
}

Stock::~Stock() {
	//Stock NOW OWNS its plants, so we need to delete the tree properly
	if (stockCatalog) {
		delete stockCatalog;
		stockCatalog = nullptr;
	}
}

void Stock::getLowStockItems() {
	StockIterator* it = new StockIterator(stockCatalog);

	while (it->hasNextNode()){
		PlantNode* curr = it->nextCoarse();
		if (curr && curr->getPlants().size() <= 1){
			cout << "Low stock for " << curr->getKey() << " " << curr->getPlants().size() << " plants remaining.\n";
		}
	}
	delete it;
}

double Stock::getTotalStockValue() {
	return calculateValueRecursive(stockCatalog);
}

double Stock::calculateValueRecursive(PlantNode* node) {
	if (!node) return 0.0;
	
	double value = 0.0;
	
	// Sum plants in this node (safe for empty nodes)
	for (Plant* p : node->getPlants()) {
		if (p) {
			value += p->getPrice();
		}
	}
	
	// Add values from subtrees
	value += calculateValueRecursive(node->getLeft());
	value += calculateValueRecursive(node->getRight());
	
	return value;
}

StockIterator* Stock::createIterator() {
	return new StockIterator(this->stockCatalog);
}

void Stock::addPlant(Plant* plant) {
	if (!plant){
		cout << "Cannot add the plant, invalid or null,\n";
		return;
	}
	
	PlantNode* node = addNode(stockCatalog, plant->getSpecies());
	node->addPlant(plant);
}

void Stock::removePlant(Plant* plant) {
	PlantNode* node = findNode(stockCatalog, plant->getSpecies());
	if (plant == nullptr || node == nullptr){
		cout << "An appropriate node cannot be located for the plant. not removed\n";
		return;
	}

	if(node->removePlant(plant)){
		cout << "Plant removed from " << node->getKey() << " node\n";
	}

}

PlantNode* Stock::findNode(PlantNode* root, string key) {
	if (!root){
		return nullptr;
	}

	int compare = root->getKey().compare(key);

	if (compare == 0){
		return root;
	} else if (compare < 0) {
		return findNode(root->getRight(), key);
	} else {
		return findNode(root->getLeft(), key);
	}
}

PlantNode* Stock::addNode(PlantNode* root, string key) {
	if (!root) {
        if (!stockCatalog) {
            stockCatalog = new PlantNode(key);
            return stockCatalog;
        }
        return new PlantNode(key);
    }

    int compare = key.compare(root->getKey());

    if (compare == 0) {
        return root;
    } else if (compare < 0) {
        if (!root->getLeft()){
			root->setLeft(new PlantNode(key));
		}
        return addNode(root->getLeft(), key);
    } else {
        if (!root->getRight()){
            root->setRight(new PlantNode(key));
		}
        return addNode(root->getRight(), key);
    }
}

int Stock::getNodeCount() {
	return countNodesRecursive(stockCatalog);
}

// Add this private helper method (also add to Stock.h)
int Stock::countNodesRecursive(PlantNode* node) {
	if (!node) return 0;
	return 1 + countNodesRecursive(node->getLeft()) + countNodesRecursive(node->getRight());
}

int Stock::getPlantCount(){
	return countPlantsRecursive(stockCatalog);
}

int Stock::countPlantsRecursive(PlantNode* node) {
	if (!node) return 0;
	
	int count = node->getPlants().size();  // Safe: empty node returns 0
	count += countPlantsRecursive(node->getLeft());
	count += countPlantsRecursive(node->getRight());
	
	return count;
}

void Stock::print() {
	cout << "\n== Stock Tree Structure ==\n";
	cout << "== Contains " << getPlantCount() << " plants and " << getNodeCount() << " different species.\n";
	cout << "== Total value of stock: R" << getTotalStockValue() << endl;
	if (!stockCatalog){
		cout << "The tree is empty.\n";
	} else {
		printHelper(stockCatalog, "", false);
	}
	cout << "\n==============================\n";
}

void Stock::printHelper(PlantNode* node, string prefix, bool isLeft){
	if (!node) return;

    node->printNode(prefix, isLeft);

    PlantNode* left = node->getLeft();
    PlantNode* right = node->getRight();

    if (left || right) {
        if (left)
            printHelper(left, prefix + (isLeft ? "│   " : "    "), true);
        if (right)
            printHelper(right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

PlantNode* Stock::getRoot(){
	return stockCatalog;
}

vector<Plant*> Stock::removePlants(string key, GrowthState* state){
	vector<Plant*> matches;
	PlantNode* node = findNode(stockCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	matches = node->removeByGrowthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	return matches;
}

vector<Plant*> Stock::removePlants(string key, HealthState* state){
	vector<Plant*> matches;
	PlantNode* node = findNode(stockCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	matches = node->removeByHealthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	return matches;
}

vector<Plant*> Stock::removePlants(GrowthState* state){
	vector<Plant*> matches;
	stockCatalog = removeByGrowthRecursive(stockCatalog, state, matches);
	cout << matches.size() << " plants removed from the entire tree.\n";
	return matches;
}

vector<Plant*> Stock::removePlants(HealthState* state){
	vector<Plant*> matches;
    stockCatalog = removeByHealthRecursive(stockCatalog, state, matches);
    cout << matches.size() << " plants removed from the entire tree.\n";
    return matches;
}

PlantNode* Stock::removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches){
	if (!node) return nullptr;

    node->setLeft(removeByGrowthRecursive(node->getLeft(), state, matches));
    node->setRight(removeByGrowthRecursive(node->getRight(), state, matches));

    vector<Plant*> removed = node->removeByGrowthState(state);
    if (!removed.empty())
        matches.insert(matches.end(), removed.begin(), removed.end());

    return node;
}

PlantNode* Stock::removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches){
	if (!node) return nullptr;

	node->setLeft(removeByHealthRecursive(node->getLeft(), state, matches));
    node->setRight(removeByHealthRecursive(node->getRight(), state, matches));

    vector<Plant*> removed = node->removeByHealthState(state);
    if (!removed.empty())
        matches.insert(matches.end(), removed.begin(), removed.end());

    return node;	
}

PlantNode* Stock::removeNode(PlantNode* root, string key){
	if (!root) return nullptr;

	int compare = key.compare(root->getKey());

	if (compare < 0){
		root->setLeft(removeNode(root->getLeft(), key));
	} else if (compare > 0){
		root->setRight(removeNode(root->getRight(), key));
	}
	else{
		if (!root->getLeft()){
			PlantNode* right = root->getRight();
			root->setRight(nullptr);
			delete root;
			return right;
		} else if (!root->getRight()){
			PlantNode* left = root->getLeft();
			root->setLeft(nullptr);
			delete root;
			return left;
		} else {
			PlantNode* successor = root->getRight();
			while (successor->getLeft()) successor = successor->getLeft();
			root->addPlants(successor->getPlants());
			root->setRight(removeNode(root->getRight(), successor->getKey()));
		}
	}
	return root;
}

vector<Plant*> Stock::getPlants(string key){
	PlantNode* node = findNode(stockCatalog, key);
	if (!node || node->getPlants().empty()){
		cout << "No plants matching the given key.\n";
		return vector<Plant*>();
	}

	vector<Plant*> plants = node->getPlants();
	cout << plants.size() << " plants found matching the key " << key << endl;
	return plants;
}

vector<Plant*> Stock::getPlants(string key, GrowthState* state){
	vector<Plant*> matches;
    PlantNode* node = findNode(stockCatalog, key);
    if (!node) return matches;

    for (auto* p : node->getPlants())
        if (p->getGrowthState() == state)
            matches.push_back(p);
    return matches;
}

vector<Plant*> Stock::getPlants(string key, HealthState* state){
	vector<Plant*> matches;
    PlantNode* node = findNode(stockCatalog, key);
    if (!node) return matches;

    for (Plant* p : node->getPlants()){
        if (p->getHealthState()->getName() == state->getName()){
			matches.push_back(p);
		}  
	}
    return matches;
}

vector<Plant*> Stock::getPlants(GrowthState* state){
	vector<Plant*> matches;
    collectByGrowthRecursive(stockCatalog, state, matches);
    return matches;
}

void Stock::collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches){
	if (!node) return;
    for (Plant* p : node->getPlants()){
        if (p->getGrowthState()->getName() == state->getName()){
		matches.push_back(p);
		}
	}
    collectByGrowthRecursive(node->getLeft(), state, matches);
    collectByGrowthRecursive(node->getRight(), state, matches);	
}

vector<Plant*> Stock::getPlants(HealthState* state){
    vector<Plant*> matches;
    collectByHealthRecursive(stockCatalog, state, matches);
    return matches;
}

void Stock::collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches){
	if (!node) return;
	for (Plant* p : node->getPlants()){
		if (p->getHealthState()->getName() == state->getName()){
		matches.push_back(p);
		}
	}
	collectByHealthRecursive(node->getLeft(), state, matches);
	collectByHealthRecursive(node->getRight(), state, matches);
}

vector<Plant*> Stock::getAllPlants(){
	vector<Plant*> matches;
    collectAllPlantsRecursive(stockCatalog, matches);
    return matches;
}

void Stock::collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches){
	if (!node) return;
	for (Plant* p : node->getPlants()){
		matches.push_back(p);
	}
	collectAllPlantsRecursive(node->getLeft(), matches);
	collectAllPlantsRecursive(node->getRight(), matches);
}

void Stock::cleanUpDeadPlants(){
	HealthState* deadState = new Dead();

    vector<Plant*> deadPlants = removePlants(deadState);
    if (deadPlants.empty()) {
        cout << "No dead plants found for cleanup.\n";
        delete deadState;
        return;
    }

    cout << "Cleaning up " << deadPlants.size() << " dead plants...\n";
	
	// Stock now owns plants, so we need to delete them
	for (Plant* p : deadPlants) {
        if (p) delete p;
    }

	delete deadState;
}

void Stock::moveToOrder(Plant* plant, Order* order){
	if (!plant || !order) {
		cout << "Invalid plant or order pointer.\n";
		return;
	}

	// Check order state
	if (order->getState()->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted.\n";
		return;
	}

	// Remove from stock (this transfers ownership)
	if (plantInTree(plant)){
		removePlant(plant);
	} else {
		cout << "Plant not found in stock.\n";
		return;
	}

	// Add to order (order now owns the plant)
	order->addPlant(plant);
	cout << "A " << plant->getSpecies() << " has been added to order " << order->getId() << endl;
}

bool Stock::plantInTree(Plant* plant){
	PlantNode* node = findNode(stockCatalog, plant->getSpecies());

	if (!node) return false;

	return node->plantInNode(plant);
}
