//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// INVENTORY.CPP
//---------------------------------------------------------------------------
// Inventory class:  Type of Transaction
//   also includes additional features:
//   -- Construction of Borrow object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#include "Inventory.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new Inventory transaction using data from the passed in
//                  string and VideoManager
Inventory::Inventory(VideoManager &videos, string newTransaction)
{
	// no customer is associate with inventory, so it is set to NULL
	transactionType = 'I';
	customer = NULL;

	// display video inventory
	videos.display();
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates Inventory
Inventory::~Inventory()
{
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  Displays this Inventorys's info (transaction type)
void Inventory::display()
{
	cout << transactionType << endl;
}

//---------------------------------------------------------------------------
// displayForCustomer
// Preconditions:   None
// Postconditions:  Displays this Inventorys's info (transaction type)
void Inventory::displayForCustomer()
{
	cout << transactionType << endl;
}