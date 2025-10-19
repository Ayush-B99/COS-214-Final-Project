#ifndef CARETAKER<T>_H
#define CARETAKER<T>_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

class Caretaker<T> {

public:
	vector<Memento<T>> mementos;

	void addMemento(Memento<T> m);

	void undo();

	Memento<T> getMemento(int index);

	Memento<T> getLastMemento();
};

#endif
