#ifndef COMPLETED_H
#define COMPLETED_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "OrderState.h"
#include "Order.h"

/**
 * @file Completed.h
 * @brief Concrete OrderState representing an order that has been completed.
 */

/**
 * @class Completed
 * @brief Represents the "Completed" state in the Order State pattern.
 * 
 * Completed is a concrete state of an Order. In this state, the order has been
 * successfully fulfilled and no further modifications should be allowed. The Completed state
 * ensures that calling proceed() has no effect, and calling cancel() is either disallowed 
 * or logged but does not alter the state.
 * 
 * This class is part of the **State design pattern**, allowing the Order
 * object to alter its behavior dynamically based on its current state.
 * 
 * Example usage:
 * @code
 * Order* order = new Order("ORD456");
 * order->setState(new Completed());
 * order->proceed(); // No effect, order remains completed
 * order->cancel();  // No effect, order remains completed
 * @endcode
 */
class Completed : public OrderState {

public:
    /**
     * @brief Constructs a Completed state object.
     */
    Completed();
    
    /**
     * @brief Attempt to proceed an order from Completed state.
     * 
     * Since the order is completed, proceeding has no effect.
     * 
     * @param order Pointer to the Order object
     */
    void proceed(Order* order);

    /**
     * @brief Attempt to cancel an order that is already completed.
     * 
     * Since the order is completed, cancelling has no effect.
     * 
     * @param order Pointer to the Order object
     */
    void cancel(Order* order);

    /**
     * @brief Retrieves the name of this state.
     * 
     * @return string const The string "Completed"
     */
    string const getName();
};

#endif
