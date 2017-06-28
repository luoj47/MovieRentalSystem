//---------------------------------------------------------------------------
// Authors: Tyler Wong & Jesse Luo
// CSS 343 B
// Professor Erika Parsons
// 16 March 2016 
//
//---------------------------------------------------------------------------
// BINTREE.CPP
//---------------------------------------------------------------------------
// BinTree class: 
//	 also includes additional features
//   -- allows input and output of the whole BinTree
//   -- allows for assignment of BinTrees
//
// Implementation and assumptions:
//   -- Store only videos
//---------------------------------------------------------------------------

#include "BinTree.h"

//---------------------------------------------------------------------------
// Default Constructor 
// Creates an empty tree.
// Preconditions:	None
// Postconditions:  A new BinTree is created
BinTree::BinTree()
{
	root = NULL;
}

//---------------------------------------------------------------------------
// Destructor 
// Calls makeEmpty
// Preconditions:   this points to memory on the heap
// Postconditions:  this is deallocated
BinTree::~BinTree()
{
	makeEmpty();
}

//---------------------------------------------------------------------------
// Is Empty 
// Preconditions:   root points to memory on the heap
// Postconditions:  true if tree is empty, otherwise false
bool BinTree::isEmpty() const
{
	return root == NULL;
}

//---------------------------------------------------------------------------
// makeEmpty
// Preconditions:   root points to memory on the heap
// Postconditions:  make the tree empty so isEmpty returns true
void BinTree::makeEmpty()
{
	clear(root);
}

//---------------------------------------------------------------------------
// retrieve 
// Preconditions:   None
// Postconditions:	Finds the Video and returns a pointer to it
Video * BinTree::retrieve(const Video *toFind)
{
	return retrieveNode(root, toFind);
}

//---------------------------------------------------------------------------
// insert 
// Preconditions:   None
// Postconditions:  Inserts a new Video into the tree
bool BinTree::insert(Video *data)
{
	return insertNode(root, data);
}

//---------------------------------------------------------------------------
// displayAll
// Preconditions:	None
// Postconditions:	Videos are displayed in order
void BinTree::displayAll() const
{
	inOrderDisplay(root);
	cout << endl;
}

//---------------------------------------------------------------------------
// clear
// Preconditions:	None
// Postconditions:	Deallocates videos stored
void BinTree::clear(Node* &current)
{
	if (current != NULL)
	{
		// Traverse tree
		clear(current->left);
		clear(current->right);

		if (current->left == NULL && current->right == NULL)
		{
			// Deallocate video
			delete current->data;
			delete current;
			current = NULL;
		}
	}
}

//---------------------------------------------------------------------------
// inOrderDisplay
// Preconditions:	None
// Postconditions:	Videos are displayed in order
void BinTree::inOrderDisplay(Node *node) const
{
	// Base case
	if(node == NULL)
	{
		return;
	}

	// Traverse tree and display videos
	inOrderDisplay(node->left);
	node->data->display();
	inOrderDisplay(node->right);
}

//---------------------------------------------------------------------------
// retrieveNode
// Preconditions:   None
// Postconditions:	Finds the Video and returns a pointer to it
Video* BinTree::retrieveNode(Node* &current, const Video* toFind) const
{
	// Base case
	if (current == NULL)
	{
		return  NULL;     
	}

	// Found video
	if (*current->data == toFind) 
	{
		return current->data;
	}
	// Traverse tree
	else if (current->data->isGreater(toFind)) 
	{
		return retrieveNode(current->left, toFind);
	}
	// Traverse tree
	else 
	{
		return retrieveNode(current->right, toFind);
	}
}

//---------------------------------------------------------------------------
// insertNode
// Preconditions:   None
// Postconditions:  Inserts a new Video into the tree
bool BinTree::insertNode(Node* &current, Video* data)
{
	// Reached leaf node
	if (current == NULL) 
	{
		current = new Node();
		current->data = data;
		current->left = current->right = NULL;
		return true;
	}

	// Check for duplicates
	if (*(current->data) == data) 
	{
		current->data->manageStock(data->getStock());

		// Deallocate video
		delete data;                                                     
		data = NULL;
		return true;
	}

	// Traverse tree until leaf level is reached
	if (current->data->isGreater(data))
	{
		return insertNode(current->left, data);
	}
	else
	{
		return insertNode(current->right, data);
	}
}