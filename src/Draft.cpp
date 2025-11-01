#include "../include/Draft.h"

Draft::Draft(){
	// cout << "Order has been initialised as a draft!\n";
}

void Draft::proceed(Order* order){
	order->setState(new Submitted());
}

void Draft::cancel(Order* order){
	order->setState(new Cancelled());
}

string const Draft::getName(){
	return "draft";
}