//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// TRANSACTIONFACTORY.H
//---------------------------------------------------------------------------
// TransactionFactory class:  create new transactions
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#include "TransactionFactory.h"

//---------------------------------------------------------------------------
// createTransaction
// Preconditions:   newTransaction is correctly formatted
// Postconditions:  A new transaction is created and a pointer to it is returned
Transaction* TransactionFactory::createTransaction(CustomerManager &customers, VideoManager &videos, string newTransaction)
{
	Transaction* transaction = NULL;
	switch (newTransaction[0])  
	{
	case 'B':
		transaction = (Transaction*) new Borrow(customers, videos, newTransaction); 
		break;
	case 'R':
		transaction = (Transaction*) new Return(customers, videos, newTransaction);
		break;
	case 'H':
		transaction = (Transaction*) new History(customers, newTransaction);
		break;
	case 'I':
		transaction = (Transaction*) new Inventory(videos, newTransaction);
		break;
	default:
		transaction = NULL;
		break;
	}
	return transaction;        
}