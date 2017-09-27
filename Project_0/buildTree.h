/*
 * buildTree.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Dennis Moyseyev
 */

#ifndef BUILDTREE_H_
#define BUILDTREE_H_

#include <vector>
#include <String>
#include <iostream>
#include <list>

using namespace std;

vector<string> divide_string_over_spaces(string);
vector<int> convert_string_vector_to_int_vector(vector<string> );
int lastDigit(int);

class  BinaryTree
{
private:

	struct TreeNode
	{
		list<int> digit_list; // the string of letter in the node
		TreeNode *left; //Pointer to left child node
		TreeNode *right; //Pointer to right child node
		int digit;
	};

	TreeNode *root; //pointer to the root node

		//private member functions
		void insert(TreeNode *&, TreeNode *&, int);
		void displayInOrder(TreeNode *) const;

public:

	//Constructor
	BinaryTree()
	{
		root=0;
	}

	//Destructor
	~BinaryTree(){}

	//Binary tree operations
	void insertNode(int , int);


	void remove(string);


	//this is an inline function that will call the display in order
	//function with the root.
	void displayInOrder()const
	{
		displayInOrder(root);
	}






};





#endif /* BUILDTREE_H_ */
