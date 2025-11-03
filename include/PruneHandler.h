/**
 * @file PruneHandler.h
 * @brief Concrete handler for pruning-related plant care requests.
 * 
 * The PruneHandler specializes in processing pruning and maintenance
 * requests within the Chain of Responsibility. It handles trimming
 * operations and delegates other care types to subsequent handlers.
 */

#ifndef PRUNEHANDLER_H
#define PRUNEHANDLER_H

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
 * @class PruneHandler
 * @brief Concrete handler that processes pruning-related plant care.
 * 
 * This handler specializes in maintenance and trimming operations.
 * It checks if a plant needs pruning and performs trimming if appropriate.
 * If the request is not pruning-related, it passes to the next handler.
 */
class PruneHandler : public PlantCareHandler {
public:
    /**
     * @brief Destructor.
     */
    ~PruneHandler();

    /**
     * @brief Handles pruning-related care requests.
     * @param plant The plant that may need trimming.
     * 
     * This method checks if the plant requires pruning and performs
     * trimming operations if needed. If the request is not pruning-related,
     * it delegates to the next handler in the responsibility chain.
     */
    void handleCareRequest(Plant *plant);

    /**
     * @brief Provides identification for the prune handler.
     * 
     * Outputs a message identifying this as the pruning care handler,
     * useful for debugging and understanding the handler chain.
     */
    void message();
};

#endif