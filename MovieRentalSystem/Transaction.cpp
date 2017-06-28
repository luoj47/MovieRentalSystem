//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// TRANSACTION.CPP
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

#include "Transaction.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new Transaction
Transaction::Transaction()
{
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocate Transaction
Transaction::~Transaction()
{
}

//---------------------------------------------------------------------------
// getCustomer
// Preconditions:   None
// Postconditions:  Returns Customer associated with this transaction
Customer* Transaction::getCustomer()
{
	return customer;
}

//---------------------------------------------------------------------------
// getTransactionType
// Preconditions:   None
// Postconditions:  Returns this transaction's type
char Transaction::getTransactionType()
{
	return transactionType;
}

