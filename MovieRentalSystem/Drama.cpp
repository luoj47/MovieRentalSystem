//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// DRAMA.CPP
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

#include "Drama.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   newVideo is correctly formatted
// Postconditions:  All fields are correctly set
Drama::Drama(string newVideo)
{
	stringstream ss;
	ss << newVideo;
	string temp;

	// Set video genre
	getline(ss, temp, ',');
	genre = temp[0];

	// Set stock
	getline(ss, temp, ',');
	stringstream(temp) >> stock;

	// Set Director
	getline(ss, director, ',');

	// Set title
	getline(ss, title, ',');

	// Set year
	getline(ss, temp, ',');
	stringstream(temp) >> year;
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate video
Drama::~Drama()
{
}

//---------------------------------------------------------------------------
// operator==  
// Preconditions:	None
// Postconditions:  True is returned if video info is the same, false is 
//					returned otherwise
bool Drama::operator==(const Video* other) const
{
	if (other->getGenre() != 'D')
	{
		return false;
	}
	else
	{
		return (director == other->getDirector() && title == other->getTitle());
	}
}

//---------------------------------------------------------------------------
// operator!=  
// Preconditions:	None
// Postconditions:  False is returned if video info is the same, true is 
//					returned otherwise
bool Drama::operator!=(const Video* other) const
{
	if (other->getGenre() != 'D')
	{
		return !(director == other->getDirector() && title == other->getTitle());
	}
	return false;
}

//---------------------------------------------------------------------------
// operator<
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Drama::operator<(const Video* other) const
{
	return isGreater(other);
}

//---------------------------------------------------------------------------
// operator>
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Drama::operator>(const Video* other) const
{
	return isLess(other);
}

//---------------------------------------------------------------------------
// isGreater
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Drama::isGreater(const Video* other) const
{
	const Drama* otherDrama = (const Drama*)other;
	return ((director > otherDrama->director) || ((director == otherDrama->director) && (title > otherDrama->title)));
}

//---------------------------------------------------------------------------
// isLess
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Drama::isLess(const Video* other) const
{
	const Drama* otherDrama = (const Drama*)other;
	return ((director < otherDrama->director) || ((director == otherDrama->director) && (title < otherDrama->title)));
}