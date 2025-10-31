/**
 * @file PlantCareHandler.h
 * @brief Handler interface for plant care request processing with Chain of Responsibility.
 * 
 * The PlantCareHandler serves as both an Invoker in the Command pattern and
 * a Handler in the Chain of Responsibility pattern. It processes plant care
 * requests and can delegate to the next handler in the chain if needed.
 */

#ifndef PLANTCAREHANDLER_H
#define PLANTCAREHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Plant;

/**
 * @class PlantCareHandler
 * @brief Abstract handler that processes plant care requests.
 * 
 * This class combines the Command pattern's Invoker role with the
 * Chain of Responsibility pattern. It can execute commands and/or
 * pass requests along a chain of handler objects.
 */
class PlantCareHandler {
protected:
    PlantCareHandler *next; ///< Pointer to the next handler in the responsibility chain

public:
    /**
     * @brief Virtual destructor for proper cleanup of derived handlers.
     */
    virtual ~PlantCareHandler();

    /**
     * @brief Handles a plant care request.
     * @param plant The plant that requires care.
     * 
     * This method processes care requests and may delegate to the next
     * handler in the chain if the current handler cannot process the request.
     */
    virtual void handleCareRequest(Plant *plant) = 0;

    /**
     * @brief Sets the next handler in the responsibility chain.
     * @param nextHandler The next handler to receive unprocessed requests.
     */
    void setNext(PlantCareHandler *nextHandler);

    /**
     * @brief Provides handler-specific information or status.
     * 
     * This method gives each concrete handler a way to identify itself
     * or provide status information about its capabilities.
     */
    virtual void message() = 0;
};

#endif