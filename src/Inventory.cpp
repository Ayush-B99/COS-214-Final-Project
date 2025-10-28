#include "../include/Inventory.h"

Inventory::Inventory() {
	plantCatalog = nullptr;

	greenHouses.push_back(new TemperatePlantFactory()); //[0]
	greenHouses.push_back(new TropicalPlantFactory());
	greenHouses.push_back(new SucculentPlantFactory());
	greenHouses.push_back(new CarnivorousPlantFactory()); //[3]

	cout << "A new instance of Inventory has been created!\n";
}

Inventory::~Inventory() {
	//assume ownership of Plant factories`
	for (GreenHouse* g : greenHouses){
		if (g) delete g;
	}

	//will recursively delete according to PlantNode destructor
	if (plantCatalog) delete plantCatalog;
}

void Inventory::setClimate(GreenHouse* factory) {	greenHouses.push_back(factory);
	cout << "A new greenhouse has been added to inventory\n";
}

Plant* Inventory::addSmallPlant(GreenHouse* house) {
	if (!house){
		cout << "Can't add small plant, invalid greenhouse.\n";
		return nullptr;
	}

	Plant* toAdd = house->createSmallPlant();
	addPlant(toAdd);

	cout << "A new " << toAdd->getSpecies() << " has been added to Inventory!\n";
	return toAdd;
}

Plant* Inventory::addMediumPlant(GreenHouse* house) {
	if (!house){
		cout << "Can't add small plant, invalid greenhouse.\n";
		return nullptr;
	}

	Plant* toAdd = house->createMediumPlant();
	addPlant(toAdd);

	cout << "A new " << toAdd->getSpecies() << " has been added to Inventory!\n";
	return toAdd;
}

Plant* Inventory::addLargePlant(GreenHouse* house) {
	if (!house){
		cout << "Can't add small plant, invalid greenhouse.\n";
		return nullptr;
	}

	Plant* toAdd = house->createLargePlant();
	addPlant(toAdd);

	cout << "A new " << toAdd->getSpecies() << " has been added to Inventory!\n";
	return toAdd;
}

void Inventory::addPlantPrototype(Plant* prototype) {
	if (!prototype){
		cout << "Can't clone and add plant, invalid input\n";
	}

	Plant* cloned = prototype->clone();
	addPlant(cloned);

	cout << "A " << prototype->getSpecies() << " has been cloned and added to Inventory!\n";
}

InventoryIterator* Inventory::createIterator() {
	return new InventoryIterator(this->plantCatalog);
}

int Inventory::getPlantCount() {
	InventoryIterator* it = new  InventoryIterator(this->plantCatalog);
	int i = 0;

	while (it->hasNext()){
		i++;
		it->nextFine();
	}
	delete it;
	return i;
}

GreenHouse* Inventory::getTemperateFactory() {
	return greenHouses[0];
}

GreenHouse* Inventory::getCarnivorousFactory() {
	return greenHouses[3];
}

GreenHouse* Inventory::getSucculentFactory() {
	return greenHouses[2];
}

GreenHouse* Inventory::getTropicalFactory() {
	return greenHouses[1];
}

void Inventory::addPlant(Plant* plant) {
	if (!plant){
		cout << "Cannot add the plant, invalid or null,\n";
		return;
	}
	
	//addNode will guarantee that we have access to the node we need, either its in the tree or we find it
	PlantNode* node = addNode(plantCatalog, plant->getSpecies());
	//add to PlantNodes vector
	node->addPlant(plant);
}

void Inventory::removePlant(Plant* plant) {
	//first findNode, if not found plant cannot be in the tree
	PlantNode* node = findNode(plantCatalog, plant->getSpecies());
	if (plant == nullptr || node == nullptr){
		cout << "An appropriate node cannot be located for the plant. not removed\n";
		return;
	}

	//now try to remove from this node's vector
	if(node->removePlant(plant)){
		cout << "Plant removed from " << node->getKey() << " node\n";
	}

	
	//if node became empty, remove the node from the tree, and update the root
	if (node->getPlants().empty()){
		plantCatalog = removeNode(plantCatalog, node->getKey());
	}

}

