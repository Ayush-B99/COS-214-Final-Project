#include "../include/Sun.h"

Sun::Sun(Plant *plant)
{
	receiver = plant;
}

void Sun::execute()
{
	// cout<< "Execute sun command" << endl;
	receiver->receiveSunlight();
}
