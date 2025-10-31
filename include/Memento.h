#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <typename T>
class Memento
{
private:
    T state;
    string date;

public:
    Memento(T state, string date) : state(state), date(date) {}

    T getState()
    {
        return &state;
    }

    string getDate()
    {
        return date;
    }

};

#endif