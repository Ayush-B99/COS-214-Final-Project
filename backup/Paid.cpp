#include "../include/Paid.h"

Paid::Paid(){
	cout << "Order has been paid!\n";
}

void Paid::proceed(Order* order){
	order->setState(new Completed());
}

void Paid::cancel(Order* order){
	order->setState(new Cancelled());
}

string const Paid::getName(){
	return "paid";
}