//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CUSTOMER.H
//---------------------------------------------------------------------------
// Customer class:  
//   also includes additional features:
//   -- builds and stores customer data
//   -- allows output of customer data
//   -- stores a history of transactions
//   -- allows output of customer's transactions
//   -- allows comparison between customers
//---------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

class Transaction;

using namespace std;

class Customer
{

public:
	Customer(const int &newID, const string &newCustomer);				// constructor
	~Customer();														// destructor	

	int getID() const;													// get Customer ID
	string getName() const;												// get Customer name
	vector<Transaction*> getTransactions() const;						// get Customer transaction history

	void setID(const int &newID);										// set customer ID
	void setName(const string &newName);								// set customer name
	void addTransaction(Transaction* newTransaction);					// add transaction to customer transaction history

	void display();														// display customer information

	bool operator==(const Customer &other) const;						// == operator
	bool operator!=(const Customer &other) const;						// != operator

private:
	vector<Transaction*> transactionLog;								// customer transaction history
	int id;
	string name;
};
#endif