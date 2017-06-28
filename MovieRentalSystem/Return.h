//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// RETURN.H
//---------------------------------------------------------------------------
// Return class:  Type of Transaction
//   also includes additional features:
//   -- Construction of Return object performs Return transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "Video.h"
#include "Transaction.h"

using namespace std;

class Return : public Transaction
{

public:
	Return(CustomerManager &customers, VideoManager &videos, string newTransaction);		// constructor
	~Return();																				// destructor

	virtual void display();																// display transaction info
	virtual void displayForCustomer();													// display transaction info
																						// when displaying with customer

protected:
	Video* videoData;
};
#endif