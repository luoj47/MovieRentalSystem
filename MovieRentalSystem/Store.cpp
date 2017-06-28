//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// STORE.CPP
//---------------------------------------------------------------------------
// Store class:  Main store class
//   also includes additional features:
//   -- build new inventory
//	 -- build new customer list
//	 -- perform transactions 
//
// Design Considerations:
//   -- We decided to pass CustomerManager and VideoManager to
//      TransactionManager so that TransactionManager can use these
//      classes to build Transactions (which require pointers to data
//      in CustomerManager and VideoManager). So, TransactionManager
//      "has-a" CustomerManager and VideoManager.
//---------------------------------------------------------------------------

#include "Store.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Constructs a new Store
Store::Store()
{
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate store
Store::~Store()
{
}

//---------------------------------------------------------------------------
// buildInventory 
// Preconditions:   Input is properly formatted
// Postconditions:  A new inventory is initialized and built
void Store::buildInventory(ifstream &infile)
{
	inventory.processVideos(infile);
	// for testing proper inventory building
	//inventory.display(); 

	inventory.displayErrors();
}

//---------------------------------------------------------------------------
// buildCustomerList 
// Preconditions:   Input is properly formatted
// Postconditions:  A new customer list is initialized and built
void Store::buildCustomerList(ifstream &infile)
{
	customerList.processCustomers(infile);
	// for testing proper customer building
	//customerList.display();
}
	
//---------------------------------------------------------------------------
// performTransactions 
// Preconditions:   Input is properly formatted
// Postconditions:  Transactions are initialized and performed
void Store::performTransactions(ifstream &infile)
{
	transactions.processTransactions(customerList, inventory, infile);
	// for testing proper transaction building
	//transactions.display();
}