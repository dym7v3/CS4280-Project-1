/*
 * node.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Dennis Moyseyev
 */


#ifndef NODE_H_
#define NODE_H_


#include <list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class  BinaryTree
{
private:

	struct TreeNode
		{
			list<int> digit_list; // the string of letter in the node
			TreeNode *left; //Pointer to left child node
			TreeNode *right; //Pointer to right child node
			int digit;
			int level;
		};

	TreeNode *root; //pointer to the root node

	//private member functions
	void insert(TreeNode *&, TreeNode *&, int,int);
	void traversePreorder(TreeNode *, ostream& ) const;
	void traversePostorder(TreeNode *, ostream&) const;
	void traverseInorder(TreeNode *, ostream&) const;


public:

	//Constructor
	BinaryTree()
	{
		root=0;

	}


	//Binary tree operations
	void insert_node(int , int);


	//this is an inline function that will call the display in order
	//function with the root.
	void display_results(string name_of_file)const
		{


			string preorder_name=name_of_file+".preorder.txt";
			string postorder_name=name_of_file+".postorder.txt";
			string inorder_name=name_of_file+".inorder.txt";

			ofstream preorder(preorder_name.c_str());
			cout<<"Preorder: "<< "\n\n";
			traversePreorder(root,preorder);

			cout<<"PostOrder: "<< "\n\n";
			ofstream postorder(postorder_name.c_str());
			traversePostorder(root,postorder);

			cout<<"Inorder: "<< "\n\n";
			ofstream inorder(inorder_name.c_str());
			traverseInorder(root,inorder);
		}



};


#endif /* NODE_H_ */
