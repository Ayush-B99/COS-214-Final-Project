/**
 * @file CommMediator.h
 * @brief Abstract mediator interface for customer-staff communication.
 * 
 * The CommMediator defines the interface for handling all communication
 * between customers and staff members. It decouples customers from direct
 * staff dependencies and provides centralized routing of interactions.
 */

#ifndef COMMMEDIATOR_H
#define COMMMEDIATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class StaffMember;
class Customer;
class Plant;

/**
 * @class CommMediator
 * @brief Mediator for handling communication between customers and staff members
 *
 * This mediator specifically handles customer-related communications:
 * - Customer queries and requests
 * - Staff responses to customers
 * - Customer purchase requests
 * - Staff assistance coordination for customers
 *
 * It decouples customers from direct staff dependencies and provides
 * centralized routing of customer-staff interactions.
 */

class CommMediator
{

public:
    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~CommMediator() = default;

    /**
     * @brief Notify staff about a customer query or request.
     * @param customer The customer making the request.
     * @param query The customer's question or request text.
     * @param plant Optional plant related to the query (nullptr if not applicable).
     * 
     * Routes customer inquiries to available and appropriate staff members
     * based on the query type and staff expertise.
     */
    virtual void notifyStaff(Customer *customer, const string &query, Plant *plant = nullptr) = 0;

    /**
     * @brief Notify customer about staff response.
     * @param staff The staff member providing the response.
     * @param customer The customer to receive the response.
     * @param response The staff's response message.
     * @param plant Optional plant related to the response (nullptr if not applicable).
     * 
     * Delivers staff responses back to the originating customer through
     * the centralized communication channel.
     */
    virtual void notifyCustomer(StaffMember *staff, Customer *customer, const string &response, Plant *plant = nullptr) = 0;

    /**
     * @brief Add a staff member to the communication system.
     * @param staff Pointer to the staff member to register.
     * 
     * Registers staff members with the mediator so they can receive
     * customer queries and participate in the communication system.
     */
    virtual void addStaff(StaffMember *staff) = 0;

    /**
     * @brief Add a customer to the communication system.
     * @param customer Pointer to the customer to register.
     * 
     * Registers customers with the mediator so they can make queries
     * and receive responses through the communication system.
     */
    virtual void addCustomer(Customer *customer) = 0;
};

#endif