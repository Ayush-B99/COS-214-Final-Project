#include "../include/Manager.h"

Manager::Manager(const string& name, CommMediator* mediator)
    : StaffMember(name, mediator)
{
    //sooo it like automatically SHOULD register with the mediator when created...in the constructor so....yeah
}
void Manager::handleCustomerQuery(Customer* customer, const string& query, Plant* plant) {
    cout << getName() << " handling complex query from " << customer->getName() 
         << ": \"" << query << "\"" << endl;
    
    string response;
    if (query.find("bulk") != string::npos || query.find("wholesale") != string::npos) {
        response = "I can help with bulk purchases! We offer discounts for orders over 20 plants.";
        // applyDiscount(customer, 10.0); // Remove this line - method doesn't exist
    }
    else if (query.find("rare") != string::npos || query.find("special") != string::npos) {
        response = "We can special order rare plants for you. It takes 2-3 weeks.";
        // handleSpecialOrder(customer, "rare orchid", 1); // Remove this line - method doesn't exist
    }
    else if (query.find("complaint") != string::npos) {
        response = "I apologize for any inconvenience. Let me make this right for you.";
    }
    else {
        response = "As manager, I'm here to ensure you have the best experience!";
    }
    
    respondToCustomer(customer, response, plant);
}

void Manager::handlePurchaseRequest(Customer* customer, const string& plantType, int quantity) {
    cout << getName() << " processing special purchase: " << quantity << " " << plantType << "(s)" << endl;
    
    string response;
    if (quantity >= 10) {
        response = "I've approved your bulk order of " + to_string(quantity) + 
                  " " + plantType + "(s) with a 15% discount!";
        // applyDiscount(customer, 15.0); // Remove this line - method doesn't exist
    } else {
        response = "I've processed your order for " + to_string(quantity) + 
                  " " + plantType + "(s). Thank you for your business!";
    }
    
    respondToCustomer(customer, response);
}





//////////////////////so the stuff below was in the uml and um i have no idea what it is so im leaving it unimplemented for now - chinmayi//////////////////////

// void Manager::getComm() {
// 	// TODO - implement Manager::getComm
// 	throw "Not yet implemented";
// }

// void Manager::setComm() {
// 	// TODO - implement Manager::setComm
// 	throw "Not yet implemented";
// }

// void Manager::getGrowth() {
// 	// TODO - implement Manager::getGrowth
// 	throw "Not yet implemented";
// }

// void Manager::setGrowth() {
// 	// TODO - implement Manager::setGrowth
// 	throw "Not yet implemented";
// }
