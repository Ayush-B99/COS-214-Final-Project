#ifndef CARETAKER<T>_H
#define CARETAKER<T>_H

class Caretaker<T> {

public:
	vector<Memento<T>> mementos;

	void addMemento(Memento<T> m);

	void undo();

	Memento<T> getMemento(int index);

	Memento<T> getLastMemento();
};

#endif
