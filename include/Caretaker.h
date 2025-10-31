#ifndef CARETAKER_H
#define CARETAKER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

#include "Memento.h"

using namespace std;

template <typename T>
class Caretaker
{

public:
    vector<Memento<T>> mementos;

    void addMemento(Memento<T> m);

    void undo();

    Memento<T> getMemento(int index);

    Memento<T> getLastMemento();
};

 #endif