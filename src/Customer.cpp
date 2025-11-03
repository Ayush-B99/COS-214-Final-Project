#include "../include/Customer.h"

Customer::Customer(const string& name, CommMediator* mediator) 
    : customerName(name), commMediator(mediator) {
    if (commMediator) {
        commMediator->addCustomer(this);
    }
}
Customer::~Customer() {
}

string Customer::getName() const {
    return customerName;
}

void Customer::setCommMediator(CommMediator* mediator) {
    commMediator = mediator;
    if (commMediator) {
        commMediator->addCustomer(this);
    }
}

void Customer::askQuestion(const string& question, Plant* plant) {
    // cout << customerName << " asking: " << question << endl;
    if (commMediator)
    {
        commMediator->notifyStaff(this, question, plant);
    }
    // else
    // {
        // cout << customerName << " cannot ask question - no mediator set!" << endl;
    // }
}

void Customer::requestAssistance() {
    // cout << customerName << " requesting assistance" << endl;
    if (commMediator) {
        commMediator->notifyStaff(this, "I need assistance please");
    }
}

void Customer::requestPurchase(const string& plantType, int quantity) {
    string request = "I want to purchase " + to_string(quantity) + " " + plantType + "(s)";
    // cout << customerName << ": " << request << endl;
    purchaseHistory.push_back("Purchased " + to_string(quantity) + " " + plantType);
    if (commMediator) {
        commMediator->notifyStaff(this, request);
    }
}

void Customer::receiveResponse(const string& response, Plant* plant) {
    this->response = customerName + " receives: \"" + response + "\"";
    if (plant) {
         this->response += " [About a plant]";
    }
    this->response += "\n";
}

string Customer::getResponse() const {
    return response;
}

vector<string> Customer::getPurchaseHistory() const {
    return purchaseHistory;
}

