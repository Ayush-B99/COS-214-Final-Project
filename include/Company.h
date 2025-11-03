/**
 * @file Company.h
 * @brief Composite component representing corporate customer groups.
 * 
 * Company is a composite in the Composite pattern that can contain
 * multiple individual customers (both Normal and Premium) as well as
 * other Company composites, forming a tree structure of customers.
 */

#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Customer.h"

/**
 * @class Company
 * @brief Composite component representing corporate customer groups.
 * 
 * As a composite in the Composite pattern, Company can store child
 * customer components (both leaves and other composites). It implements
 * component operations by delegating to its children and aggregating results.
 * 
 * Company composites typically represent business entities that may have
 * multiple employees or departments as individual customers, with
 * corporate-level discounts and billing.
 */
class Company : public Customer {
    
public:
    vector<Customer*> customers;  ///< Child customer components in this composite

    /**
     * @brief Construct a new Company composite.
     * @param name Company name.
     * @param mediator Communication mediator for the composite.
     */
    Company(const string& name, CommMediator* mediator) : Customer(name, mediator) {}

    /**
     * @brief Destructor for Company composite.
     * 
     * Responsible for cleaning up child customer components.
     */
    ~Company();

    /**
     * @brief Get the corporate discount rate.
     * @return Discount rate as decimal (typically aggregated from child components).
     * 
     * Implements the Component operation for composite nodes. May calculate
     * discount based on aggregate purchasing power or corporate agreements.
     */
    double getDiscount();

    /**
     * @brief Add a customer component to this composite.
     * @param c Pointer to the customer component to add.
     * 
     * Composite operation for building the customer hierarchy.
     * Adds individual customers (leaves) or other companies (composites)
     * to this composite's collection of child components.
     */
    void addCustomer(Customer* c);

    /**
     * @brief Remove a customer component from this composite.
     * @param c Pointer to the customer component to remove.
     * 
     * Composite operation for modifying the customer hierarchy.
     * Removes the specified customer component from this composite's collection.
     */
    void removeCustomer(Customer* c);
};

#endif