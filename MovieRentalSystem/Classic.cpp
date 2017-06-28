//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// CLASSIC.CPP
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

#include "Classic.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   newVideo is correctly formatted
// Postconditions:  All fields are correctly set
Classic::Classic(string newVideo)
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

	// Set actor
	ss >> temp;                  
	actor += temp;
	actor += ' ';
	ss >> temp;                
	actor += temp;

	// Set month
	ss >> month;           

	// Set year
	ss >> year;                 
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate video
Classic::~Classic()
{
}

//---------------------------------------------------------------------------
// getActor 
// Preconditions:   None
// Postconditions:  Returns the major actor
string Classic::getActor() const
{
	return actor;
}

//---------------------------------------------------------------------------
// getMonth 
// Preconditions:   None
// Postconditions:  Returns the release month
int Classic::getMonth() const
{
	return month;
}

//---------------------------------------------------------------------------
// display 
// Preconditions:   None
// Postconditions:  Displays video info
void Classic::display()
{
	cout << setw(7) << left << month << setw(6) << left << year <<
		setw(18) << left << actor << setw(23) << left <<
		title << setw(17) << left << director << setw(5) << left << stock << endl;
}

//---------------------------------------------------------------------------
// displayForTransaction
// Preconditions:   None
// Postconditions:  Displays video info in original format without stock. For use
//                  with Transaction displaying.
void Classic::displayForTransaction()
{
	cout << genre << " " << director << ", " << title << ", " << actor << " " 
		<< month << " " << year <<  endl;
}

//---------------------------------------------------------------------------
// operator==  
// Preconditions:	None
// Postconditions:  True is returned if video info is the same, false is 
//					returned otherwise
bool Classic::operator==(const Video* other) const
{
	const Classic* newClassic = (const Classic*)other;
	return (newClassic->getMonth() == month && newClassic->getYear() == year && newClassic->getActor() == actor);
}

//---------------------------------------------------------------------------
// operator!=  
// Preconditions:	None
// Postconditions:  False is returned if video info is the same, true is 
//					returned otherwise
bool Classic::operator!=(const Video* other) const
{
	const Classic* newClassic = (const Classic*)other;
	return !(newClassic->getMonth() == month && newClassic->getYear() == year && newClassic->getActor() == actor);
}

//---------------------------------------------------------------------------
// operator<
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Classic::operator<(const Video* other) const
{
	return isGreater(other);
}

//---------------------------------------------------------------------------
// operator>
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Classic::operator>(const Video* other) const
{
	return isLess(other);
}

//---------------------------------------------------------------------------
// isGreater
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is greater than input
bool Classic::isGreater(const Video* other) const
{
	const Classic *otherClassic = (const Classic*)other;
	return ((year > otherClassic->year) || ((year == otherClassic->year) && (month > otherClassic->month))
		|| ((year == otherClassic->year) && (month == otherClassic->month) && (actor > otherClassic->actor)));
}

//---------------------------------------------------------------------------
// isLess
// operator< helper method
// Preconditions:	None
// Postconditions:  True if this is less than input
bool Classic::isLess(const Video* other) const
{
	const Classic *otherClassic = (const Classic*)other;
	return ((year < otherClassic->year) || ((year == otherClassic->year) && (month < otherClassic->month))
		|| ((year == otherClassic->year) && (month == otherClassic->month) && (actor < otherClassic->actor)));
}