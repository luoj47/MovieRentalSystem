//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// DRAMA.H
//---------------------------------------------------------------------------
// Drama class:  type of Video
//   also includes additional features:
//   -- allows for equality of two videos
//   -- allows for comparison of two videos
//   -- display video info
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "Video.h"
#include <sstream>

class Drama : public Video
{
public:
	Drama(string newVideo);									// constructor
	~Drama();												// destructor
	
	virtual bool operator==(const Video* other) const;		// == operator
	virtual bool operator!=(const Video* other) const;		// != operator
	virtual bool operator<(const Video* other) const;		// < operator
	virtual bool operator>(const Video* other) const;		// > operator

	virtual bool isGreater(const Video* rhs) const;			// greater than helper
	virtual bool isLess(const Video* rhs) const;			// less than helper
};
#endif