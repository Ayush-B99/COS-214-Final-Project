#ifndef STORAGE_H
#define STORAGE_H

class Storage {


public:
	virtual InventoryIterator* createIterator() = 0;
};

#endif
