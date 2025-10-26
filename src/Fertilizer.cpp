#include "../include/Fertilizer.h"

Fertilizer::Fertilizer(Plant *plant)
{
}

void Fertilizer::execute()
{
	cout << "Execute fertilizer command" << endl;
}

void Fertilizer::undo()
{
	// TODO - implement Fertilizer::undo
	throw "Not yet implemented";
}
