//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEOMANAGER.CPP
//---------------------------------------------------------------------------
// VideoManager class:  Manage videos
//   also includes additional features:
//   -- display all video info
//	 -- display input errors
//	 -- create new videos
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#include "VideoManager.h"

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  Construct a new VideoManager
VideoManager::VideoManager()
{
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   None
// Postconditions:  Deallocate VideoManager
VideoManager::~VideoManager()
{
}

//---------------------------------------------------------------------------
// getVideo 
// Preconditions:   None
// Postconditions:  Returns a pointer if the video is found, NULL otherwise
Video * VideoManager::getVideo(Video* toFind, char genre)
{
	switch (genre)
	{
	case 'F':
		return comedyTree.retrieve(toFind);
		break;
	case 'D':
		return dramaTree.retrieve(toFind);
		break;
	case 'C':
		return classicTree.retrieve(toFind);
		break;
	default:
		return NULL;
		break;
	}
}

//---------------------------------------------------------------------------
// createVideo 
// Preconditions:   None
// Postconditions:  Creates a new video and stores it in the appropriate tree
void VideoManager::createVideo(string newVideo)
{
	Video* a = VideoFactory::createVideo(newVideo);

	switch (newVideo[0])
	{
	case 'F':
		comedyTree.insert(a);
		break;
	case 'D':
		dramaTree.insert(a);
		break;
	case 'C':
		classicTree.insert(a);
		break;
	default:
		addError(newVideo);
		break;
	}
}

//---------------------------------------------------------------------------
// processVideos 
// Preconditions:   None
// Postconditions:	Read in file and create new videos
void VideoManager::processVideos(ifstream & infile)
{
	numOfErrors = 0;
	string line;   

	for (;;) 
	{
		getline(infile, line);  

		if (infile.eof())
		{
			break;
		}
		VideoManager::createVideo(line);
	}
}

//---------------------------------------------------------------------------
// display 
// Preconditions:   None
// Postconditions:  Prints videos in correct order
void VideoManager::display() const
{
	cout << "------------------------------------VIDEOS------------------------------------" << endl;
	// Print comedies
	cout << "-----------------------------------Comedies-----------------------------------" << endl;
	cout << setw(33) << left << "Title" << setw(1) << right << "Year"
		<< setw(20) << left << "Director" << setw(20) << left << "Stock" << endl;

	comedyTree.displayAll();
	cout << endl;

	// Print dramas
	cout << "------------------------------------Dramas------------------------------------" << endl;
	cout << setw(33) << left << "Title" << setw(1) << right << "Year"
		<< setw(20) << left << "Director" << setw(20) << left << "Stock" << endl;

	dramaTree.displayAll();
	cout << endl;

	// Print classics
	cout << "-----------------------------------Classics-----------------------------------" << endl;
	cout << setw(7) << left << "Month" << setw(6) << left << "Year" <<
		setw(18) << left << "Actor" << setw(23) << left <<
		"Title" << setw(17) << left << "Director" << setw(5) << left << "Stock" << endl;

	classicTree.displayAll();
	cout << endl;
}

//---------------------------------------------------------------------------
// displayErrors 
// Preconditions:   None
// Postconditions:  Prints errors on input
void VideoManager::displayErrors() const
{
	cout << "-----------------------------Inventory Build Errors-----------------------------" << endl;
	cout << "Invalid Lines:" << endl;
	cout << errors << endl;
	cout << endl;
}

//---------------------------------------------------------------------------
// addError 
// Preconditions:   None
// Postconditions:  Adds a new error
void VideoManager::addError(string error)
{
	numOfErrors++;
	ostringstream temp;
	temp << numOfErrors;

	// Format and add error
	errors += temp.str() + ". ";
	errors += error;
	errors += "\n";
}