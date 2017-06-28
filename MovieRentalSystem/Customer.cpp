//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CUSTOMER.CPP
//---------------------------------------------------------------------------
// Customer class:  
//   also includes additional features:
//   -- builds and stores customer data
//   -- allows output of customer data
//   -- stores a history of transactions
//   -- allows output of customer's transactions
//   -- allows comparison between customers
//---------------------------------------------------------------------------

#include "Customer.h"	

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new Customer with given ID and name info.
Customer::Customer(const int &newID, const string &newCustomer)
{
	id = newID;
	name = newCustomer;
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates Customer
Customer::~Customer()
{
}

//---------------------------------------------------------------------------
// getID 
// Preconditions:   None
// Postconditions:  Returns this Customer's ID.
int Customer::getID() const
{
	return id;
}

//---------------------------------------------------------------------------
// getName
// Preconditions:   None
// Postconditions:  Returns this Customer's name.
string Customer::getName() const
{
	return name;
}

//---------------------------------------------------------------------------
// getTransactions 
// Preconditions:   None
// Postconditions:  Returns this Customer's transaction history log.
vector<Transaction*> Customer::getTransactions() const
{
	return transactionLog;
}

//---------------------------------------------------------------------------
// setID
// Preconditions:   None
// Postconditions:  Set this Customer's ID with the input ID.
void Customer::setID(const int &newID)
{
	id = newID;
}

//---------------------------------------------------------------------------
// setName
// Preconditions:   None
// Postconditions:  Set this Customer's name with the input name.
void Customer::setName(const string &newName)
{
	name = newName;
}

//---------------------------------------------------------------------------
// addTransaction
// Preconditions:   None
// Postconditions:  adds a Transaction to the Customer's transaction history.
void Customer::addTransaction(Transaction* newTransaction)
{
	transactionLog.push_back(newTransaction);
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  Displays the customer's ID and name.
void Customer::display()
{
	cout << "Customer ID: " << id << endl << "Customer Name: " << name << endl;
}

//---------------------------------------------------------------------------
// operator==  
// Preconditions:	None
// Postconditions:  True is returned if customer info is the same, false is 
//					returned otherwise
bool Customer::operator==(const Customer &other) const
{
	return (id == other.id) && (name == other.name);
}

//---------------------------------------------------------------------------
// operator!=  
// Preconditions:	None
// Postconditions:  True is returned if customer info is not the same, false is 
//					returned otherwise.
bool Customer::operator!=(const Customer &other) const
{
	return (id != other.id) || (name != other.name);
}