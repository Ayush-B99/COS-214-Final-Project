#include "PlantNode.h"

PlantNode::PlantNode(string name) {
	// TODO - implement PlantNode::PlantNode
	throw "Not yet implemented";
}

PlantNode::PlantNode(PlantNode* other) {
	// TODO - implement PlantNode::PlantNode
	throw "Not yet implemented";
}

PlantNode::~PlantNode() {
	// TODO - implement PlantNode::~PlantNode
	throw "Not yet implemented";
}

stirng PlantNode::getKey() {
	// TODO - implement PlantNode::getKey
	throw "Not yet implemented";
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
	// TODO - implement PlantNode::addPlant
	throw "Not yet implemented";
}

void PlantNode::addPlants(vector<Plant*> newPlants) {
	// TODO - implement PlantNode::addPlants
	throw "Not yet implemented";
}

bool PlantNode::removePlant(Plant* plant) {
	// TODO - implement PlantNode::removePlant
	throw "Not yet implemented";
}

bool PlantNode::removeNode(string name) {
	// TODO - implement PlantNode::removeNode
	throw "Not yet implemented";
}

bool PlantNode::isLeaf() {
	// TODO - implement PlantNode::isLeaf
	throw "Not yet implemented";
}
