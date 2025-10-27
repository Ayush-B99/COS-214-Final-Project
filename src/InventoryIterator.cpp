#include "../include/InventoryIterator.h"

InventoryIterator::InventoryIterator(PlantNode* root) {
	this->root = root;
	this->currentNode = nullptr;
	this->indexInNode = 0;
	
	reset(); //push left and position at first index
}

InventoryIterator::~InventoryIterator() {
	//iterator does not own any dynamic memory
}

void InventoryIterator::pushLeft(PlantNode* node) {
	while (node){
		nodeStack.push(node);
		node = node->getLeft();
	}
}

void InventoryIterator::reset() {
	//clear nodeStack
	while (!nodeStack.empty()){
		nodeStack.pop();
	}

	pushLeft(root);

	currentNode = nullptr;
	indexInNode = 0;

	//find the first valid node
	while (!nodeStack.empty()){
		currentNode = nodeStack.top();
		nodeStack.pop();
		pushLeft(currentNode->getRight());

		if (!currentNode->getPlants().empty()){
			indexInNode = 0;
			return;
		}
	}
	//no valid nodes in the tree
	currentNode = nullptr;


}

Plant* InventoryIterator::next() {
	//default to fine grained traversal
	return nextFine();
}

Plant* InventoryIterator::nextFine() {
	if (!hasNext()) return nullptr;

    //advance within current node if possible
    if (currentNode && indexInNode + 1 < currentNode->getPlants().size())
    {
        return currentNode->getPlants().at(++indexInNode);
    }

    //otherwise go to next valid node
    while (!nodeStack.empty())
    {
        PlantNode* node = nodeStack.top();
        nodeStack.pop();
        pushLeft(node->getRight());

        if (node->getPlants().empty()){
			continue;
		}

        currentNode = node;
        indexInNode = 0;
        return currentNode->getPlants().front();
    }

	//default if found the last node
    currentNode = nullptr;
    return nullptr;
}

Plant* InventoryIterator::nextCoarse() {
	if (!hasNext()) return nullptr;

	//move forward within current node if we can
	if (currentNode && indexInNode + 1 < currentNode->getPlants().size()){
		return currentNode->getPlants().at(++indexInNode);
	}

	//otherwise move to the next valid node
	while (!nodeStack.empty()){
		PlantNode* node = nodeStack.top();
		nodeStack.pop();
		pushLeft(node->getRight());

		//skip invalid nodes
		if (node->getPlants().empty()){
			continue;
		}

		currentNode = node;
		indexInNode = 0;
		return currentNode->getPlants().at(indexInNode);
	}

	//no valid index found, end of tree
	currentNode = nullptr;
	return nullptr;
}

Plant* InventoryIterator::currentPlant() {
	if (!currentNode || currentNode->getPlants().empty()){
		return nullptr;
	}
	///maybe change this as it does not take overflow into consideration
	if (indexInNode >= currentNode->getPlants().size()){
		return nullptr;
	}
	return currentNode->getPlants().at(indexInNode);
}

bool InventoryIterator::hasNext() {
	if (!currentNode){
		return false;
	}

	//are there still plants left in this node
	if (indexInNode + 1 < currentNode->getPlants().size()){
		return true;
	}

	//else if there is another valid node
	return hasNextNode();

}

bool InventoryIterator::hasNextNode(){
	stack<PlantNode*> temp = nodeStack;
	PlantNode* tempNode = currentNode;
	size_t tempIndex = indexInNode;

	PlantNode* node = tempNode;

	while (true){
		//go to next node (leftmost of right subtree)
		if (node && node->getRight()){
			node = node->getRight();
			while (node && node->getLeft()){
				node = node->getLeft();
			}
		} else {
			if (temp.empty()){
				return false;
			}
			node = temp.top();
			temp.pop();
		}

		if (node && !node->getPlants().empty()){
			return true;
		}
		if (temp.empty() && (!node || node->getPlants().empty())){
			return false;
		}
	}
}

map<PlantNode*, int> InventoryIterator::getPosition() {
	if (!currentNode){
		return {};
	}
	return {{currentNode, indexInNode}};
}



void InventoryIterator::setPosition(map<PlantNode*, int>& pos) {
	if (pos.empty()) return;

	currentNode = pos.begin()->first;
	indexInNode = pos.begin()->second;

	///dont know if we need to repopulate nodestack for traversal
}

