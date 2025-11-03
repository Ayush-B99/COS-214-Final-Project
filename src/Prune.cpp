#include "../include/Prune.h"

Prune::Prune(Plant *plant)
{
	this->receiver = plant;
}

void Prune::execute()
{
	// cout<< "Execute prune command" << endl;
	receiver->receivePruning();
	receiver->completeCareSession(); // i think this is gonna break when testing with full development of a plant (seed -> mature)
}
