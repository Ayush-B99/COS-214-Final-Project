#include <iostream>
#include "../include/ConcreteCommMediator.h"
#include "../include/Manager.h"
#include "../include/Worker.h"
#include "../include/Customer.h"

using namespace std;

int main() {
    cout << "=== COMMMEDIATOR TESTING ===" << endl << endl;
    
    ConcreteCommMediator* mediator = new ConcreteCommMediator();
    
    Manager* manager = new Manager("SHAVIR (Manager)", mediator);
    Worker* worker1 = new Worker("DIYA (Worker)", mediator);
    Worker* worker2 = new Worker("CHINMAYI (Worker)", mediator);
    
    Customer* customer1 = new Customer("AYUSH");
    Customer* customer2 = new Customer("FABIO");
    Customer* customer3 = new Customer("DIDI");
    
    mediator->addCustomer(customer1);
    mediator->addCustomer(customer2);
    mediator->addCustomer(customer3);
    
    cout << endl << "=== TEST 1: Basic Customer Queries ===" << endl;
    
    mediator->notifyStaff(customer1, "How often should I water my plants?", nullptr);
    cout << endl;
    
    mediator->notifyStaff(customer2, "I want to buy plants in bulk for my office", nullptr);
    cout << endl;
    
    mediator->notifyStaff(customer3, "How much sunlight do succulents need?", nullptr);
    cout << endl;
    
    cout << "=== TEST 2: Staff Availability ===" << endl;
    mediator->notifyStaff(customer1, "idk a plant ques", nullptr);
    cout << endl;
    
    cout << "=== TEST 3: Direct Staff Assignment ===" << endl;
    mediator->assignStaffToCustomer(worker2, customer1);
    cout << endl;
    
    cout << "=== TEST 4: Get Assigned Staff ===" << endl;
    StaffMember* assigned = mediator->getAssignedStaff(customer1);
    if (assigned) {
        cout << "Customer " << customer1->getName() << " is assigned to: " << assigned->getName() << endl;
    }
    cout << endl;
    
    // Cleanup
    delete mediator;
    delete manager;
    delete worker1;
    delete worker2;
    delete customer1;
    delete customer2;
    delete customer3;
    
    cout << "=== YAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAY ===" << endl;
    return 0;
}