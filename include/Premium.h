/**
 * @file Premium.h
 * @brief Leaf component representing individual premium customers.
 * 
 * Premium customers are leaf nodes in the Composite pattern hierarchy.
 * They represent individual customers with enhanced benefits and discounts.
 */

#ifndef PREMIUM_H
#define PREMIUM_H

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
 * @class Premium
 * @brief Leaf component representing individual premium customers.
 * 
 * As a leaf in the Composite pattern, Premium represents terminal
 * customer objects that have no children. They implement enhanced
 * discount rates compared to Normal customers.
 * 
 * Premium customers receive significant discounts as part of their
 * premium membership benefits.
 */
class Premium : public Customer {
public:
    /**
     * @brief Get the discount rate for premium customers.
     * @return Discount rate as decimal (enhanced rate for premium members).
     * 
     * Implements the Component operation for leaf nodes with premium benefits.
     * Premium customers typically receive substantial discounts (e.g., 15-25%).
     */
    double getDiscount();
};

#endif