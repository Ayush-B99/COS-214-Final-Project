#ifndef COMPANY_H
#define COMPANY_H

class Company : Customer {

public:
	vector<Customers*> customers;

	void getDiscount();

	void addCustomer(Customer* c);

	void removeCustomer(Customer* c);
};

#endif
