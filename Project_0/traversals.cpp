/*
 * traversals.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Dennis Moyseyev
 */

#include "buildTree.h"

	//This will be a function used to display the binary tree.
	void BinaryTree::in_order(TreeNode *nodePtr, int level) const
	{
		if(nodePtr)
		{
			cout<<"The level is: "<<level<<endl;
			cout<<nodePtr->digit<<":";
			for (auto v : nodePtr->digit_list)
			       cout << " "<<v;
			cout<<"\n";

			in_order(nodePtr->left, level++);
			in_order(nodePtr->right, level++);
		}
	}
