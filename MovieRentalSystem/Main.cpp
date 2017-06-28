//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// MAIN.CPP
//---------------------------------------------------------------------------
// Main
//   -- Entry point to the program
//
// Assumptions
// - Input data file (.txt) is correctly formatted (correct comma and space placement)
// - No duplicate Customers (Customers with the same ID)
//---------------------------------------------------------------------------

#include "Store.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	// Initialize and build inventory
	Store videoStore;
	ifstream videoFile("data4movies.txt");
	if (!videoFile) 
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	videoStore.buildInventory(videoFile);

	// Initizalize and build customers
	ifstream customerFile("data4customers.txt");
	if (!customerFile) 
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	videoStore.buildCustomerList(customerFile);

	// Initialize and perform transactions
	ifstream transactionFile("data4commands.txt");
	if (!transactionFile) 
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	videoStore.performTransactions(transactionFile);

	return 0;
}
