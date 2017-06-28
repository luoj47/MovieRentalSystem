//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CUSTOMERMANAGER.CPP
//---------------------------------------------------------------------------
// CustomerManager class:  Manage customers
//   also includes additional features:
//   -- create new customers
//   -- display customer info
//   -- display customer transaction history
//   -- get customers from customer list
//
// Implementation and assumptions:
//   -- no duplicate customers
//   -- input data is correctly formatted and has valid data
//---------------------------------------------------------------------------

#include "CustomerManager.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new CustomerManager
CustomerManager::CustomerManager()
{
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates CustomerManager
CustomerManager::~CustomerManager()
{
}

//---------------------------------------------------------------------------
// createCustomer
// Preconditions:   None
// Postconditions:  Creates a new Customer and stores it in the HashTable
void CustomerManager::createCustomer(string line)
{
	int id; 
	string newCustomer;

	stringstream customerDetails(line);
	customerDetails >> id >> newCustomer;

	Customer* customer = new Customer(id, newCustomer);
	customerList.put(customer, id);
}

//---------------------------------------------------------------------------
// getCustomer
// Preconditions:   None
// Postconditions:  Returns a pointer to a customer if found, NULL if not
Customer* CustomerManager::getCustomer(const int &id)
{
	return customerList.get(id);
}

//---------------------------------------------------------------------------
// processCustomer
// Preconditions:   None
// Postconditions:  Builds the customer list from a file
void CustomerManager::processCustomers(ifstream &infile)
{
	string line;
	while(getline(infile, line))
	{
		createCustomer(line);
	}
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  displays a list of all customers in the customer list
void CustomerManager::display()
{
	customerList.display();
}

//---------------------------------------------------------------------------
// displayHistory
// Preconditions:   None
// Postconditions:  Displays the transaction history of the given Customer
void CustomerManager::displayHistory(Customer* cust) const
{
	vector<Transaction*> transactionLog = cust->getTransactions();
	for (size_t i = 0; i < transactionLog.size(); i++)
	{
		transactionLog[i]->displayForCustomer();
	}
}
