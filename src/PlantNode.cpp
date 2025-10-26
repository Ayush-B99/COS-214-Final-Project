#include "../include/PlantNode.h"

PlantNode::PlantNode(string name) {
	this->key = name;
	this->left = nullptr;
	this->right = nullptr;
	this->plants;
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
		delete p;
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
	int i = 0;
	for (Plant* p : plants){
		if (p == plant){
			plants.erase(plants.begin() + i);
			return true;
		}
		i++;
	}
	//did not find anything or plants is empty
	return false;
}

vector<Plant*> PlantNode::removeByGrowthState(GrowthState* state){
	vector<Plant*> matches;
	for (Plant* p : plants){
		///todo: when states are fleshed out, use them to compare
		if (p->getGrowthState() == state){
			matches.push_back(p);
		}
	}
	return matches;
}

vector<Plant*> PlantNode::removeByHealthState(HealthState* state){
	vector<Plant*> matches;
	for (Plant* p : plants){
		///todo: when states are fleshed out, use them to compare
		if (p->getHealthState() == state){
			matches.push_back(p);
		}
	}
	return matches;
}

bool PlantNode::isLeaf() {
	return (this->left == nullptr && this->right == nullptr);
}
