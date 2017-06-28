//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEO.CPP
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

#include "Video.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new Video and variables are set to default
Video::Video()
{
	genre = ' ';
	stock = 0;
	director = "";
	title = "";
	year = 0;
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate video
Video::~Video()
{
}

//---------------------------------------------------------------------------
// manageStock 
// Preconditions:   None
// Postconditions:  Increment stock
void Video::manageStock(int newStock)
{
	stock += newStock;
}

//---------------------------------------------------------------------------
// getGenre 
// Preconditions:   None
// Postconditions:  Returns the genre
char Video::getGenre() const
{
	return genre;
}

//---------------------------------------------------------------------------
// getStock 
// Preconditions:   None
// Postconditions:  Returns the current stock
int Video::getStock() const
{
	return stock;
}

//---------------------------------------------------------------------------
// getYear 
// Preconditions:   None
// Postconditions:  Returns the release year
int Video::getYear() const
{
	return year;
}

//---------------------------------------------------------------------------
// getTitle 
// Preconditions:   None
// Postconditions:  Returns the video title
string Video::getTitle() const
{
	return title;
}

//---------------------------------------------------------------------------
// getDirector 
// Preconditions:   None
// Postconditions:  Returns the video director
string Video::getDirector() const
{
	return director;
}

//---------------------------------------------------------------------------
// display 
// Preconditions:   None
// Postconditions:  Displays video info
void Video::display()
{
	cout << setw(33) << left << title << setw(1) << right << year
		<< setw(20) << left << director << setw(20) << left << stock << endl;
}

//---------------------------------------------------------------------------
// displayForTransaction
// Preconditions:   None
// Postconditions:  Displays video info in original format without stock. For use
//                  with Transaction displaying.
void Video::displayForTransaction()
{
	cout << genre << " " << director << ", " << title << ", " << year <<  endl;
}