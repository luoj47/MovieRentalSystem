//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEOMANAGER.H
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

#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include "BinTree.h"
#include "VideoFactory.h"
#include "Video.h"
#include "Comedy.h"
#include <fstream>
#include <iostream>
#include <sstream>

class VideoManager
{

public:
	VideoManager();									// constructor
	~VideoManager();								// destructor

	Video* getVideo(Video* toFind, char genre);		// find a video

	void createVideo(string newVideo);				// create new video
	void processVideos(ifstream &infile);			// process input file

	void display() const;							// display all videos
	void displayErrors() const;						// display errors on input

private:
	void addError(string);							// add a new error
	string errors;									// holds input errors
	int numOfErrors;								// number of errors logged

	BinTree comedyTree;								// BSTree for comedy videos
	BinTree dramaTree;								// BSTree for drama videos
	BinTree classicTree;							// BSTree for classic videos
};
#endif