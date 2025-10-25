#include "../include/Order.h"

Order::Order(string& orderId) {
	// TODO - implement Order::Order
	throw "Not yet implemented";
}

Order::~Order() {
	// TODO - implement Order::~Order
	throw "Not yet implemented";
}

void Order::submitted() {
	// TODO - implement Order::submitted
	throw "Not yet implemented";
}

void Order::paid() {
	// TODO - implement Order::paid
	throw "Not yet implemented";
}

void Order::cancelled() {
	// TODO - implement Order::cancelled
	throw "Not yet implemented";
}

void Order::completed() {
	// TODO - implement Order::completed
	throw "Not yet implemented";
}

void Order::addItem(Plant* item) {
	// TODO - implement Order::addItem
	throw "Not yet implemented";
}

void Order::removeItem(Plant* item) {
	// TODO - implement Order::removeItem
	throw "Not yet implemented";
}

vector<Plant*>& Order::getOrderItems() {
	// TODO - implement Order::getOrderItems
	throw "Not yet implemented";
}

double Order::calculateTotal() {
	// TODO - implement Order::calculateTotal
	throw "Not yet implemented";
}

Iterator* Order::createIterator() {
	// TODO - implement Order::createIterator
	throw "Not yet implemented";
}

double Order::getTotal() {
	return this->total;
}

string Order::getStateName() {
	// TODO - implement Order::getStateName
	throw "Not yet implemented";
}

OrderState* Order::getState() {
	return this->state;
}

void Order::setState(OrderState* state) {
	this->state = state;
}

string& Order::getId() {
	// TODO - implement Order::getId
	throw "Not yet implemented";
}
