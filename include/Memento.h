#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

/**
 * @file Memento.h
 * @brief Implements the Memento design pattern for state preservation
 */

/**
 * @class Memento
 * @brief Stores and manages object state snapshots with automatic deep/shallow copy detection
 * 
 * The Memento class is part of the Memento design pattern, which provides the ability
 * to restore an object to its previous state (undo via rollback). This implementation
 * uses template metaprogramming to automatically detect whether the stored type supports
 * deep copying through a clone() method.
 * 
 * @tparam T The type of object whose state is being stored. If T has a clone() method,
 *           deep copies will be created automatically. Otherwise, shallow copies are used.
 * 
 * @details
 * Key Features:
 * - Automatic deep copy detection using SFINAE (Substitution Failure Is Not An Error)
 * - Deep copying for types with clone() method (e.g., Plant classes)
 * - Shallow copying fallback for types without clone()
 * - Compile-time decision making with zero runtime overhead
 * - Type-safe state preservation
 * 
 * Design Pattern:
 * - Pattern: Memento Pattern
 * - Role: Memento (stores internal state of Originator)
 * - Collaborators: Caretaker (manages mementos), Originator (creates and restores state)
 * 
 * @note This is a template class - implementations are in Memento.cpp which is included
 *       at the end of this header file.
 * 
 * @see Caretaker
 * 
 * Example usage:
 * @code
 * shared_ptr<Plant> originalPlant = make_shared<Plant>(...);
 * Memento<Plant> snapshot(originalPlant);  // Creates deep copy if Plant has clone()
 * 
 * // Later, restore the state
 * shared_ptr<Plant> restoredPlant = snapshot.getState();
 * @endcode
 */
template<typename T>
class Memento
{
private:
    /**
     * @brief Stored state of the object
     * 
     * Contains either a deep copy (if T has clone()) or shallow copy (shared pointer)
     * of the original object's state.
     */
    shared_ptr<T> state;
    
    /**
     * @brief Attempts deep copy using clone() method (SFINAE - preferred overload)
     * 
     * This overload is selected when type U has a clone() method. Uses decltype to
     * check at compile-time if ptr->clone() is a valid expression.
     * 
     * @tparam U The type being cloned (deduced from function call)
     * @param ptr Pointer to object to clone
     * @param int Dummy parameter for overload resolution (exact match priority)
     * @return shared_ptr<U> New shared pointer containing deep copy via clone()
     * 
     * @note The trailing return type decltype(ptr->clone(), shared_ptr<U>()) performs
     *       compile-time validation that clone() exists. The comma operator evaluates
     *       both expressions and returns the type of the second (shared_ptr<U>).
     */
    template<typename U>
    static auto tryClone(shared_ptr<U> ptr, int) -> decltype(ptr->clone(), shared_ptr<U>())
    {
        return ptr ? shared_ptr<U>(ptr->clone()) : nullptr;
    }
    
    /**
     * @brief Fallback shallow copy when clone() method doesn't exist (SFINAE)
     * 
     * This overload is selected when type U does NOT have a clone() method.
     * It performs a shallow copy by simply copying the shared_ptr.
     * 
     * @tparam U The type being copied (deduced from function call)
     * @param ptr Pointer to object to copy
     * @param long Dummy parameter for overload resolution (requires int->long conversion, lower priority)
     * @return shared_ptr<U> Shallow copy (same shared pointer, incremented reference count)
     * 
     * @note This has lower priority than the int overload due to implicit conversion cost.
     */
    template<typename U>
    static shared_ptr<U> tryClone(shared_ptr<U> ptr, long)
    {
        return ptr; // Fallback: shallow copy
    }

public:
    /**
     * @brief Constructs a Memento storing the given state
     * 
     * Creates a memento by attempting to deep copy the provided state. If the type T
     * has a clone() method, a deep copy is created. Otherwise, a shallow copy is made.
     * 
     * @param statePtr Shared pointer to the state to be preserved
     * 
     * @note The tryClone helper automatically selects between deep and shallow copy
     *       at compile-time based on whether T has a clone() method.
     */
    Memento(shared_ptr<T> statePtr);
    
    /**
     * @brief Retrieves the stored state
     * 
     * Returns the preserved state that was stored when the memento was created.
     * 
     * @return shared_ptr<T> The stored state
     * 
     * @note Currently returns the stored pointer directly. For complete immutability,
     *       consider also cloning on retrieval: return tryClone(state, 0);
     */
    shared_ptr<T> getState() const;
};

#include "../src/Memento.cpp"

#endif
