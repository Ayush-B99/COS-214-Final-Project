#include "../include/Completed.h"

Completed::Completed(){
	cout << "Order has been completed! enjoy your plants\n";
}

void Completed::proceed(Order* order){
	cout << "Order has already concluded, cannot proceed.\n";
}

void Completed::cancel(Order* order){
	cout << "Order has already concluded, cannot cancel\n";
}

string const Completed::getName(){
	return "completed";
}
