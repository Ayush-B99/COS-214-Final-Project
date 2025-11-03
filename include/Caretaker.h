#ifndef CARETAKER_H
#define CARETAKER_H

#include <iostream>
#include <string>
#include <system_error>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>
#include "Memento.h"

using namespace std;

/**
 * @file Caretaker.h
 * @brief Implements the Caretaker role in the Memento design pattern
 */

/**
 * @class Caretaker
 * @brief Manages a history of Memento objects for undo/redo functionality
 * 
 * The Caretaker is responsible for maintaining a collection of mementos but never
 * examines or operates on the contents of a memento. It acts as a safe-keeper
 * for state history, providing the ability to save, retrieve, and restore previous
 * states of an object.
 * 
 * @tparam T The type of object state being managed through mementos
 * 
 * @details
 * Key Responsibilities:
 * - Store multiple memento snapshots in chronological order
 * - Provide access to historical states by index or most recent
 * - Support undo operations by removing the most recent memento
 * - Never modify or inspect the internal state of mementos
 * 
 * Design Pattern:
 * - Pattern: Memento Pattern
 * - Role: Caretaker (manages but doesn't modify mementos)
 * - Collaborators: Memento (stores state), Originator (creates/restores state)
 * 
 * Common Use Cases:
 * - Undo/Redo functionality in applications
 * - Checkpointing and rollback in games or simulations
 * - Version history tracking
 * - Transaction management with rollback capability
 * 
 * @note This is a template class - implementations are in Caretaker.cpp which is
 *       included at the end of this header file.
 * 
 * @see Memento
 * 
 * Example usage:
 * @code
 * Caretaker<Plant> history;
 * 
 * // Save state
 * Memento<Plant> snapshot(plantPtr);
 * history.addMemento(snapshot);
 * 
 * // Modify plant...
 * 
 * // Restore previous state
 * Memento<Plant> previous = history.getLastMemento();
 * plantPtr = previous.getState();
 * 
 * // Or undo the last save
 * history.undo();
 * @endcode
 */
template<typename T>
class Caretaker
{
private:
    /**
     * @brief Vector storing the history of mementos in chronological order
     * 
     * Each memento represents a snapshot of the object's state at a particular
     * point in time. Index 0 is the oldest state, back() is the most recent.
     */
    vector<Memento<T>> mementos;

public:
    /**
     * @brief Default constructor for Caretaker
     * 
     * Creates an empty caretaker with no stored mementos.
     */
    Caretaker();
    
    /**
     * @brief Destructor for Caretaker
     * 
     * Cleans up all stored mementos. The mementos themselves will handle
     * cleanup of any deep-copied state they contain.
     */
    ~Caretaker();
    
    /**
     * @brief Adds a new memento to the history
     * 
     * Appends the given memento to the end of the memento vector, making it
     * the most recent state snapshot.
     * 
     * @param m The memento to add to the history
     * 
     * @note This does not limit the number of stored mementos. For memory-constrained
     *       applications, consider implementing a maximum history size with automatic
     *       removal of oldest mementos.
     */
    void addMemento(Memento<T> m);

    /**
     * @brief Removes the most recent memento from history (undo operation)
     * 
     * Removes the last memento added to the history. This is typically used
     * to implement undo functionality - discard the current state and revert
     * to a previous one.
     * 
     * @note If the memento vector is empty, this operation does nothing.
     *       It does not throw an exception or produce an error.
     * 
     * @see getLastMemento()
     */
    void undo();

    /**
     * @brief Retrieves a memento at a specific index in the history
     * 
     * Provides access to any memento in the history by its chronological index.
     * Index 0 represents the oldest saved state, and size()-1 is the most recent.
     * 
     * @param index Zero-based index of the memento to retrieve
     * @return Memento<T> The memento at the specified index
     * 
     * @throws Returns NULL if index is out of bounds (prints error message)
     * 
     * @warning The current implementation returns NULL for invalid indices, which
     *          will cause a compilation error since Memento<T> is not a pointer type.
     *          Consider throwing an exception or returning optional<Memento<T>> instead.
     * 
     * @note For accessing the most recent memento, prefer getLastMemento() for clarity.
     */
    Memento<T> getMemento(int index);

    /**
     * @brief Retrieves the most recently added memento
     * 
     * Returns the last memento in the history without removing it. This is the
     * most recent snapshot of the object's state.
     * 
     * @return Memento<T> The most recent memento
     * 
     * @throws Returns NULL if no mementos exist (prints error message)
     * 
     * @warning The current implementation returns NULL for empty history, which
     *          will cause a compilation error since Memento<T> is not a pointer type.
     *          Consider throwing an exception or returning optional<Memento<T>> instead.
     * 
     * @note This is equivalent to getMemento(size()-1) but more explicit in intent.
     * 
     * @see undo()
     */
    Memento<T> getLastMemento();
};

#include "../src/Caretaker.cpp"

#endif
