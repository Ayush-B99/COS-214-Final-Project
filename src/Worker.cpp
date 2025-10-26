#include "../include/Worker.h"

void Worker::getComm()
{
	// TODO - implement Worker::getComm
	throw "Not yet implemented";
}

void Worker::setComm()
{
	// TODO - implement Worker::setComm
	throw "Not yet implemented";
}

void Worker::getGrowth(Plant *plant)
{

	commandQueue.push_back(new Water(plant));
	commandQueue.push_back(new Sun(plant));
	commandQueue.push_back(new Fertilizer(plant));

	this->executeCommand();
}

void Worker::setGrowth()
{
	// TODO - implement Worker::setGrowth
	throw "Not yet implemented";
}
