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

class PlantCareHandler {

private:
	PlantCareHandler* successor;
	PlantCareHandler* next;

public:
	virtual ~PlantCareHandler();

	virtual void temperateCare() = 0;

	virtual void carnivorousCare() = 0;

	virtual void succulentCare() = 0;

	virtual void tropicalCare() = 0;

	void setNext();

	virtual void message() = 0;
};

#endif
