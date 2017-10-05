

#include "buildTree.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;


//Returns the last digit of the number. I doesn't matter if it is negative or postive.
int last_digit(int number) { return abs(number % 10); }


//This divides the string over spaces and saves it into a string vector.
vector<int> divide_string_over_spaces(string my_string)
{

	istringstream ss(my_string);
	int token;

	vector<int> my_vector;
	while( ss >> token)
	{

		my_vector.push_back(token);
	}

	return my_vector;
}



	//This function is from the book at allows you to insert strings into the tree.
	void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode, int value, int level)
	{

		//Insert the node
		if(nodePtr==0)
		{
			nodePtr=newNode;
			nodePtr->digit_list.push_front(value);
			nodePtr->level=level;

		}
		else if(newNode->digit==nodePtr->digit)
			nodePtr->digit_list.push_front(value);
		else if(newNode->digit<nodePtr->digit)
			insert(nodePtr->left,newNode, value, level+1); //search the left branch
		else
			insert(nodePtr->right,newNode, value, level+1);//search the right branch
	}


	//This function will be used to insert the node into the tree.
	void BinaryTree:: insert_node(int key, int vector_value)
	{
		TreeNode *newNode=0; //pointer to a new node.

		//Create a new node and store a string in it.
		newNode=new TreeNode;
		newNode->digit=key;
		newNode->left=newNode->right=0;


		insert(root, newNode, vector_value, 0);
	}







