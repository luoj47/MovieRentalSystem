//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// BORROW.CPP
//---------------------------------------------------------------------------
// Borrow class:  Type of Transaction
//   also includes additional features:
//   -- Construction of Borrow object performs Borrow transaction
//   -- Allows output of transaction information
//
// Implementation and assumptions:
//   -- Input data will be correctly formatted (commas, spaces, etc.)
//---------------------------------------------------------------------------

#include "Borrow.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new Borrow transaction using data from the passed in
//                  string, CustomerManager and VideoManager
Borrow::Borrow(CustomerManager &customers, VideoManager &videos, string newTransaction)
{
	// string stream to get parts of data from the transaction string
	stringstream transactionDetails(newTransaction);
	transactionDetails >> transactionType;

	int id;
	transactionDetails >> id;
	customer = customers.getCustomer(id);

	// build transaction if customer is NOT null. A null customer means the the customer
	// given doesn't exist. The transaction object will be deleted in TransactionManager.
	if(customer != NULL)
	{
		char mediaType;
		transactionDetails >> mediaType;
		// For different media types than DVD, do stuff here

		string remaining;
		getline(transactionDetails, remaining);
		char videoGenre = remaining[1];

		// Creates a new video for use to find the corresponding video in VideoManager
		Video* toFind = NULL;
		if(videoGenre == 'F')
		{
			string genre, title, year;
			stringstream r(remaining);
			r >> genre;
			getline(r, title, ',');
			r >> year;
			toFind = (Video*) new Comedy(genre + ", 0, NULL," + title + ", " + year);
		}
		else if(videoGenre == 'D')
		{
			string genre, director, title;
			stringstream r(remaining);
			r >> genre;
			getline(r, director, ',');
			getline(r, title, ',');
			toFind = (Video*) new Drama(genre + ", 0," + director + "," + title + ", 0");
		}
		else if(videoGenre == 'C')
		{
			string genre, month, year, actor;
			stringstream r(remaining);
			r >> genre >> month >> year;
			getline(r, actor, ',');
			toFind = (Video*) new Classic(genre + ", 0, NULL, NULL," + actor + " " + month + " " +  year);
		}

		// Find video based on created video
		videoData = videos.getVideo(toFind, videoGenre);
		delete toFind;
		toFind = NULL;

		if(videoData != NULL)
		{
			// Borrow only possible if stock is available. Customer set to null
			// if not enough stock is available because the transaction is not valid
			// and will be deleted.
			if(videoData->getStock() >= 1)
			{
				videoData->manageStock(-1);
			}
			else
			{
				cout << "Borrow command will result in a negative stock: " + newTransaction << endl;
				customer = NULL;
			}
		}
		// If video is NULL, then the video information in the transaction was invalid. Customer
		// will also be set to null for transaction deletion.
		else
		{
			cout << "Non-Existent video entered. Invalid Line: " + newTransaction << endl;
			customer = NULL;
		}
	}
	else
	{
		cout << "Non-Existent customer entered. Invalid Line: " + newTransaction << endl;
	}
}

//---------------------------------------------------------------------------
// Destructor
// Preconditions:   None
// Postconditions:  Deallocates Borrow
Borrow::~Borrow()
{
}

//---------------------------------------------------------------------------
// display
// Preconditions:   None
// Postconditions:  Displays this Borrow's info (customer, transaction type, video)
void Borrow::display()
{
	customer->display();
	cout << transactionType << " ";
	videoData->display();
}

//---------------------------------------------------------------------------
// displayForCustomer
// Preconditions:   None
// Postconditions:  Displays this Borrow's info (customer, transaction type, video
//					info without stock information).
void Borrow::displayForCustomer()
{
	cout << transactionType << " ";
	videoData->displayForTransaction();
}