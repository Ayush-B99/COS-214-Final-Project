#include "../include/Water.h"

Water::Water(Plant *plant)
{
	receiver = plant;
}

void Water::execute()
{
	// cout << "Execute water command" << endl;

	receiver->receiveWatering();
}
