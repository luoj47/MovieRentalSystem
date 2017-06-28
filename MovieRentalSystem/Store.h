//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// STORE.H
//---------------------------------------------------------------------------
// Store class:  Main store class
//   also includes additional features:
//   -- build new inventory
//	 -- build new customer list
//	 -- perform transactions 
//---------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include "CustomerManager.h"
#include "TransactionManager.h"
#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;

class Store
{

public:
	Store();										// constructor
	~Store();										// destructor

	void buildInventory(ifstream &infile);			// build new inventory
	void buildCustomerList(ifstream &infile);		// build new customer list
	void performTransactions(ifstream &infile);		// perform transactions

private:
	VideoManager inventory;							// manage inventory
	CustomerManager customerList;					// manage customers
	TransactionManager transactions;				// manage transactions
};
#endif