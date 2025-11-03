#include "../include/SucculentPlantFactory.h"
#include "../include/ConcreteGrowthObserver.h"

SucculentPlantFactory::SucculentPlantFactory()
{
	// TODO - implement SucculentPlantFactory::SucculentPlantFactory
}

SucculentPlantFactory::~SucculentPlantFactory()
{
	// TODO - implement SucculentPlantFactory::~SucculentPlantFactory
}

Plant *SucculentPlantFactory::createSmallPlant()
{
	HenAndChicks *henAndChicks = new HenAndChicks();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(henAndChicks);
	return henAndChicks;
}

Plant *SucculentPlantFactory::createMediumPlant()
{
	AloeVera *aloeVera = new AloeVera();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(aloeVera);
	return aloeVera;
}

Plant *SucculentPlantFactory::createLargePlant()
{
	Condelabra *condelabra = new Condelabra();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(condelabra);
	return condelabra;
}
