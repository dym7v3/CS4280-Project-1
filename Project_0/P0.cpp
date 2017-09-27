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
#include <stdlib.h>
#include <istream>
#include <iterator>
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



	BinaryTree my_tree;

	string file_string;
	vector<string> input_numbers;
	vector<int> intNumbers;


	if(argc==1)
	{

		getline(cin, file_string);
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



	//Separates the string numbers over white-spaces. returns a string vector.
	input_numbers=divide_string_over_spaces(file_string);

	//converts the string vector into a integer vector. Returns a int vector.
	intNumbers=convert_string_vector_to_int_vector(input_numbers);


	    for(int i=0; i<input_numbers.size(); i++)
	    {
	    	int num=lastDigit(intNumbers[i]);
	    	my_tree.insertNode(num, intNumbers[i]);
	    }


	   my_tree.displayInOrder();

	   return 0;
}



