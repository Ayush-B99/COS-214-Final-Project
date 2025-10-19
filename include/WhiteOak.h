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

class WhiteOak : LargePlant {


public:
	WhiteOak();

	WhiteOak(WhiteOak& other);

	~WhiteOak();

	Plant* clone();
};

#endif
