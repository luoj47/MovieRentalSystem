//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// VIDEOFACTORY.H
//---------------------------------------------------------------------------
// VideoFactory class:  create new videos
//
// Implementation and assumptions:
//   -- the input is correctly formatted
//   -- the input has all data fields
//---------------------------------------------------------------------------

#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H

#include "Video.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

class VideoFactory
{
public:
	static Video* createVideo(string newVideo);				// create new video
};
#endif
