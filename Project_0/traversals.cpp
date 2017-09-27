/*
 * traversals.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Dennis Moyseyev
 */

#include "buildTree.h"

	//This will be a function used to display the binary tree.
	void BinaryTree::traversePreorder(TreeNode *nodePtr) const
	{
		if(nodePtr)
		{
			for (int i = 0; i < nodePtr->level; ++i)
			{
			   cout << "\t" ;
			}
			cout<<nodePtr->digit<<":";
			for (auto v : nodePtr->digit_list)
			       cout << " "<<v;
			cout<<"\n";

			traversePreorder(nodePtr->left);
			traversePreorder(nodePtr->right);
		}


	}

	//This will be a function used to display the binary tree in postorder.
		void BinaryTree::traversePostorder(TreeNode *nodePtr) const
		{
			if(nodePtr)
			{
				traversePostorder(nodePtr->left);
				traversePostorder(nodePtr->right);

				for (int i = 0; i < nodePtr->level; ++i)
				{
				   cout << "\t" ;
				}
				cout<<nodePtr->digit<<":";
				for (auto v : nodePtr->digit_list)
				       cout << " "<<v;
				cout<<"\n";



			}
		}

//This will be a function used to display the binary tree in order.
	void BinaryTree::traverseInorder(TreeNode *nodePtr) const
	{
		if(nodePtr)
		{
			traverseInorder(nodePtr->left);

			for (int i = 0; i < nodePtr->level; ++i)
			{
				cout << "\t" ;
			}
			cout<<nodePtr->digit<<":";
			for (list<int>::iterator it=nodePtr->digit_list.begin(); it != nodePtr->digit_list.end(); ++it)
			    cout << ' ' << *it;
			cout<<"\n";

			traverseInorder(nodePtr->right);
		}
	}


