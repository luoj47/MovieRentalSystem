//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// HISTORY.CPP
//---------------------------------------------------------------------------
// History class:  Type of Transaction
//   also includes additional features:
//   -- Construction of History object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#include "History.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new History transaction using data from the passed in
//                  string and CustomerManager.
History::History(CustomerManager &customers, string newTransaction)
{
	// string stream to get parts of data from the transaction string
	stringstream transactionDetails(newTransaction);
	transactionDetails >> transactionType;

	int id;
	transactionDetails >> id;
	customer = customers.getCustomer(id);

	// Display customer's transactions if customer is not NULL. If customer is NULL
	// this transaction will be deleted in TransactionManager.
	if(customer != NULL)
	{
		customer->display();
		cout << "-----------------------------Customer Transactions-----------------------------" << endl;
		// Checks transaction log size to determine output.
		if(customer->getTransactions().size() != 0)
		{
			customers.displayHistory(customer);
			cout << endl;
		}
		else
		{
			cout << "This customer has not performed any transactions." << endl << endl;
		}
	}
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates History
History::~History()
{
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  Displays this History's info (customer, transaction type)
void History::display()
{
	customer->display();
	cout << transactionType << endl;
}

//---------------------------------------------------------------------------
// displayForCustomer
// Preconditions:   None
// Postconditions:  Displays this History's info (transaction type)
void History::displayForCustomer()
{
	cout << transactionType << endl;
}