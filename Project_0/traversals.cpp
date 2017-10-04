/*
 * traversals.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Dennis Moyseyev
 */

#include "buildTree.h"
#include "traversals.h"
#include "node.h"
#include <fstream>
#include <iostream>
using namespace std;

	//Displays the results in preorder.
	void BinaryTree::traversePreorder(TreeNode *nodePtr, ostream& output) const
	{
		if(nodePtr)
		{
			for (int i = 0; i < nodePtr->level; ++i)
			{
			   cout << "\t" ;
			   output<<"\t";

			}
			cout<<nodePtr->digit<<":";
			output<<nodePtr->digit<<":";
			for (auto v : nodePtr->digit_list)
			{
				cout << " "<<v;
				output<<" "<<v;
			}
			cout<<"\n";
			output<<"\n";

			traversePreorder(nodePtr->left, output);
			traversePreorder(nodePtr->right, output);
		}


	}

	//This will be a function used to display the binary tree in postorder.
		void BinaryTree::traversePostorder(TreeNode *nodePtr,ostream& output) const
		{
			if(nodePtr)
			{
				traversePostorder(nodePtr->left,output);
				traversePostorder(nodePtr->right,output);

				for (int i = 0; i < nodePtr->level; ++i)
				{
				   cout << "\t" ;
				   output<< "\t" ;
				}
				cout<<nodePtr->digit<<":";
				output<<nodePtr->digit<<":";
				for (auto v : nodePtr->digit_list)
				{
				       cout << " "<<v;
				       output<< " "<<v;
				}
				cout<<"\n";
				output<<"\n";



			}
		}

//This will be a function used to display the binary tree inorder.
	void BinaryTree::traverseInorder(TreeNode *nodePtr,ostream& output) const
	{
		if(nodePtr)
		{
			traverseInorder(nodePtr->left,output);

			for (int i = 0; i < nodePtr->level; ++i)
			{
				cout << "\t" ;
				output<<"\t";
			}
			cout<<nodePtr->digit<<":";
			output<<nodePtr->digit<<":";
			for (list<int>::iterator it=nodePtr->digit_list.begin(); it != nodePtr->digit_list.end(); ++it)
			{
			    cout << ' ' << *it;
			    output<< ' ' << *it;
			}

			cout<<"\n";
			output<<"\n";

			traverseInorder(nodePtr->right,output);
		}
	}



