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

	//find the first valid node with plants
	while (!nodeStack.empty()){
		PlantNode* top = nodeStack.top();
		if (!top->getPlants().empty()){
			//dont pop just yet, we need to use this node until we exhaust it
			currentNode = top;
			indexInNode = 0;
			return;
		}
		//skip empty nodes by popping them and prepping their right subtree
		nodeStack.pop();
		pushLeft(top->getRight());
	}
	//no valid nodes, do nothing
	currentNode = nullptr;
	indexInNode = 0;
}

Plant* InventoryIterator::next() {
	//default to fine grained traversal
	return nextFine();
}

Plant* InventoryIterator::nextFine() {
	if (!currentNode){
		return nullptr;
	}

	// Safety check: ensure current node has plants
	if (currentNode->getPlants().empty()) {
		// This shouldn't happen, but handle it gracefully
		currentNode = nullptr;
		return nullptr;
	}

	// Safety check: ensure indexInNode is within bounds
	if (indexInNode >= currentNode->getPlants().size()) {
		// Index out of bounds, reset to find next valid node
		if (!nodeStack.empty() && nodeStack.top() == currentNode){
			nodeStack.pop();
		}
		pushLeft(currentNode->getRight());
		
		// Find next non-empty node
		currentNode = nullptr;
		while (!nodeStack.empty()){
			PlantNode* top = nodeStack.top();
			if (!top->getPlants().empty()){
				currentNode = top;
				indexInNode = 0;
				break;
			}
			nodeStack.pop();
			pushLeft(top->getRight());
		}
		
		// Try again with new position
		if (currentNode && indexInNode < currentNode->getPlants().size()) {
			return nextFine();
		}
		return nullptr;
	}

	// Get current plant
	Plant* result = currentNode->getPlants().at(indexInNode);

	// Advance the iterator state
	indexInNode++;

	// Check if we need to move to next node
	if (indexInNode >= currentNode->getPlants().size()){
		// We've reached the end of the node, move to next
		if (!nodeStack.empty() && nodeStack.top() == currentNode){
			nodeStack.pop();
		}

		pushLeft(currentNode->getRight());

		// Find the next nonempty node
		currentNode = nullptr;
		while (!nodeStack.empty()){
			PlantNode* top = nodeStack.top();
			if (!top->getPlants().empty()){
				currentNode = top;
				indexInNode = 0;
				break;
			}

			nodeStack.pop();
			pushLeft(top->getRight());
		}
	}

	return result;
}	

PlantNode* InventoryIterator::nextCoarse() {
	// Skip empty nodes entirely
	while (true) {
		if (!currentNode && nodeStack.empty()) {
			return nullptr;
		}

		// If this is the first call
		if (!currentNode) {
			if (nodeStack.empty()) return nullptr;
			currentNode = nodeStack.top();
			nodeStack.pop();
		} 
		else {
			// Move to the next in-order node
			if (currentNode->getRight()) {
				pushLeft(currentNode->getRight());
			}

			if (nodeStack.empty()) {
				currentNode = nullptr;
				return nullptr;
			}

			currentNode = nodeStack.top();
			nodeStack.pop();
		}

		// Check if current node has plants
		if (!currentNode->getPlants().empty()) {
			indexInNode = 0;
			return currentNode;
		}
		
		// If current node is empty, continue to next node
	}
}

Plant* InventoryIterator::currentPlant() {
	if (!currentNode) {
		return nullptr;
	}
	
	// Safety check for empty vector
	if (currentNode->getPlants().empty()) {
		return nullptr;
	}
	
	// Safety check for index bounds
	if (indexInNode >= currentNode->getPlants().size()) {
		return nullptr;
	}
	
	return currentNode->getPlants().at(indexInNode);
}

bool InventoryIterator::hasNext() {
	if (!currentNode) {
		return false;
	}
	
	// Check if current node has plants at current index
	if (!currentNode->getPlants().empty() && indexInNode < currentNode->getPlants().size()) {
		return true;
	}
	
	// Check if there are more nodes with plants in the traversal
	stack<PlantNode*> tempStack = nodeStack;
	PlantNode* tempCurrent = currentNode;
	
	// Pop current node if it's on top
	if (!tempStack.empty() && tempStack.top() == tempCurrent) {
		tempStack.pop();
	}
	
	// Check right subtree of current node
	if (tempCurrent && tempCurrent->getRight()) {
		PlantNode* right = tempCurrent->getRight();
		// Do an in-order traversal to check for any non-empty nodes
		stack<PlantNode*> checkStack;
		PlantNode* checkNode = right;
		
		// Push all left nodes
		while (checkNode) {
			checkStack.push(checkNode);
			checkNode = checkNode->getLeft();
		}
		
		// Check all nodes in right subtree
		while (!checkStack.empty()) {
			PlantNode* node = checkStack.top();
			checkStack.pop();
			
			if (!node->getPlants().empty()) {
				return true;
			}
			
			// Push right subtree
			checkNode = node->getRight();
			while (checkNode) {
				checkStack.push(checkNode);
				checkNode = checkNode->getLeft();
			}
		}
	}
	
	// Check remaining nodes in stack
	while (!tempStack.empty()) {
		PlantNode* top = tempStack.top();
		tempStack.pop();
		
		if (!top->getPlants().empty()) {
			return true;
		}
		
		// Check right subtree
		if (top->getRight()) {
			PlantNode* right = top->getRight();
			stack<PlantNode*> checkStack;
			PlantNode* checkNode = right;
			
			while (checkNode) {
				checkStack.push(checkNode);
				checkNode = checkNode->getLeft();
			}
			
			while (!checkStack.empty()) {
				PlantNode* node = checkStack.top();
				checkStack.pop();
				
				if (!node->getPlants().empty()) {
					return true;
				}
				
				checkNode = node->getRight();
				while (checkNode) {
					checkStack.push(checkNode);
					checkNode = checkNode->getLeft();
				}
			}
		}
	}
	
	return false;
}

bool InventoryIterator::hasNextNode(){
	// Check if there's another node (empty or not) in the traversal
	stack<PlantNode*> tempStack = nodeStack;
	PlantNode* tempCurrent = currentNode;

	if (!tempCurrent && tempStack.empty()) {
		return false;
	}

	// Pop current node if it's on top
	if (tempCurrent && !tempStack.empty() && tempStack.top() == tempCurrent) {
		tempStack.pop();
	}

	// Check right subtree
	if (tempCurrent && tempCurrent->getRight()) {
		return true; // There's at least one more node
	}

	// Check if there are more nodes in stack
	return !tempStack.empty();
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

	// Note: This doesn't rebuild the stack, which could cause issues
	// For proper functionality, consider rebuilding the stack to maintain traversal state
}