#include "../include/TropicalPlantFactory.h"
#include "../include/ConcreteGrowthObserver.h"

TropicalPlantFactory::TropicalPlantFactory()
{
	// TODO - implement TropicalPlantFactory::TropicalPlantFactory
}

TropicalPlantFactory::~TropicalPlantFactory()
{
	// TODO - implement TropicalPlantFactory::~TropicalPlantFactory
}

Plant *TropicalPlantFactory::createSmallPlant()
{
	Nerve *nerve = new Nerve();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(nerve);
	return nerve;
}

Plant *TropicalPlantFactory::createMediumPlant()
{
	BirdOfParadise *birdOfParadise = new BirdOfParadise();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(birdOfParadise);
	return birdOfParadise;
}

Plant *TropicalPlantFactory::createLargePlant()
{
	Rubber *rubber = new Rubber();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(rubber);
	return rubber;
}
