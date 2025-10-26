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
        
    	void addMemento(Memento<T> m)
    	{
    		mementos.push_back(m);
    	}
    
    	void undo()
    	{
    		if (!mementos.empty())
    		{
    			mementos.pop_back();
    		}
    	}
    
    	Memento<T> getMemento(int index)
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
    
    	Memento<T> getLastMemento()
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
};

#endif
