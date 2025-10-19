#ifndef STOCKITERATOR_H
#define STOCKITERATOR_H

class StockIterator : Iterator {

private:
	PlantNode* root;
	map<PlantNode*, size_t> current;
	stack<PlantNode*> nodeStack;

public:
	StockIterator(PlantNode* root);

	~StockIterator();

	Plant* next();

	Plant* current();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void pushLeft(PlantNode* node);

	Plant* nextFine();

	PlantNode* nextCoarse();

	void setPosition(map<PlantNode*, size_t> pos);
};

#endif
