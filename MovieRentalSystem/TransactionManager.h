//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// TRANSACTIONMANAGER.H
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
//	 -- CustomerManager and VideoManager is passed into TransactionManager
//		so Transactions can be built.
//---------------------------------------------------------------------------

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include "TransactionFactory.h"
#include "CustomerManager.h"
#include "VideoManager.h"
#include <vector>

class TransactionManager
{
	
public:
	TransactionManager();						// constructor
	~TransactionManager();						// destructor
	
	void createTransaction(CustomerManager &customers, VideoManager &videos, string newTransaction);	// create new transaction
	void processTransactions(CustomerManager &customers, VideoManager &videos, ifstream &infile);		// process input file
	void display();								// display all transactions

private:
	vector<Transaction*> transactionHistory;	// vector to hold all transactions
};
#endif