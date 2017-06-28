//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEOFACTORY.CPP
//---------------------------------------------------------------------------
// VideoFactory class:  create new videos
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#include "VideoFactory.h"

//---------------------------------------------------------------------------
// createVideo
// Preconditions:   newVideo is correctly formatted
// Postconditions:  Construct a new Video and a pointer to it is returned
Video * VideoFactory::createVideo(string newVideo)
{
	Video *  video = NULL; 
	switch (newVideo[0])  
	{
	case 'F':
		video = (Video*) new Comedy(newVideo); 
		break;
	case 'D':
		video = (Video*) new Drama(newVideo);
		break;
	case 'C':
		video = (Video*) new Classic(newVideo);
		break;
	default:
		video = NULL;                    
		break;
	}
	return video;                         
}