#include "../include/TemperatePlantFactory.h"
#include "../include/ConcreteGrowthObserver.h"

TemperatePlantFactory::TemperatePlantFactory()
{
	// empty constructor
}

TemperatePlantFactory::~TemperatePlantFactory()
{
	// no mem management needed for now
}

Plant *TemperatePlantFactory::createSmallPlant()
{
	Daisy *daisy = new Daisy();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(daisy);
	return daisy;
}

Plant *TemperatePlantFactory::createMediumPlant()
{
	Lilac *lilac = new Lilac();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(lilac);
	return lilac;
}

Plant *TemperatePlantFactory::createLargePlant()
{
	WhiteOak *whiteOak = new WhiteOak();
	ConcreteGrowthObserver *observer = new ConcreteGrowthObserver(whiteOak);
	return whiteOak;
}
