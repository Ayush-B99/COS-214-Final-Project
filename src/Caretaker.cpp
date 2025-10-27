// #include "../include/Caretaker.h"

template<typename T>
Caretaker<T>::Caretaker()
{
}

template<typename T>
Caretaker<T>::~Caretaker()
{
}

template<typename T>
void Caretaker<T>::addMemento(Memento<T> m)
{
    mementos.push_back(m);
}

template<typename T>
void Caretaker<T>::undo()
{
    if (!mementos.empty())
    {
        mementos.pop_back();
    }
}

template<typename T>
Memento<T> Caretaker<T>::getMemento(int index)
{
    if (index >= 0 && index < mementos.size())
    {
        return mementos[index];
    }
    else
    {
        cout << "Invalid index" << endl;

        return NULL;
    }
}

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

        return NULL;
    }
}
