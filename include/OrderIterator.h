#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H

class OrderIterator : Iterator {

private:
	PlantNode* order;
	int position;

public:
	OrderIterator(vector<Plant*>& collection);

	~OrderIterator();

	void next();

	Order* current();

	bool hasNext();

	void reset();

	map<string, int> getPosition();

	void setPosition(size_t index);
};

#endif
