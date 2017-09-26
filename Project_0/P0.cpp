/*
 * P0.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Dennis Moyseyev
 */

#include <fstream>
#include <iostream>
#include "Node.h"

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

	cout<< argv[0];

	if(argc==1)
	{
		fp=stdin;
	}

	else
	{
		ifstream the_file ( argv[1] );

		//Checks if the file was actually opened.
		if ( !the_file.is_open() )
			cout<<"Could not open file\n"; //Prints out an error message

	    else
	    {
	    	  char x;
	      	  while ( the_file.get ( x ) )
	    	  cout<< x;
	    }
	}


	list<int>::iterator num_value;

	Node *t=new Node();

	t->values.push_front(4);
	t->values.push_front(4);
	t->values.push_front(6);
	t->values.push_front(7);

	   for(num_value = t->values.begin(); num_value != t->values.end(); ++num_value)
	        cout << '\t' << *num_value;
	    cout << '\n';




  }



