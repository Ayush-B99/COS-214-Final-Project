#ifndef ORDER_H
#define ORDER_H

class Order : Storage {

private:
	OrderState* state;
	PlantNode* orderItems;
	string id;
	double total;

public:
	Order(string& orderId);

	~Order();

	void submitted();

	void paid();

	void cancelled();

	void completed();

	void addItem(Plant* item);

	void removeItem(Plant* item);

	vector<Plant*>& getOrderItems();

	double calculateTotal();

	OrderIterator* createIterator();

	double getTotal();

	string getStateName();

	OrderState* getState();

	void setState(OrderState* state);

	string& getId();
};

#endif
