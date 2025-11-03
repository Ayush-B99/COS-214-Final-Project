#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Order;

/**
 * @file OrderState.h
 * @brief Abstract base class for implementing the State pattern in Orders.
 */

/**
 * @class OrderState
 * @brief Defines the interface for different states of an Order.
 * 
 * OrderState is part of the **State design pattern**, allowing an Order
 * to alter its behavior when its internal state changes.
 * Concrete states (e.g., Draft, Submitted) implement this interface to 
 * provide state-specific behavior for proceeding or canceling an order.
 * 
 * @see Draft, Submitted
 */
class OrderState {

public:
    /**
     * @brief Virtual destructor for proper cleanup of derived states.
     */
    virtual ~OrderState();

    /**
     * @brief Executes the transition to the next state of the Order.
     * @param order Pointer to the Order whose state is changing.
     * 
     * Each concrete state defines what happens when the Order proceeds.
     */
    virtual void proceed(Order* order) = 0;

    /**
     * @brief Cancels the Order from the current state.
     * @param order Pointer to the Order to cancel.
     * 
     * Concrete states define how cancellation is handled depending on 
     * the current state.
     */
    virtual void cancel(Order* order) = 0;

    /**
     * @brief Retrieves the name of the current state.
     * @return Constant string representing the state's name.
     */
    virtual string const getName() = 0;
};

#endif