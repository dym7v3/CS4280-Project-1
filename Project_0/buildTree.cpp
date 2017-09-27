

#include "buildTree.h"
#include <iostream>
#include <vector>
#include <String>
#include <sstream>
#include <cstdlib>
using namespace std;


//Returns the last digit of the number. I doesn't matter if it is negative or postive.
int lastDigit(int number) { return abs(number % 10); }

//Converts the string vector to a integer vector. Returns a integer vector.
vector<int> convert_string_vector_to_int_vector(vector<string> input_numbers)
{
			vector<int> intNumbers;
		    for (int i=0; i< input_numbers.size(); i++)
		    {


		    int num = atoi(input_numbers.at(i).c_str());
		    if(num==0)
		    {
		    	cout<<"Your file has characters in it. The program will end."<<endl;
		    	exit(0);
		    }

		    intNumbers.push_back(num);
		    }
		    return intNumbers;
}

//This divides the string over spaces and saves it into a string vector.
vector<string> divide_string_over_spaces(string my_string)
	{
		istringstream ss(my_string);
		string token;

		vector<string> my_vector;
		while(getline(ss, token, ' '))
		{
			my_vector.push_back(token);
		}

		return my_vector; //returns a vector
	}



	//This function is from the book at allows you to insert strings into the tree.
	void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode, int value)
	{

		//Insert the node
		if(nodePtr==0)
		{
			nodePtr=newNode;
			nodePtr->digit_list.push_back(value);
		}
		else if(newNode->digit==nodePtr->digit)
			nodePtr->digit_list.push_back(value);
		else if(newNode->digit<nodePtr->digit)
			insert(nodePtr->left,newNode, value); //search the left branch
		else
			insert(nodePtr->right,newNode, value);//search the right branch
	}


	//This function will be used to insert the node into the tree.
	void BinaryTree:: insertNode(int key, int vector_value)
	{
		TreeNode *newNode=0; //pointer to a new node.

		//Create a new node and store a string in it.
		newNode=new TreeNode;
		newNode->digit=key;
		newNode->left=newNode->right=0;


		insert(root, newNode, vector_value);
	}




	//This will be a function used to display the binary tree.
	void BinaryTree::displayInOrder(TreeNode *nodePtr) const
	{
		if(nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout<<nodePtr->digit<<":";
			for (auto v : nodePtr->digit_list)
			       cout << " "<<v;
			cout<<"\n";
			displayInOrder(nodePtr->right);
		}
	}


