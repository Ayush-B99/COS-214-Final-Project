#ifndef DRAFT_H
#define DRAFT_H

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
#include "Cancelled.h"
#include "Submitted.h"

/**
 * @file Draft.h
 * @brief Concrete OrderState representing an order in draft form.
 */

/**
 * @class Draft
 * @brief Represents the "Draft" state in the Order State pattern.
 * 
 * Draft is a concrete state of an Order. In this state, the order has been
 * created but not yet submitted. It defines behavior for proceeding 
 * (moving to Submitted) or cancellation (moving to Cancelled).
 * 
 * This class is part of the **State design pattern**, allowing the Order
 * object to alter its behavior based on its current state.
 * 
 * @see OrderState, Cancelled, Submitted
 */
class Draft : public OrderState {

public:
    /**
     * @brief Constructs a Draft state instance.
     */
    Draft();

    /**
     * @brief Proceeds the order to the next appropriate state.
     * @param order Pointer to the Order being processed.
     * 
     * In the Draft state, proceeding typically moves the order to Submitted.
     */
    void proceed(Order* order);

    /**
     * @brief Cancels the order from the Draft state.
     * @param order Pointer to the Order being cancelled.
     * 
     * Moves the order to the Cancelled state.
     */
    void cancel(Order* order);

    /**
     * @brief Retrieves the name of the current state.
     * @return Constant string "Draft"
     */
    string const getName();
};

#endif
