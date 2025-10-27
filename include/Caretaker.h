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

template<typename T>
class Caretaker
{
    private:
    	vector<Memento<T>> mementos;
    
    public:
        Caretaker();
        
        ~Caretaker();
        
    	void addMemento(Memento<T> m);
    
    	void undo();
    
    	Memento<T> getMemento(int index);
    
    	Memento<T> getLastMemento();
};

#include "../src/Caretaker.cpp"

#endif
