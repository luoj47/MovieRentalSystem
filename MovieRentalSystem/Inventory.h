//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// INVENTORY.H
//---------------------------------------------------------------------------
// Inventory class:  Type of Transaction
//   also includes additional features:
//   -- Construction of Borrow object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Transaction.h"
//#include "VideoManager.h"

using namespace std;

class Inventory : public Transaction
{

public:
	Inventory(VideoManager &videos, string newTransaction);			// constructor
	~Inventory();													// destructor

	virtual void display();																// display transaction info
	virtual void displayForCustomer();													// display transaction info
																						// when displaying with customer
};
#endif