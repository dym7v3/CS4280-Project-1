/*
 * node.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Dennis Moyseyev
 */

#ifndef NODE_H_
#define NODE_H_

#include<string>
#include<iostream>
#include<list>

using namespace std;

class  BinaryTree
{
private:

	struct TreeNode
	{
		list<int> digitList; // the string of letter in the node
		TreeNode *left; //Pointer to left child node
		TreeNode *right; //Pointer to right child node
		int digit;
	};

	TreeNode *root; //pointer to the root node

	//private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(string, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;

public:

	//Constructor
	BinaryTree()
	{
		root=0;
	}

	//Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	//Binary tree operations
	void insertNode(string);
	void remove(string);
	//this is an inline function that will call the display in order
	//function with the root.
	void displayInOrder()const
	{
		displayInOrder(root);
	}






};




#endif /* NODE_H_ */
