//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// HASHTABLE.CPP
//---------------------------------------------------------------------------
// HashTable class:  
//   also includes additional features:
//   -- builds a HashTable of Customers, one customer as a time
//   -- allows getting of Customers in HashTable
//   -- allows output of Hastable
//
// Implementation and assumptions:
//   -- only stores customers
//---------------------------------------------------------------------------

#include "HashTable.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new HashTable and initializes each index to NULL
HashTable::HashTable()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		customerTable[i] = NULL;
	}
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates HashTable, deleting each node and customer data
HashTable::~HashTable()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		Node* current = customerTable[i];
		while(current != NULL)
		{
			Node* toDelete = current;
			current = current->next;

			delete toDelete->data;
			delete toDelete;
			toDelete = NULL;
		}
	}
}

//---------------------------------------------------------------------------
// put
// Preconditions:   None
// Postconditions:  inserts a customer into the HashTable
void HashTable::put(Customer* newCustomer, const int &id)
{
	// finds proper index by modding by the size of the HashTable
	int insertionIndex = id % TABLESIZE;

	Node* newNode = new Node;
	newNode->data = newCustomer;
	
	// Places new Customer in the correct order in the linked list at the index
	// Customers will be ordered from lowest to highest (by ID)
	if(customerTable[insertionIndex] == NULL || 
		(customerTable[insertionIndex]->data->getID() > newNode->data->getID()))
	{
		newNode->next = customerTable[insertionIndex];
		customerTable[insertionIndex] = newNode;
	}
	else
	{
		Node* current = customerTable[insertionIndex];
		while(current->next != NULL && (current->next->data->getID() < newNode->data->getID()))
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

//---------------------------------------------------------------------------
// get
// Preconditions:   None
// Postconditions:  Returns a pointer to a customer in the HashTable
Customer* HashTable::get(const int &id)
{
	// Finds the index the customer is at and goes through linked
	// list at that index to find customer
	int getIndex = id % TABLESIZE;
	Node* current = customerTable[getIndex];
	while(current != NULL)
	{
		if(current->data->getID() == id)
		{
			return current->data;
		}
		current = current->next;
	}
	return NULL;
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  displays all customers in the HashTable
void HashTable::display()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		Node* current = customerTable[i];
		while(current != NULL)
		{
			current->data->display();
			current = current->next;
		}
	}
}