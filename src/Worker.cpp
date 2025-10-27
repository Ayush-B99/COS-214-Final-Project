#include "../include/Worker.h"

Worker::Worker(const string& name, CommMediator* mediator)
    : StaffMember(name, mediator)
{
    //Staffmember handles mediator registration which basically happens automatically when they join...so extra stuff we dont need.
}

void Worker::handleCustomerQuery(Customer* customer, const string& query, Plant* plant) {
    cout << getName() << " handling query from " << customer->getName() 
         << ": \"" << query << "\"" << endl;
    
    string response;
    if (query.find("water") != string::npos || query.find("care") != string::npos) {
        response = "I can help with plant care! Most plants need watering once a week.";
        providePlantCareAdvice(customer, "general");
    }
    else if (query.find("price") != string::npos || query.find("cost") != string::npos) {
        response = "Let me check the prices for you. Our plants range from $5 to $50.";
    }
    else if (query.find("sunlight") != string::npos) {
        response = "Great question! Most plants need 4-6 hours of sunlight daily.";
    }
    else {
        response = "I'll be happy to help you with that!";
    }
    
    respondToCustomer(customer, response, plant);
}

void Worker::handlePurchaseRequest(Customer* customer, const string& plantType, int quantity) {
    cout << getName() << " processing purchase: " << quantity << " " << plantType << "(s)" << endl;
    checkInventory(plantType);
    
    string response = "I've processed your order for " + to_string(quantity) + 
                     " " + plantType + "(s). Your total is $" + 
                     to_string(quantity * 15) + ". Thank you!";
    
    respondToCustomer(customer, response);
}




void Worker::providePlantCareAdvice(Customer* customer, const string& plantType) {
    cout << "    [" << getName() << " providing " << plantType << " care advice to " << customer->getName() << "]" << endl;
}

void Worker::checkInventory(const string& plantType) {
    cout << "    [" << getName() << " checking inventory for " << plantType << "]" << endl;
}






// void Worker::getComm() {
// 	// TODO - implement Worker::getComm
// 	throw "Not yet implemented";
// }

// void Worker::setComm() {
// 	// TODO - implement Worker::setComm
// 	throw "Not yet implemented";
// }

// void Worker::getGrowth() {
// 	// TODO - implement Worker::getGrowth
// 	throw "Not yet implemented";
// }

// void Worker::setGrowth() {
// 	// TODO - implement Worker::setGrowth
// 	throw "Not yet implemented";
// }
