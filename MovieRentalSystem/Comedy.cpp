//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// COMEDY.CPP
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

#include "Comedy.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   newVideo is correctly formatted
// Postconditions:  All fields are correctly set
Comedy::Comedy(string newVideo)
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
Comedy::~Comedy()
{
}

//---------------------------------------------------------------------------
// operator==  
// Preconditions:	None
// Postconditions:  True is returned if video info is the same, false is 
//					returned otherwise
bool Comedy::operator==(const Video* other) const
{
	if(other->getGenre() != 'F')
	{
		return false;
	}
	else
	{
		return (title == other->getTitle() && year == other->getYear());
	}
}

//---------------------------------------------------------------------------
// operator!=  
// Preconditions:	None
// Postconditions:  False is returned if video info is the same, true is 
//					returned otherwise
bool Comedy::operator!=(const Video* other) const
{
	if (other->getGenre() != 'F')
	{
		return !(title == other->getTitle() && year == other->getYear());
	}
	return false;
}

//---------------------------------------------------------------------------
// operator<
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Comedy::operator<(const Video* other) const
{
	return isGreater(other);
}

//---------------------------------------------------------------------------
// operator>
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Comedy::operator>(const Video* other) const
{
	return isLess(other);
}

//---------------------------------------------------------------------------
// isGreater
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Comedy::isGreater(const Video* other) const
{
	const Comedy* otherComedy = (const Comedy*)other;
	return ((title > otherComedy->title) || ((title == otherComedy->title) && (year > otherComedy->year)));
}

//---------------------------------------------------------------------------
// isLess
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Comedy::isLess(const Video * other) const
{
	const Comedy* otherComedy = (const Comedy*)other;
	return ((title < otherComedy->title) || ((title == otherComedy->title) && (year < otherComedy->year)));
}