vector<Plant*> Inventory::removePlants(string key, GrowthState* state) {
	vector<Plant*> matches;
	//find node where the plant should be
	PlantNode* node = findNode(plantCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	//otherwise, search the node for matches
	matches = node->removeByGrowthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	//if node became empty, remove the node from the tree, and update the root
	if (node->getPlants().empty()){
		plantCatalog = removeNode(plantCatalog, node->getKey());
	}

	return matches;
}

vector<Plant*> Inventory::removePlants(string key, HealthState* state){
	vector<Plant*> matches;
	//find node where the plant should be
	PlantNode* node = findNode(plantCatalog, key);

	if (node == nullptr){
		cout << "No plants matching those parameters could be found.\n";
		return matches;
	}

	//otherwise, search the node for matches
	matches = node->removeByHealthState(state);
	cout << matches.size() << " plants removed from " << key << ".\n";

	//if node became empty, remove the node from the tree, and update the root
	if (node->getPlants().empty()){
		plantCatalog = removeNode(plantCatalog, node->getKey());
	}

	return matches;
}

vector<Plant*> Inventory::removePlants(GrowthState* state){
	vector<Plant*> matches;
	plantCatalog = removeByGrowthRecursive(plantCatalog, state, matches);
	cout << matches.size() << " plants removed from the entire tree.\n";
	return matches;
}

vector<Plant*> Inventory::removePlants(HealthState* state) {
    vector<Plant*> matches;
    plantCatalog = removeByHealthRecursive(plantCatalog, state, matches);
    cout << matches.size() << " plants removed from the entire tree.\n";
    return matches;
}

//recursive helper functions for removal

PlantNode* Inventory::removeByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches){
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

PlantNode* Inventory::removeByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches){
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


vector<Plant*> Inventory::getPlants(string key){
	PlantNode* node = findNode(plantCatalog, key);
	if (!node || node->getPlants().empty()){
		cout << "No plants matching the given key.\n";
		return vector<Plant*>();
	}

	vector<Plant*> plants = node->getPlants();
	cout << plants.size() << " plants found matching the key " << key << endl;
	return plants;

}

vector<Plant*> Inventory::getPlants(string key, GrowthState* state){
    vector<Plant*> matches;
    PlantNode* node = findNode(plantCatalog, key);
    if (!node) return matches;

    for (auto* p : node->getPlants())
        if (p->getGrowthState() == state)
            matches.push_back(p);
    return matches;
}

vector<Plant*> Inventory::getPlants(string key, HealthState* state){
	vector<Plant*> matches;
    PlantNode* node = findNode(plantCatalog, key);
    if (!node) return matches;

    for (Plant* p : node->getPlants()){
		///todo: fix when states are finalized
        if (p->getHealthState()->getName() == state->getName()){
			matches.push_back(p);
		}  
	}
    return matches;
}

vector<Plant*> Inventory::getPlants(GrowthState* state){
	vector<Plant*> matches;
    collectByGrowthRecursive(plantCatalog, state, matches);
    return matches;
}

void Inventory::collectByGrowthRecursive(PlantNode* node, GrowthState* state, vector<Plant*>& matches){
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

vector<Plant*> Inventory::getPlants(HealthState* state){
    vector<Plant*> matches;
    collectByHealthRecursive(plantCatalog, state, matches);
    return matches;
}

void Inventory::collectByHealthRecursive(PlantNode* node, HealthState* state, vector<Plant*>& matches){
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

vector<Plant*> Inventory::getAllPlants(){
    vector<Plant*> matches;
    collectAllPlantsRecursive(plantCatalog, matches);
    return matches;
}

void Inventory::collectAllPlantsRecursive(PlantNode* node, vector<Plant*>& matches){
	if (!node) return; //end of subtree
	for (Plant* p : node->getPlants()){
		matches.push_back(p);
	}
	collectAllPlantsRecursive(node->getLeft(), matches);
	collectAllPlantsRecursive(node->getRight(), matches);
}

void Inventory::moveValidPlantsToStock(Stock* stock){
	    if (!stock) {
        cout << "Cant move plants to stock, invalid Storage pointer.\n";
        return;
    }

	GrowthState* matureState = new Mature();
	vector<Plant*> toMove = getPlants(matureState);

	if (toMove.empty()){
		cout << "No mature plants found to move.\n";
		return;
	}

	cout << "Copying " << toMove.size() << " mature plants to Stock...\n";

	for (Plant* p : toMove){
		if (p) stock->addPlant(p);
	}

	cout << "Plants successfully copied to Stock!\n";
	delete matureState;
}

void Inventory::cleanUpDeadPlants(){
    HealthState* deadState = new Dead();

    vector<Plant*> deadPlants = removePlants(deadState);
    if (deadPlants.empty()) {
        cout << "No dead plants found for cleanup.\n";
        return;
    }

    cout << "Cleaning up " << deadPlants.size() << " dead plants...\n";
	//cleans up memory since we genuinely delete them
	///check here for seg faults just in case
    for (Plant* p : deadPlants) {
        if (p) delete p;
    }

    cout << "All dead plants removed and memory freed.\n";
	delete deadState;
}



PlantNode* Inventory::removeNode(PlantNode* root, string key) {
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

PlantNode* Inventory::findNode(PlantNode* root, string key) {
	if (!root){
		cout << "Empty plant catalog.\n";
		return nullptr;
	}

	//compare key values until we find the correct node
	int compare = root->getKey().compare(key);

	if (compare == 0){
		cout << "Found a matching node!\n";
		return root;
	} else if (compare < 0) {
		return findNode(root->getRight(), key);
	} else {
		return findNode(root->getLeft(), key);
	}
}

PlantNode* Inventory::addNode(PlantNode* root, string key) {
    if (!root) {
        if (!plantCatalog) { //tree is empty at the global level
            plantCatalog = new PlantNode(key);
            return plantCatalog;
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

int Inventory::getNodeCount() {
	int count = 0;
	InventoryIterator it(plantCatalog);

	//now jump to each next distinct node
	while (true){
		Plant* p = it.nextCoarse();
		if (!p) break; //null if end of tree
		count++;
	}

	return count-1;
}

void Inventory::print() {
	cout << "\n== Inventory Tree Structure ==\n";
	cout << "== Contains " << getPlantCount() << " plants and " << getNodeCount() << " different species.\n";
	if (!plantCatalog){
		cout << "The tree is empty.\n";
	} else {
		printHelper(plantCatalog, "", false);
	}
	cout << "\n==============================\n";
}

void Inventory::printHelper(PlantNode* node, string prefix, bool isLeft){
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

PlantNode* Inventory::getRoot(){
	return plantCatalog;
}


