/**
 * @file WaterHandler.h
 * @brief Concrete handler for water-related plant care requests.
 * 
 * The WaterHandler specializes in processing hydration requests
 * within the Chain of Responsibility. It handles watering operations
 * and delegates other care types to subsequent handlers.
 */

#ifndef WATERHANDLER_H
#define WATERHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

#include "PlantCareHandler.h"

/**
 * @class WaterHandler
 * @brief Concrete handler that processes water-related plant care.
 * 
 * This handler specializes in hydration operations. It checks if a plant
 * needs water and provides hydration if appropriate. If the request is not
 * water-related, it passes the request to the next handler in the chain.
 */
class WaterHandler : public PlantCareHandler {
public:
    /**
     * @brief Destructor.
     */
    ~WaterHandler();

    /**
     * @brief Handles water-related care requests.
     * @param plant The plant that may need hydration.
     * 
     * This method checks if the plant requires water and hydrates it
     * if needed. If the request is not water-related, it delegates
     * to the next handler in the responsibility chain.
     */
    void handleCareRequest(Plant *plant);

    /**
     * @brief Provides identification for the water handler.
     * 
     * Outputs a message identifying this as the water care handler,
     * useful for debugging and understanding the handler chain.
     */
    void message();
};

#endif