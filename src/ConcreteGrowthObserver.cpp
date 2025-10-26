#include "../include/ConcreteGrowthObserver.h"
#include "../include/ConcreteGrowthMediator.h"

ConcreteGrowthObserver::ConcreteGrowthObserver(Plant *plant, ConcreteGrowthMediator *med)
{
	this->subject = plant; // create a shallow copy of the plant
	this->mediator = med;  // shallow copy of growth mediator

	plant->attach(this); // attach this observer to the plant
}

ConcreteGrowthObserver::~ConcreteGrowthObserver()
{
	// no memory deallocated as the plant will delete the observer and as such the observer cannot redelete the same plant
}

void ConcreteGrowthObserver::onGrowthChange()
{

	this->state = subject->getHealthState(); // update observer state

	if (dynamic_cast<NeedsCare *>(state)) // test if plant needs care
	{
		this->mediator->notify(subject); // notifes mediator with the plant that needs care
	}
}
