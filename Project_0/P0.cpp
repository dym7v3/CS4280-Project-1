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
#include <stdio.h>
#include <cstring>
using namespace std;


int main ( int argc, char *argv[] )
{



	BinaryTree my_tree;
	string file_string;
	vector<string> input_numbers;
	vector<int> intNumbers;
	FILE* fp;
	char buffer [100];
	if(argc==1)
	{

		getline(cin, file_string);
	}

	else
	{

		file_string=argv[1];
		fp=fopen(file_string.c_str(), "r");

		//This will open the file and read in the file with ifstream.
		ifstream the_file(argv[1]);

		//Checks if the file was actually opened.
		if ( !the_file.is_open() )
			cout<<"Could not open file\n"; //Prints out an error message


		if ( the_file.peek() == std::ifstream::traits_type::eof() )
		{
		   cout<<"The File is empty. The Program will end.";
		   exit(1);

		}



	   while ( ! feof (fp) )
	   {
		   if ( fgets (buffer , 100 , fp) == NULL ) break;
	    		fputs (buffer , stdout);
	   }


		fclose (fp);


	}


	/*
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
		*/
	   return 0;
}



