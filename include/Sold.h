#ifndef SOLD_H
#define SOLD_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "GrowthState.h"

class Sold : public GrowthState {
    public:
        void grow(Plant* plant);

        vector<string> getRequiredCare();

        string getStatusMessage(Plant* plant);

        bool isSold();

        string getName();
};

#endif