#include "../include/Fertilizer.h"

Fertilizer::Fertilizer(Plant *plant)
{
	receiver = plant;
}

void Fertilizer::execute()
{
	cout << "Execute fertilizer command" << endl;
	receiver->receiveFertilizing();
}