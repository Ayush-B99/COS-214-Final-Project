/**
 * @file FertilizerHandler.h
 * @brief Concrete handler for fertilizer-related plant care requests.
 * 
 * The FertilizerHandler specializes in processing fertilization requests
 * within the Chain of Responsibility. It handles nutrient-related care
 * and delegates other care types to the next handler in the chain.
 */

#ifndef FERTILIZERHANDLER_H
#define FERTILIZERHANDLER_H

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
 * @class FertilizerHandler
 * @brief Concrete handler that processes fertilizer-related plant care.
 * 
 * This handler specializes in fertilization operations. It checks if a plant
 * needs fertilizer and applies it if appropriate. If the request is not
 * fertilizer-related, it passes the request to the next handler in the chain.
 */
class FertilizerHandler : public PlantCareHandler {
public:
    /**
     * @brief Destructor.
     */
    ~FertilizerHandler();

    /**
     * @brief Handles fertilizer-related care requests.
     * @param plant The plant that may need fertilization.
     * 
     * This method checks if the plant requires fertilizer and applies it
     * if needed. If the request is not fertilizer-related, it delegates
     * to the next handler in the responsibility chain.
     */
    void handleCareRequest(Plant *plant);

    /**
     * @brief Provides identification for the fertilizer handler.
     * 
     * Outputs a message identifying this as the fertilizer care handler,
     * useful for debugging and understanding the handler chain.
     */
    void message();
};

#endif