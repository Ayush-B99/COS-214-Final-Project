#ifndef SUBMITTED_H
#define SUBMITTED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "OrderState.h"
#include "Cancelled.h"
#include "Paid.h"

/**
 * @file Submitted.h
 * @brief Concrete OrderState representing an order that has been submitted.
 */

/**
 * @class Submitted
 * @brief Represents the "Submitted" state in the Order State pattern.
 * 
 * Submitted is a concrete state of an Order. In this state, the order has been
 * finalized by the user but not yet paid. It defines behavior for proceeding 
 * (moving to Paid) or cancellation (moving to Cancelled).
 * 
 * This class is part of the **State design pattern**, allowing the Order
 * object to alter its behavior based on its current state.
 * 
 * @see OrderState, Cancelled, Paid
 */
class Submitted : public OrderState {

public:
    /**
     * @brief Constructs a Submitted state instance.
     */
    Submitted();

    /**
     * @brief Proceeds the order to the next appropriate state.
     * @param order Pointer to the Order being processed.
     * 
     * In the Submitted state, proceeding typically moves the order to Paid.
     */
    void proceed(Order* order);

    /**
     * @brief Cancels the order from the Submitted state.
     * @param order Pointer to the Order being cancelled.
     * 
     * Moves the order to the Cancelled state.
     */
    void cancel(Order* order);

    /**
     * @brief Retrieves the name of the current state.
     * @return Constant string "Submitted"
     */
    string const getName();
}; 

#endif
