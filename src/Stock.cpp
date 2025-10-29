#include "../include/Stock.h"
#include "../include/Inventory.h" //only way to resolve these weird dependencies
#include "../include/Order.h" 

Stock::Stock() {
	stockCatalog = nullptr;

	cout << "A new instance of Stock has been created!\n";
}

Stock::~Stock() {
	//stock does not own its plant* since its a shallow copy subset
	stockCatalog = nullptr;
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
	double val = 0;
	StockIterator* it = new StockIterator(this->stockCatalog);

	//iterate through each plant
	while (it->hasNext()){
		Plant* current = it->currentPlant();
		if (current){
			val += current->getPrice();
		}
		it->nextFine();
	}
	delete it;
	return val;
}

StockIterator* Stock::createIterator() {
	return new StockIterator(this->stockCatalog);
}

void Stock::addPlant(Plant* plant) {
	if (!plant){
		cout << "Cannot add the plant, invalid or null,\n";
		return;
	}
	
	//addNode will guarantee that we have access to the node we need, either its in the tree or we find it
	PlantNode* node = addNode(stockCatalog, plant->getSpecies());
	//add to PlantNodes vector
	node->addPlant(plant);
}

void Stock::removePlant(Plant* plant) {
	//first findNode, if not found plant cannot be in the tree
	PlantNode* node = findNode(stockCatalog, plant->getSpecies());
	if (plant == nullptr || node == nullptr){
		cout << "An appropriate node cannot be located for the plant. not removed\n";
		return;
	}

	//now try to remove from this node's vector
	if(node->removePlant(plant)){
		cout << "Plant removed from " << node->getKey() << " node\n";
	}

	//allow for empty nodes 
	
}

PlantNode* Stock::findNode(PlantNode* root, string key) {
	if (!root){
		//cout << "Empty plant catalog.\n";
		return nullptr;
	}

	//compare key values until we find the correct node
	int compare = root->getKey().compare(key);

	if (compare == 0){
		//cout << "Found a matching node!\n";
		return root;
	} else if (compare < 0) {
		return findNode(root->getRight(), key);
	} else {
		return findNode(root->getLeft(), key);
	}
}

PlantNode* Stock::addNode(PlantNode* root, string key) {
	if (!root) {
        if (!stockCatalog) { //tree is empty at the global level
            stockCatalog = new PlantNode(key);
            return stockCatalog;
        }
        return new PlantNode(key); //failsafe
    }

    int compare = key.compare(root->getKey());

    if (compare == 0) { //duplicate, do nothing but return 
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
	int count = 0;
	StockIterator it(stockCatalog);

	//now jump to each next distinct node
	while (true){
		PlantNode* p = it.nextCoarse();
		if (!p) break; //null if end of tree
		count++;
	}

	return count;
}

int Stock::getPlantCount(){
		StockIterator* it = new  StockIterator(this->stockCatalog);
	int i = 0;

	while (it->hasNext()){
		i++;
		it->nextFine();
	}
	delete it;
	return i;
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

    //print current nod e and all of its plants
    node->printNode(prefix, isLeft);

    PlantNode* left = node->getLeft();
    PlantNode* right = node->getRight();

    //if both exist, right is considered "below" left for symmetry
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
	//find node where the plant should be
	PlantNode* node = findNode(stockCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	//otherwise, search the node for matches
	matches = node->removeByGrowthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	//if node became empty, remove the node from the tree, and update the root
	

	return matches;
}

vector<Plant*> Stock::removePlants(string key, HealthState* state){
	vector<Plant*> matches;
	//find node where the plant should be
	PlantNode* node = findNode(stockCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	//otherwise, search the node for matches
	matches = node->removeByHealthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	//if node became empty, remove the node from the tree, and update the root
	

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
	//end of branch
	if (!node) return nullptr;

    // recurse into children first (post-order)
    node->setLeft(removeByGrowthRecursive(node->getLeft(), state, matches));
    node->setRight(removeByGrowthRecursive(node->getRight(), state, matches));

    // remove matching plants from this node
    vector<Plant*> removed = node->removeByGrowthState(state);
    if (!removed.empty())
        matches.insert(matches.end(), removed.begin(), removed.end());

    // if node has no plants now, remove the node from this subtree
    if (node->getPlants().empty()) {
        // removeNode expects a subtree root and key; it returns the new subtree root
        PlantNode* newSubRoot = removeNode(node, node->getKey());
        return newSubRoot;
    }

    return node;
}

PlantNode* Stock::removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches){
	//end of branch
	if (!node) return nullptr;

	node->setLeft(removeByHealthRecursive(node->getLeft(), state, matches));
    node->setRight(removeByHealthRecursive(node->getRight(), state, matches));

    vector<Plant*> removed = node->removeByHealthState(state);
    if (!removed.empty())
        matches.insert(matches.end(), removed.begin(), removed.end());

    if (node->getPlants().empty()) {
        PlantNode* newSubRoot = removeNode(node, node->getKey());
        return newSubRoot;
    }

    return node;	
}

PlantNode* Stock::removeNode(PlantNode* root, string key){
	//not found
	if (!root) return nullptr;

	int compare = key.compare(root->getKey());

	//yoh i forgot how messed up deletion is in these things 
	if (compare < 0){
		root->setLeft(removeNode(root->getLeft(), key));
	} else if (compare > 0){
		root->setRight(removeNode(root->getRight(), key));
	}
	else{ //found the node to remove
		if (!root->getLeft()){
			PlantNode* right = root->getRight();
			root->setRight(nullptr);
			delete root; ///watch for memory fuck ups
			return right;
		} else if (!root->getRight()){
			PlantNode* left = root->getLeft();
			root->setLeft(nullptr);
			delete root;
			return left;
		} else { //find inorder successor and replace
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
		///todo: fix when states are finalized
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
	if (!node) return; //end of subtree
    for (Plant* p : node->getPlants()){
		///todo: fix when states are finalized
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
	if (!node) return; //end of subtree
	for (Plant* p : node->getPlants()){
		///todo: fix when states are finalized
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
	if (!node) return; //end of subtree
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
        return;
    }

    cout << "Cleaning up " << deadPlants.size() << " dead plants...\n";
	
	//does not clean up any memory, since Inventory owns these plants

	delete deadState;
}

void Stock::moveToOrder(Plant* plant, Inventory* inventory, Order* order){
	//block depending on order state
	if (order->getState()->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted";
		return;
	}

	//remove from both stock and inventory
	if (plantInTree(plant)){
		removePlant(plant);
	}
	if (inventory->plantInTree(plant)){
		inventory->removePlant(plant);
	}

	order->addPlant(plant);
	cout << "a " << plant->getSpecies() << " has been added to order " << order->getId() << endl;

}

bool Stock::plantInTree(Plant* plant){
	//first find the node that it should belong to
	PlantNode* node = findNode(stockCatalog, plant->getSpecies());

	if (!node) return false;

	//now try to find the plant in the node

	return node->plantInNode(plant);
}