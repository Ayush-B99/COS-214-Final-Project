#ifndef WHITEOAK_H
#define WHITEOAK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "LargePlant.h"

class WhiteOak : public LargePlant {


public:
	WhiteOak();

	WhiteOak(WhiteOak& other);

	~WhiteOak();

	Plant* clone();
};

#endif
