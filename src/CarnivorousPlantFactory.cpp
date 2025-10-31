#include "../include/CarnivorousPlantFactory.h"
#include "../include/ConcreteGrowthObserver.h"

CarnivorousPlantFactory::CarnivorousPlantFactory()
{
	// TODO - implement CarnivorousPlantFactory::CarnivorousPlantFactory
}

CarnivorousPlantFactory::~CarnivorousPlantFactory()
{
	// TODO - implement CarnivorousPlantFactory::~CarnivorousPlantFactory
}

Plant *CarnivorousPlantFactory::createSmallPlant()
{
	Sundew *sundew = new Sundew();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(sundew);
	return sundew;
}

Plant *CarnivorousPlantFactory::createMediumPlant()
{
	Pitcher *pitcher = new Pitcher();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(pitcher);
	return pitcher;
}

Plant *CarnivorousPlantFactory::createLargePlant()
{
	Nepenthes *nepenthes = new Nepenthes();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(nepenthes);
	return nepenthes;
}
