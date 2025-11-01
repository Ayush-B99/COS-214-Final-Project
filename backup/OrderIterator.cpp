#include "../include/OrderIterator.h"

OrderIterator::OrderIterator(PlantNode* order) {
	position = 0;
	if (order) this->order = order->getPlants(); 
}

OrderIterator::~OrderIterator() {
	//does not own any dynamic memory
}

Plant* OrderIterator::next() {
	if (!hasNext()){
		return nullptr;
	}
	return order.at(position++);
}

Plant* OrderIterator::currentPlant() {
	if (position < 0 || position >= static_cast<int>(order.size())){
		return nullptr;
	}
	return order.at(position);
}

bool OrderIterator::hasNext() {
	return position < static_cast<int>(order.size());
}

void OrderIterator::reset() {
	position = 0;
}

int OrderIterator::getPosition() {
	return position;
}

void OrderIterator::setPosition(int index) {
		if (index >= 0 && index < static_cast<int>(order.size())) {
		position = index;
	} else {
		cerr << "[OrderIterator] Invalid index: " << index
		          << " (size=" << order.size() << ")\n";
	}
}

bool OrderIterator::hasPrevious() {
	return position > 0;
}

Plant* OrderIterator::previous() {
	if (!hasPrevious()) return nullptr;
	return order.at(--position);
}