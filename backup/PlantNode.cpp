#include "../include/PlantNode.h"

PlantNode::PlantNode(string name) {
	this->key = name;
	this->left = nullptr;
	this->right = nullptr;
	this->plants;
	cout << "New PlantNode with key " << name << " has been created!\n";
}

PlantNode::PlantNode(PlantNode* other) {
	this->key = other->key;
	left = nullptr;
	right = nullptr;

	//deep copy all plants in node
	for (Plant* p : other->plants){
		if (p){
			plants.push_back(p->clone());
		}
	}

	cout << "A copy of PlantNode with key " << other->key << " has been created!\n";

	//recursively copy left and right subtrees
	if (other->left){
		left = new PlantNode(other->left);
	}
	if (other->right){
		right = new PlantNode(other->right);
	}

}

PlantNode::~PlantNode() {
	for (Plant* p : plants){
		if (p) delete p;
	}

	//delete left and right subtrees recursively
	delete left;
	delete right;
}

const string PlantNode::getKey() {
	return this->key;
}

vector<Plant*> PlantNode::getPlants() {
	return this->plants;
}

PlantNode* PlantNode::getLeft() {
	return this->left;
}

PlantNode* PlantNode::getRight() {
	return this->right;
}

void PlantNode::setLeft(PlantNode* left) {
	this->left = left;
}

void PlantNode::setRight(PlantNode* right) {
	this->right = right;
}

void PlantNode::addPlant(Plant* plant) {
	plants.push_back(plant);
}

void PlantNode::addPlants(vector<Plant*> newPlants) {
	for (Plant* p : newPlants){
		plants.push_back(p);
	}
}

bool PlantNode::removePlant(Plant* plant) {
	if (!plant) return false;
	
	// Find and remove the plant
	for (size_t i = 0; i < plants.size(); i++){
		if (plants[i] == plant){
			plants.erase(plants.begin() + i);
			return true;
		}
	}
	
	// Plant not found in this node
	return false;
}

vector<Plant*> PlantNode::removeByHealthState(HealthState* state){
	vector<Plant*> matches;
	
	// Iterate backwards to safely erase while iterating
	for (int i = plants.size() - 1; i >= 0; i--){
		if (plants[i]->getHealthState()->getName() == state->getName()){
			matches.push_back(plants[i]);
			plants.erase(plants.begin() + i);
		}
	}
	
	return matches;
}

vector<Plant*> PlantNode::removeByGrowthState(GrowthState* state){
	vector<Plant*> matches;
	
	// Iterate backwards to safely erase while iterating
	for (int i = plants.size() - 1; i >= 0; i--){
		if (plants[i]->getGrowthState()->getName() == state->getName()){
			matches.push_back(plants[i]);
			plants.erase(plants.begin() + i);
		}
	}
	
	return matches;
}


bool PlantNode::isLeaf() {
	return (this->left == nullptr && this->right == nullptr);
}

void PlantNode::printNode(string prefix, bool isLeft){
	//no i did not figure out this formatting on my own, nobody else has to know that though
    //branch line and node index
    cout << prefix;
    cout << (isLeft ? "├── " : "└── ");
    cout << key << " (" << plants.size() << " plant/s)" << endl;

    //print details of each plant in vector
    for (size_t i = 0; i < plants.size(); i++) {
        cout << prefix;
        cout << (isLeft ? "│   " : "    "); //align with branch
        cout << "   > " << plants[i]->getSpecies();

        if (plants[i]->getGrowthState() && plants[i]->getHealthState()) {
            cout << " | Growth: " << plants[i]->getGrowthState()->getName()
                 << " | Health: " << plants[i]->getHealthState()->getName();
        }

        cout << " | Price: R" << plants[i]->getPrice() << endl;
    }
}

bool PlantNode::plantInNode(Plant* plant){
	for (Plant* p : plants){
		if (p == plant){ //pointer comparisons for exact match
			return true;
		}
	}
	return false;
}

