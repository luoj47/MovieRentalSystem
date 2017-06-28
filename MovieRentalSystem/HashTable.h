//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// HASHTABLE.H
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

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Customer.h"

const int TABLESIZE = 100;

class HashTable
{

public:
	HashTable();														// constructor	
	~HashTable();														// destructor

	void put(Customer* newCustomer, const int &id);						// insert a customer
	Customer* get(const int &id);										// retrieve a customer

	void display();														// display customer list

private:
	struct Node															// Nodes for linked list
	{
		Node* next;														// pointer to next Node
		Customer* data;													// customer data
	};
	
	Node* customerTable[TABLESIZE];										// HashTable (separate chaining)
};
#endif
