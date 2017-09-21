/*
 * P0.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Dennis Moyseyev
 */

#include <fstream>
#include <iostream>

using namespace std;

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


  }

