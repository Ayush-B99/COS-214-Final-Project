#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "../include/CarnivorousPlantFactory.h"

int testObserverMediator()
{

    std::cout << "Testing Observer and Mediator Patterns" << std::endl;
    CarnivorousPlantFactory *factory = new CarnivorousPlantFactory();
    ;

    // Plant *venusFlytrap = factory.createMediumPlant();

    // venusFlytrap->printFullStatus();

    // std::cout << "----------------------------------" << std::endl;

    return 0;
}

int main()
{
    testObserverMediator();

    return 0;
}
