//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// BORROW.H
//---------------------------------------------------------------------------
// Borrow class:  Type of Transaction
//   also includes additional features:
//   -- Construction of Borrow object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include "Video.h"
#include "Transaction.h"

using namespace std;

class Borrow : public Transaction
{

public:
	Borrow(CustomerManager &customers, VideoManager &videos, string newTransaction);	// constructor
	~Borrow();																			// destructor

	virtual void display();																// display transaction info
	virtual void displayForCustomer();													// display transaction info
																						// when displaying with customer

protected:
	Video* videoData;
};
#endif