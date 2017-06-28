//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CUSTOMERMANAGER.H
//---------------------------------------------------------------------------
// CustomerManager class:  Manage customers
//   also includes additional features:
//   -- create new customers
//   -- display customer info
//   -- display customer transaction history
//   -- get customers from customer list
//
// Implementation and assumptions:
//   -- no duplicate customers
//   -- input data is correctly formatted and has valid data
//---------------------------------------------------------------------------

#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "HashTable.h"
#include "Customer.h"
#include "Transaction.h"
#include <fstream>
#include <sstream>

class CustomerManager
{

public:
	CustomerManager();									// constructor
	~CustomerManager();									// destructor

	void createCustomer(string line);					// create new Customer
	Customer* getCustomer(const int &id);				// find a Customer

	void processCustomers(ifstream &infile);			// build customer list
	void display();										// display customer list
	void displayHistory(Customer* cust) const;			// display transaction history for a customer

private:
	HashTable customerList;								// HashTable to store customers
};
#endif