#ifndef PAID_H
#define PAID_H

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
#include "Completed.h"

/**
 * @file Paid.h
 * @brief Concrete OrderState representing an order that has been paid.
 */

/**
 * @class Paid
 * @brief Represents the "Paid" state in the Order State pattern.
 * 
 * Paid is a concrete state of an Order. It defines specific behavior
 * when the order proceeds (moves to Completed) or is cancelled (moves to Cancelled).
 * 
 * This class is part of the **State design pattern** for Orders, allowing
 * dynamic change in behavior depending on the order's current state.
 * 
 * @see OrderState, Cancelled, Completed
 */
class Paid : public OrderState {

public:
    /**
     * @brief Constructs a Paid state instance.
     */
    Paid();
    
    /**
     * @brief Proceeds the order to the next appropriate state.
     * @param order Pointer to the Order being processed.
     * 
     * In the Paid state, proceeding typically moves the order to Completed.
     */
    void proceed(Order* order);

    /**
     * @brief Cancels the order from the Paid state.
     * @param order Pointer to the Order being cancelled.
     * 
     * Moves the order to the Cancelled state.
     */
    void cancel(Order* order);

    /**
     * @brief Retrieves the name of the current state.
     * @return Constant string "Paid"
     */
    string const getName();
};

#endif