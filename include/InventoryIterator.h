#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

class InventoryIterator : Iterator {

private:
	PlantNode* root;
	map<PlantNode*, size_t> current;
	stack<PlantNode*> nodeStack;

public:
	InventoryIterator(PlantNode* root);

	~InventoryIterator();

	Plant* next();

	Plant* current();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void pushLeft(PlantNode* node);

	Plant* nextFine();

	PlantNode* nextCoarse();

	void setPosition(map<PlantNode*> pos);
};

#endif
