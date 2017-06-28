//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// HISTORY.H
//---------------------------------------------------------------------------
// History class:  Type of Transaction
//   also includes additional features:
//   -- Construction of History object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"
#include "CustomerManager.h"

using namespace std;

class History : public Transaction
{

public:
	History(CustomerManager &customers, string newTransaction);							// constructor
	~History();																			// destructor

	virtual void display();																// display transaction info
	virtual void displayForCustomer();													// display transaction info
																						// when displaying with customer
};
#endif