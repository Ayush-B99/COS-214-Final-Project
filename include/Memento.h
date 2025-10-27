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

template<typename T>
class Memento
{
    private:
        shared_ptr<T> state;

    public:
        Memento(shared_ptr<T> state) : state(state) {}
    
        shared_ptr<T> getState() const;
};

#include "../src/Memento.cpp"

#endif
