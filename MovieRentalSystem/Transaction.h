//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// TRANSACTION.H
//---------------------------------------------------------------------------
// Transaction class:  Transaction base class
//   also includes additional features:
//   -- use as a base class
//   -- get info about a transaction
//   -- display transaction information
//
// Implementation and assumptions:
//   -- child classes will inherit from this class
//---------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "VideoManager.h"
#include "CustomerManager.h"
#include <string>
#include <sstream>

class Customer;

using namespace std;

class Transaction
{

public:
	Transaction();										// constructor
	~Transaction();										// destructor

	char getTransactionType();							// get transaction type
	Customer* getCustomer();							// get customer associated with this transaction
	virtual void display() = 0;							// display transaction information
	virtual void displayForCustomer() = 0;				// display transaction info when displayed with customer

protected:
	char transactionType;
	Customer* customer;
};
#endif