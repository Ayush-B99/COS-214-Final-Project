#include "../include/ConcreteGrowthObserver.h"

ConcreteGrowthObserver::ConcreteGrowthObserver(Plant *plant)
{
	this->subject = plant; // create a shallow copy of the plant

	plant->attach(this); // attach this observer to the plant
}

ConcreteGrowthObserver::~ConcreteGrowthObserver()
{
	// no memory deallocated as the plant will delete the observer and as such the observer cannot redelete the same plant
}

void ConcreteGrowthObserver::onGrowthChange()
{

	this->state = subject->getHealthState(); // update observer state

	// cout<< "Observer received message from plant" << subject->getSpecies() << " about growth change." << endl;

	if (dynamic_cast<NeedsCare *>(state)) // test if plant needs care
	{
		// cout<< "BEGIN CHAIN" << endl;
		subject->handleCareRequest(); // start chain of responsibility to handle care
	}
}
