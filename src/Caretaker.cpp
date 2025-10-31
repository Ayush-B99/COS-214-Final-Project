#include "../include/Caretaker.h"

/**
 * @brief Constructs an empty Caretaker
 * 
 * Initializes a caretaker with an empty memento history vector.
 * 
 * @tparam T The type of state being managed
 */
template<typename T>
Caretaker<T>::Caretaker()
{
}

/**
 * @brief Destroys the Caretaker and all stored mementos
 * 
 * @tparam T The type of state being managed
 */
template<typename T>
Caretaker<T>::~Caretaker()
{
}

/**
 * @brief Adds a memento to the end of the history
 * 
 * @tparam T The type of state being managed
 * @param m The memento to add
 */
template<typename T>
void Caretaker<T>::addMemento(Memento<T> m)
{
    mementos.push_back(m);
}

/**
 * @brief Removes the most recent memento (undo last save)
 * 
 * @tparam T The type of state being managed
 */
template<typename T>
void Caretaker<T>::undo()
{
    if (!mementos.empty())
    {
        mementos.pop_back();
    }
}

/**
 * @brief Retrieves a memento by index
 * 
 * @tparam T The type of state being managed
 * @param index The zero-based index of the memento to retrieve
 * @return Memento<T> The requested memento
 * @throws runtime_error if index is out of bounds
 */
template<typename T>
Memento<T> Caretaker<T>::getMemento(int index)
{
    if (index >= 0 && index < static_cast<int>(mementos.size()))
    {
        return mementos[index];
    }
    else
    {
        cout << "Invalid index" << endl;
        throw runtime_error("Memento index out of bounds");
    }
}

/**
 * @brief Retrieves the most recent memento without removing it
 * 
 * @tparam T The type of state being managed
 * @return Memento<T> The most recent memento
 * @throws runtime_error if no mementos exist
 */
template<typename T>
Memento<T> Caretaker<T>::getLastMemento()
{
    if (!mementos.empty())
    {
        return mementos.back();
    }
    else
    {
        cout << "No backup available" << endl;
        throw runtime_error("No mementos available in history");
    }
}
