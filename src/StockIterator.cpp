#include "../include/StockIterator.h"

StockIterator::StockIterator(PlantNode* root) {
	this->root = root;
	this->currentNode = nullptr;
	this->indexInNode = 0;

	reset(); //push left and position at first index
}

StockIterator::~StockIterator() {
	//does not own any dynamic memory
}

Plant* StockIterator::next() {
	return nextFine();
}

Plant* StockIterator::currentPlant() {
	if (!currentNode || indexInNode >= currentNode->getPlants().size()){
		return nullptr;
	}
	return currentNode->getPlants().at(indexInNode);
}

bool StockIterator::hasNext() {
	return (currentNode != nullptr);
}

bool StockIterator::hasNextNode(){
    stack<PlantNode*> tempStack = nodeStack;
    PlantNode* tempCurrent = currentNode;
    size_t tempIndex = indexInNode;

    // If currentNode has more nodes in its vector beyond tempIndex, then there is a next node only if you mean same node,
    // but for node-level "next node" we need to see if there exists another distinct node below the traversal.
    // Pop currentNode (if present on top) and look for next non-empty node.
    if (tempCurrent && !tempStack.empty() && tempStack.top() == tempCurrent) {
        tempStack.pop();
    }

    if (tempCurrent) {
        // check right subtree first
        PlantNode* r = tempCurrent->getRight();
        if (r) {
            // find leftmost in r
            PlantNode* n = r;
            while (n && n->getLeft()) n = n->getLeft();
            // check recursively if n has plants or its right descendants do
            stack<PlantNode*> s;
            if (n) s.push(n);
            while (!s.empty()) {
                PlantNode* t = s.top(); s.pop();
                if (!t->getPlants().empty()) return true;
                if (t->getRight()) {
                    PlantNode* m = t->getRight();
                    while (m) { s.push(m); m = m->getLeft(); }
                }
            }
        }
    }

    // then check nodes in stack
    while (!tempStack.empty()) {
        PlantNode* top = tempStack.top();
        tempStack.pop();
        if (!top->getPlants().empty()) return true;
        // simulate pushLeft(top->right)
        PlantNode* r = top->getRight();
        PlantNode* n = r;
        while (n && n->getLeft()) n = n->getLeft();
        if (n) {
            // quick DFS to find any non-empty node rooted at n
            stack<PlantNode*> s;
            s.push(n);
            while (!s.empty()) {
                PlantNode* t = s.top(); s.pop();
                if (!t->getPlants().empty()) return true;
                if (t->getRight()) {
                    PlantNode* m = t->getRight();
                    while (m) { s.push(m); m = m->getLeft(); }
                }
            }
        }
    }

    return false;
}

void StockIterator::reset() {
	//clear nodeStack
	while (!nodeStack.empty()){
		nodeStack.pop();
	}

	pushLeft(root);

	currentNode = nullptr;
	indexInNode = 0;

	//find the first valid node
	while (!nodeStack.empty()){
		PlantNode* top = nodeStack.top();
		if (!top->getPlants().empty()){
			//dont pop just yet, we need to use this node until we exhaust it
			currentNode = top;
			indexInNode = 0;
			return;
		}
		//skipp empty nodes by popping them and prepping their right subtree
		nodeStack.pop();
		pushLeft(top->getRight());

	}
	//no valid nodes, do nothing
	currentNode = nullptr;
	indexInNode = 0;
}

map<PlantNode*, int> StockIterator::getPosition() {
	if (!currentNode){
		return {};
	}
	return {{currentNode, indexInNode}};
}

void StockIterator::pushLeft(PlantNode* node) {
	while (node){
		nodeStack.push(node);
		node = node->getLeft();
	}
}

Plant* StockIterator::nextFine() {
	if (!currentNode){
		return nullptr;
	}

    //advance within current node if possible
	///fixed possibly: return the current plant not the next plant
	Plant* result = nullptr;
	//get current plant
	if (indexInNode < currentNode->getPlants().size()){
		result = currentNode->getPlants().at(indexInNode);
	} else {
		//handle overflow and fix later
		result = nullptr;
	}

	//advance the iterator state
    if (indexInNode + 1 < currentNode->getPlants().size()){
		indexInNode++;
		return result; //guaranteed to not be null by current plant get
	}

	//otherwise, we've reached the end of the node
	//pop current and move into its right subtree inorder
	if (!nodeStack.empty() && nodeStack.top() == currentNode){
		nodeStack.pop();
	} else {
		///add alt condition here if needed, but probably not
	}

	pushLeft(currentNode->getRight());

	//find the next nonempty node
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

	return result;
}

PlantNode* StockIterator::nextCoarse() {
	if (nodeStack.empty() && !currentNode)
        return nullptr;

    PlantNode* node = nullptr;

    // Case 1: first call or after reset
    if (!currentNode) {
        if (nodeStack.empty()) return nullptr;
        node = nodeStack.top();
        nodeStack.pop();
        pushLeft(node->getRight());
    } 
    else {
        // Case 2: move to next node in-order
        if (currentNode->getRight()) {
            pushLeft(currentNode->getRight());
        }

        if (nodeStack.empty()) {
            currentNode = nullptr;
            return nullptr;
        }

        node = nodeStack.top();
        nodeStack.pop();
        pushLeft(node->getRight());
    }

    currentNode = node;
    indexInNode = 0;
    return currentNode;
}

void StockIterator::setPosition(map<PlantNode*, int>& pos) {
	if (pos.empty()) return;

	currentNode = pos.begin()->first;
	indexInNode = pos.begin()->second;
}