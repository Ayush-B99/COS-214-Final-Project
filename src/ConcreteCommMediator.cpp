#include "../include/ConcreteCommMediator.h"

#include <algorithm>

void ConcreteCommMediator::notifyStaff(Customer *customer, const string &query, Plant *plant)
{
    // cout<< "CUSTOMER_MEDIATOR: " << customer->getName()
         // << " asks: \"" << query << "\"" << endl;

    // Find available staff to handle the query
    StaffMember *availableStaffMember = nullptr;
    for (StaffMember *staff : availableStaff)
    {
        if (staff->getAvailability())
        {
            availableStaffMember = staff;
            break;
        }
    }

    if (availableStaffMember)
    {
        // cout<< "CUSTOMER_MEDIATOR: Routing to " << availableStaffMember->getName() << endl;
        availableStaffMember->setAvailability(false);
        assignments[customer] = availableStaffMember;
        availableStaffMember->handleCustomerQuery(customer, query, plant);
    }
    else
    {
        // cout<< "CUSTOMER_MEDIATOR: No available staff for " << customer->getName()
             // << ". Please wait." << endl;
        // In full implementation, would add to waiting queue
    }
}

void ConcreteCommMediator::notifyCustomer(StaffMember *staff, Customer *customer, const string &response, Plant *plant)
{
    // cout<< "CUSTOMER_MEDIATOR: " << staff->getName()
         // << " responds to " << customer->getName() << ": \"" << response << "\"" << endl;

    // Mark staff as available again
    staff->setAvailability(true);
    assignments.erase(customer);

    customer->receiveResponse(response, plant);
}

void ConcreteCommMediator::addStaff(StaffMember *staff)
{
    if (staff && find(availableStaff.begin(), availableStaff.end(), staff) == availableStaff.end())
    {
        availableStaff.push_back(staff);
        staff->setAvailability(true);
        // cout<< "CUSTOMER_MEDIATOR: " << staff->getName() << " added to customer service" << endl;
    }
}

void ConcreteCommMediator::addCustomer(Customer *customer)
{
    if (customer && find(registeredCustomers.begin(), registeredCustomers.end(), customer) == registeredCustomers.end())
    {
        registeredCustomers.push_back(customer);
        // cout<< "CUSTOMER_MEDIATOR: " << customer->getName() << " registered in system" << endl;
    }
}

void ConcreteCommMediator::assignStaffToCustomer(StaffMember *staff, Customer *customer)
{
    if (staff && customer)
    {
        assignments[customer] = staff;
        staff->setAvailability(false);
        // cout<< "CUSTOMER_MEDIATOR: " << staff->getName()
             // << " assigned to " << customer->getName() << endl;
    }
}

StaffMember *ConcreteCommMediator::getAssignedStaff(Customer *customer) const
{
    auto it = assignments.find(customer);
    return (it != assignments.end()) ? it->second : nullptr;
}