/*
 * P0.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Dennis Moyseyev
 */

#include <fstream>
#include <iostream>
#include <String>
#include <vector>
#include "node.h"
#include "buildTree.h"

using namespace std;

/*
Functions used with List :
front() – Returns reference to the first element in the list
back() – Returns reference to the last element in the list
push_front(g) – Adds a new element ‘g’ at the beginning of the list
push_back(g) – Adds a new element ‘g’ at the end of the list
pop_front() – Removes the first element of the list, and reduces size of the list by 1
pop_back() – Removes the last element of the list, and reduces size of the list by 1
begin() – Returns an iterator pointing to the first element of the list
end() – Returns an iterator pointing to the theoretical last element which follows the last element
empty() – Returns whether the list is empty(1) or not(0)
insert() – Inserts new elements in the list before the element at a specified position
erase() – Removes a single element or a range of elements from the list
assign() – Assigns new elements to list by replacing current elements and resizes the list
remove() – Removes all the elements from the list, which are equal to given element
reverse() – Reverses the list
size() – Returns the number of elements in the list
sort() – Sorts the list in increasing order

*/





int main ( int argc, char *argv[] )
{

	FILE *fp; //Creates a file pointer.


	BinaryTree my_tree;

	string file_string;
	vector<string> input_numbers;


	if(argc==1)
	{
		fp=stdin;
	}

	else
	{
		//This will open the file and read in the file with ifstream.
		ifstream the_file ( argv[1] );

		//Checks if the file was actually opened.
		if ( !the_file.is_open() )
			cout<<"Could not open file\n"; //Prints out an error message

		//Other wise it will import the file as a string.
	    else
	    {
	    	  char x; //It will take character by character and append to the string.
	      	  while (the_file.get ( x ))
	      	  {
	      		file_string+=x;
	      	  }

	    }
	}



	input_numbers=divide_string_over_spaces(file_string);

	string last_digit=get_last_digit(4, input_numbers);
	cout<<last_digit<<endl;





	/*
	list<int>::iterator num_value;

	Node *t=new Node();

	t->values.push_front(4);vector<string> divide_string_over_spaces(string my_string)
	t->values.push_front(4);
	t->values.push_front(6);
	t->values.push_front(7);

	   for(num_value = t->values.begin(); num_value != t->values.end(); ++num_value)
	        cout << '\t' << *num_value;
	    cout << '\n';

	*/






}


