//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEO.H
//---------------------------------------------------------------------------
// Video class:  Video base class
//   also includes additional features:
//   -- use as a base class
//	 -- get info about vidoes
//	 -- display video info
//
// Implementation and assumptions:
//   -- child classes will inherit from this class
//---------------------------------------------------------------------------

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Video
{

public:
	Video();													// constructor
	virtual ~Video();											// destructor

	void manageStock(int newStock);								// add to stock

	char getGenre() const;										// return genre
	int getStock() const;										// return stock
	int getYear() const;										// return year of release
	string getTitle() const;									// return video title
	string getDirector() const;									// return director
	
	virtual void display();										// display video info
	virtual void displayForTransaction();                       // display video info for transactions

	virtual bool operator==(const Video* other) const = 0;		// == operator
	virtual bool operator!=(const Video* other) const = 0;		// != operator
	virtual bool operator<(const Video* other) const = 0;		// < operator
	virtual bool operator>(const Video* other) const = 0;		// > operator

	virtual bool isGreater(const Video* other) const = 0;		// greater than helper
	virtual bool isLess(const Video* other) const = 0;			// less than helper

protected:
	char genre;													
	int stock;									
	string director;
	string title;
	int year;
};
#endif