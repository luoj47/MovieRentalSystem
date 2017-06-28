//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// TRANSACTIONMANAGER.CPP
//---------------------------------------------------------------------------
// TransactionManager class:  Manage transactions
//   also includes additional features:
//   -- display all transaction info
//	 -- create new transactions
//	 -- load transactions
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//
// Design considerations:
//	 -- CustomerManager and VideoManager as passed into TransactionManager
//		so Transactions can be built.
//---------------------------------------------------------------------------

#include "TransactionManager.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  TransactionManager is created
TransactionManager::TransactionManager()
{
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate TransactionManager
TransactionManager::~TransactionManager()
{
	for(size_t i = 0; i < transactionHistory.size(); i++)
	{
		delete transactionHistory[i];
		transactionHistory[i] = NULL;
	}

	transactionHistory.clear();
}

//---------------------------------------------------------------------------
// createTransaction 
// Preconditions:   None
// Postconditions:  Creates a new transaction, link to customer, and add to vector
void TransactionManager::createTransaction(CustomerManager &customers, VideoManager &videos, string newTransaction)
{
	Transaction *a = TransactionFactory::createTransaction(customers, videos, newTransaction);
	
	// If "a" is null, an invalid command was given. If customer is NULL, then an invalid customer or video was
	// given. In these cases, the transaction will be deleted and error information will be printed.
	if(a != NULL)
	{
		if(a->getTransactionType() == 'B' || a->getTransactionType() == 'R' || a->getTransactionType() == 'H')
		{
			if(a->getCustomer() != NULL)
			{
				// Link to customer
				a->getCustomer()->addTransaction(a);
				transactionHistory.push_back(a);
			}
			else
			{
				delete a;
				a = NULL;
			}
		}
		else if(a->getTransactionType() == 'I')
		{
			transactionHistory.push_back(a);
		}
	}
	else
	{
		cout << "Invalid command entered. Invalid line: " + newTransaction << endl;
		delete a;
		a = NULL;
	}
}

//---------------------------------------------------------------------------
// processTransactions 
// Preconditions:   None
// Postconditions:	Read in file and create new transactions
void TransactionManager::processTransactions(CustomerManager &customers, VideoManager &videos, ifstream &infile)
{
	cout << "Processing Transactions..." << endl << endl;
	string line;
	while(getline(infile, line))
	{
		createTransaction(customers, videos, line);
	}
}

//---------------------------------------------------------------------------
// display 
// Preconditions:   None
// Postconditions:  Prints transactions
void TransactionManager::display()
{
	for(size_t i = 0; i < transactionHistory.size(); i++)
	{
		transactionHistory[i]->display();
		cout << endl;
	}
}