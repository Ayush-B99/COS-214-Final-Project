#include "../include/Company.h"

double Company::getDiscount()
{
	double totalDiscount = 0.0;
	for (Customer *customer : customers)
	{
		totalDiscount += customer->getDiscount();
	}
	return totalDiscount;
}

Company::~Company()
{
	for (Customer *customer : customers)
	{
		delete customer;
	}
	customers.clear();
}

void Company::addCustomer(Customer *c)
{
	if (c != nullptr)
	{
		customers.push_back(c);
	}
}

void Company::removeCustomer(Customer *c)
{
	for (auto it = customers.begin(); it != customers.end();)
	{
		if (*it == c)
		{
			customers.erase(it);
			break;
		}
	}
}