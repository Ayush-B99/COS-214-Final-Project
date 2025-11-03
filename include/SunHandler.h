/**
 * @file SunHandler.h
 * @brief Concrete handler for sunlight-related plant care requests.
 * 
 * The SunHandler specializes in processing sunlight exposure requests
 * within the Chain of Responsibility. It handles light-related care
 * and delegates other care types to the next handler.
 */

#ifndef SUNHANDLER_H
#define SUNHANDLER_H

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
 * @class SunHandler
 * @brief Concrete handler that processes sunlight-related plant care.
 * 
 * This handler specializes in light exposure operations. It checks if a plant
 * needs sunlight and provides appropriate light exposure if needed.
 * If the request is not light-related, it passes to the next handler.
 */
class SunHandler : public PlantCareHandler {
public:
    /**
     * @brief Destructor.
     */
    ~SunHandler();

    /**
     * @brief Handles sunlight-related care requests.
     * @param plant The plant that may need light exposure.
     * 
     * This method checks if the plant requires sunlight and provides
     * appropriate exposure if needed. If the request is not light-related,
     * it delegates to the next handler in the responsibility chain.
     */
    void handleCareRequest(Plant *plant);

    /**
     * @brief Provides identification for the sun handler.
     * 
     * Outputs a message identifying this as the sunlight care handler,
     * useful for debugging and understanding the handler chain.
     */
    void message();
};

#endif