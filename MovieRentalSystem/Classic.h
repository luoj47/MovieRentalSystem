//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CLASSIC.H
//---------------------------------------------------------------------------
// Classic class:  type of Video
//   also includes additional features:
//   -- allows for equality of two videos
//   -- allows for comparison of two videos
//   -- display video info
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H

#include "Video.h"
#include <sstream>

class Classic : public Video
{
public:
	Classic(string newVideo);								// constructor
	~Classic();												// destructor

	string getActor() const;								// return major actor
	int getMonth() const;									// return month of release

	void display();											// display video info
	void displayForTransaction();							// display video info for transactions
	
	virtual bool operator==(const Video* other) const;		// == operator
	virtual bool operator!=(const Video* other) const;		// != operator
	virtual bool operator<(const Video* other) const;		// < operator
	virtual bool operator>(const Video* other) const;		// > operator

	virtual bool isGreater(const Video* rhs) const;			// greater than helper
	virtual bool isLess(const Video* rhs) const;			// less than helper

protected:
	string actor;											// major actor
	int month;												// month of release
};
#endif