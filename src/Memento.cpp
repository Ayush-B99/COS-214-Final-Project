#include "../include/Memento.h"

/**
 * @brief Constructs a Memento with automatic deep/shallow copy detection
 * 
 * Implementation details:
 * - Calls tryClone(statePtr, 0) where 0 is type int
 * - Compiler first tries int overload (exact match)
 * - If T has clone(): deep copy is created
 * - If T lacks clone(): SFINAE removes int overload, long overload is used (shallow copy)
 * 
 * @tparam T The type of state being stored
 * @param statePtr Pointer to state to preserve
 */
template<typename T>
Memento<T>::Memento(shared_ptr<T> statePtr)
{
    state = tryClone(statePtr, 0);
}

/**
 * @brief Returns the stored state
 * 
 * @tparam T The type of state being retrieved
 * @return shared_ptr<T> The preserved state snapshot
 */
template<typename T>
shared_ptr<T> Memento<T>::getState() const
{
    return state;
}
