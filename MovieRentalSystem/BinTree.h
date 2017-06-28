//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// BINTREE.H
//---------------------------------------------------------------------------
// BinTree class: 
//	 also includes additional features
//   -- allows input and output of the whole BinTree
//   -- allows for assignment of BinTrees
//
// Implementation and assumptions:
//   -- Store only videos
//---------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

#include "Video.h"
#include <iostream>

class BinTree
{

public:
	BinTree();														// constructor			   
	~BinTree();														// destructor

	bool isEmpty() const;											// is tree empty
	void makeEmpty();												// make tree empty
	            
	Video* retrieve(const Video*);									// retrieve a video
	bool insert(Video *data);										// insert a video
	void displayAll() const;										// display videos in order

private:
	struct Node
	{
		Video* data;												// pointer to data object
		Node* left;													// left subtree pointer
		Node* right;												// right subtree pointer
	};
	Node* root;														// root of the tree

	void clear(Node* &current);										// makeEmpty() helper
	void inOrderDisplay(Node*) const;								// displayAll() helper
	Video* retrieveNode(Node* &current, const Video*) const;		// retrieve() helper
	bool insertNode(Node* &current, Video* data);					// insert() helper
};
#endif