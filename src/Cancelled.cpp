#include "../include/Cancelled.h"

Cancelled::Cancelled(){
	cout << "Cancelling your order :(\n";
}

void Cancelled::proceed(Order* order){
	// cout << "Order has been cancelled. Cannot proceed\n";
}

void Cancelled::cancel(Order* order){
	cout << "Order is already cancelled.\n";
}

string const Cancelled::getName(){
	return "cancelled";
}
