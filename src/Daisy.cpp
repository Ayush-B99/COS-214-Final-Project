#include "../include/Daisy.h"

Daisy::Daisy() : SmallPlant("Daisy")
{
	setPrice(25.0);
	setDescription("A cheerful Daisy with white petals");
}

Daisy::Daisy(Daisy &other) : SmallPlant(other)
{
	setPrice(other.getPrice());
}

Daisy::~Daisy()
{
	// TODO - implement Daisy::~Daisy
}

Plant *Daisy::clone()
{
	// TODO - implement Daisy::clone
	return new Daisy(*this);
}
