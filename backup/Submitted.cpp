#include "../include/Submitted.h"

Submitted::Submitted(){
	cout << "Order has been finalized and submitted!\n";
}

void Submitted::proceed(Order* order){
	order->setState(new Paid());
}

void Submitted::cancel(Order* order){
	order->setState(new Cancelled());
}

string const Submitted::getName(){
	return "submitted";
}