/**
 * @file Normal.h
 * @brief Leaf component representing individual regular customers.
 * 
 * Normal customers are leaf nodes in the Composite pattern hierarchy.
 * They represent individual customers with standard pricing and benefits.
 */

#ifndef NORMAL_H
#define NORMAL_H

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
 * @class Normal
 * @brief Leaf component representing individual regular customers.
 * 
 * As a leaf in the Composite pattern, Normal represents terminal
 * customer objects that have no children. They implement the Component
 * interface operations directly without delegation to child components.
 * 
 * Normal customers receive the standard discount rate (typically 0%).
 */
class Normal : public Customer {
public:
    /**
     * @brief Get the discount rate for normal customers.
     * @return Discount rate as decimal (typically 0.0 for normal customers).
     * 
     * Implements the Component operation for leaf nodes. Normal customers
     * typically receive no discount or a minimal standard discount.
     */
    double getDiscount();
};

#endif