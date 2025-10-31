/**
 * @file Command.h
 * @brief Abstract command interface for plant care operations.
 * 
 * The Command class defines the interface for all plant care commands in the
 * Command pattern. This pattern encapsulates plant care operations as objects,
 * allowing for parameterization, queuing, logging, and undo functionality.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

/**
 * @class Command
 * @brief Abstract base class for all plant care commands.
 * 
 * This interface defines the execute method that all concrete commands must implement.
 * The Command pattern allows separating the object that invokes the operation (invoker)
 * from the object that knows how to perform the operation (receiver).
 */
class Command {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived commands.
     */
    virtual ~Command();

    /**
     * @brief Executes the plant care command.
     * 
     * This method performs the actual plant care operation when invoked.
     * Concrete command classes implement this to call specific methods
     * on the receiver (Plant) object.
     */
    virtual void execute() = 0;
};

#endif