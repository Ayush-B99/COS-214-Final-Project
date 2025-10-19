#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {


public:
	virtual ~Iterator();

	virtual Plant* next() = 0;

	virtual bool hasNext() = 0;

	virtual Plant* current() = 0;

	virtual void reset() = 0;
};

#endif
