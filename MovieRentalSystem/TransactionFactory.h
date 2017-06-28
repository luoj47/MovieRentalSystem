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

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "VideoManager.h"
#include "CustomerManager.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "Inventory.h"

class TransactionFactory
{
public:
	static Transaction* createTransaction(CustomerManager &customers, VideoManager &videos, string newTransaction);  // create new transaction
};
#endif