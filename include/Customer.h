#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {


public:
	virtual double getDiscount() = 0;

	~Customer();
};

#endif
