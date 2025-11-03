#include "../include/Order.h"
#include "../include/Stock.h"
#include "../include/Inventory.h"

Order::Order(string orderId) {
	this-> id = orderId;
	this->orderItems = new PlantNode(id);
	total = 0;
	state = new Draft();

	cout << "Order " << orderId << " has been created successfully!\n";
}

Order::~Order() {
	//ownership of plants is transferred to order
	if (orderItems) delete orderItems;

	if (state) delete state;

	orderItems = nullptr;
	state = nullptr;
}

void Order::proceed(){
	if (state){
		state->proceed(this);
	}
}

void Order::cancel(Inventory* inv, Stock* stock){
	if (state){
		state->cancel(this);
	}
	
	// Return all plants back to stock only
	for (Plant* p : orderItems->getPlants()){
		if (p && stock){
			stock->addPlant(p);
		}
	}
	
	// Clear the order without deleting plants (stock owns them now)
	orderItems->getPlants().clear();
}


void Order::addPlant(Plant* item) {
	//block adding based on state
	if (state->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted";
		return;
	}

	if (orderItems->plantInNode(item)){
		cout << "This plant is already in your order.\n";
		return;
	}

	orderItems->addPlant(item);
	cout << item->getSpecies() << " successfully added to your order!\n";

	calculateTotal();
}

void Order::removePlant(Plant* item, Inventory* inv, Stock* stock) {
	if (state->getName() != "draft"){
		cout << "You cannot edit an order after it has been submitted.\n";
		return;
	}

	if (!orderItems->removePlant(item)){
		cout << item->getSpecies() << " either not found or not removed.\n";
		return;
	}
	
	cout << item->getSpecies() << " successfully removed from your order!\n";

	// Return plant to Stock only (Stock owns it)
	if (item && stock) {
		stock->addPlant(item);
	}
	
	calculateTotal();
}

vector<Plant*> Order::getOrderItems() {
	vector<Plant*> items = orderItems->getPlants();
	return items;
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
	if (!orderItems || orderItems->getPlants().empty()){
		cout << "Order " << id << " is empty. Engage in consumerism!\n";
		return;
	}

	cout << "Order " << id 
		 << " Total: R" << total 
		 << " in state " << state->getName() << endl;

	orderItems->printNode("", false);
}

//DO NOT USE THIS ITS JUST SO I STOP GETTING YELLED AT BY COMPILER
void Order::removePlant(Plant* plant){
	removePlant(plant, nullptr, nullptr);
}

PlantNode* Order::getNode(){
	return orderItems;
}

unique_ptr<Plant> Order::decorateWithPot(unique_ptr<Plant> p, const string& potType) {
    return make_unique<PotDecorator>(std::move(p), potType);
}

unique_ptr<Plant> Order::decorateWithFertilizer(unique_ptr<Plant> p, const string& fertilizerType) {
    return make_unique<FertilizerDecorator>(std::move(p), fertilizerType);
}