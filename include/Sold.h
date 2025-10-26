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
        void grow(Plant* plant) override;

        vector<string> getRequiredCare() override;

        string getStatusMessage(Plant* plant) override;

        bool isSold() override;
};

#endif
