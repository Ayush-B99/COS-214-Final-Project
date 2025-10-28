#include "../include/Order.h"

Order::Order(string& orderId) {
	this-> id = orderId;
	this->orderItems = new PlantNode(id);
	total = 0;
	state = new Draft();
}

Order::~Order() {
	//ownership of plants is transferred to order
	if (orderItems) delete orderItems;

	if (state) delete state;
}

void Order::submitted() {
	
}

void Order::paid() {

}

void Order::cancelled() {

}

void Order::completed() {

}

void Order::addItem(Plant* item) {
	//block adding based on state
	if (state->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted";
	}

	if (orderItems->plantInNode(item)){
		cout << "This plant is already in your order.\n";
		return;
	}

	orderItems->addPlant(item);
	cout << item->getSpecies() << " successfully added to your order!\n";

	calculateTotal();
}

void Order::removeItem(Plant* item, Inventory* inv) {
	if (state->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted";
	}

	if (!orderItems->removePlant(item)){
		cout << item->getSpecies() << " either not found or not removed.\n";
	}
	cout << item->getSpecies() << " successfully removed from your order!\n";

	//need to move the plant back into inventory
	///ideally move back to stock as well but we cant maintain all those pointers
	if (item){
		inv->addPlant(item);
	}
}

vector<Plant*>& Order::getOrderItems() {
	vector<Plant*> ret = orderItems->getPlants();
	return ret;
}

double Order::calculateTotal() {
	double running = 0;
	for (Plant* p : orderItems->getPlants()){
		if (p){
			running += p->getPrice();
		}
	}
	
	this->total = running;
	return total;
}

OrderIterator* Order::createIterator() {
	return new OrderIterator(orderItems);
}

double Order::getTotal() {
	return this->total;
}

string Order::getStateName() {
	return state->getName();
}

OrderState* Order::getState() {
	return this->state;
}

void Order::setState(OrderState* state) {
	this->state = state;
}

string& Order::getId() {
	return this->id;
}

void Order::print(){
	cout << "Order " << id 
		 << "Total: R" << total << endl;

	orderItems->printNode("", false);
}
