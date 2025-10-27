#ifndef PLANTCAREHANDLER_H
#define PLANTCAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Plant;

class PlantCareHandler
{

private:
	PlantCareHandler *successor;
	PlantCareHandler *next;

public:
	virtual ~PlantCareHandler();

	virtual void handleCareRequest(Plant *plant) = 0;

	void setNext();

	virtual void message() = 0;
};

#endif
