#ifndef CANCELLED_H
#define CANCELLED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "Order.h"
#include "OrderState.h"

/**
 * @file Cancelled.h
 * @brief Concrete OrderState representing an order that has been cancelled.
 */

/**
 * @class Cancelled
 * @brief Represents the "Cancelled" state in the Order State pattern.
 * 
 * Cancelled is a concrete state of an Order. In this state, the order has been
 * cancelled and no further modifications should be allowed. The Cancelled state
 * ensures that calling proceed() has no effect, and calling cancel() reinforces
 * the current state.
 * 
 * This class is part of the **State design pattern**, allowing the Order
 * object to alter its behavior dynamically based on its current state.
 * 
 * Example usage:
 * @code
 * Order* order = new Order("ORD123");
 * order->setState(new Cancelled());
 * order->proceed(); // No effect, order remains cancelled
 * order->cancel();  // Reinforces cancelled state
 * @endcode
 */
class Cancelled : public OrderState {

public:
    /**
     * @brief Constructs a Cancelled state object.
     */
    Cancelled();
    
    /**
     * @brief Attempt to proceed an order from Cancelled state.
     * 
     * Since the order is cancelled, proceeding has no effect.
     * 
     * @param order Pointer to the Order object
     */
    void proceed(Order* order);

    /**
     * @brief Attempt to cancel an order that is already cancelled.
     * 
     * Reinforces the cancelled state; the order remains cancelled.
     * 
     * @param order Pointer to the Order object
     */
    void cancel(Order* order);

    /**
     * @brief Retrieves the name of this state.
     * 
     * @return string const The string "Cancelled"
     */
    string const getName();
};

#endif
