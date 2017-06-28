//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// COMEDY.H
//---------------------------------------------------------------------------
// Comedy class:  type of Video
//   also includes additional features:
//   -- allows for equality of two videos
//   -- allows for comparison of two videos
//   -- display video info
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "Video.h"
#include <sstream>

class Comedy : public Video
{
public:
	Comedy(string newVideo);								// constructor
	~Comedy();												// destructor

	virtual bool operator==(const Video* other) const;		// == operator
	virtual bool operator!=(const Video* other) const;		// != operator
	virtual bool operator<(const Video* other) const;		// < operator
	virtual bool operator>(const Video* other) const;		// > operator

	virtual bool isGreater(const Video* other) const;		// greater than helper
	virtual bool isLess(const Video* other) const;			// less than helper
};
#endif