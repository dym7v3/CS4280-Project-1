/*
 * P0.cpp
 *
 *  Created on: Sep 20, 2017
 *  Author: Dennis Moyseyev
 *  Class: CS4280
 *
 *
 * Program Details: This program will take a file or input from the keyword
 * and it will build a binary tree and display the traversals in the console and save it in files.
 * Note: This program will not take character from the input file. It will only take 32-bit integers.
 *
 */

//Check the libraries before turning in.


#include <iostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "node.h"
#include "buildTree.h"

using namespace std;


int main ( int argc, char *argv[] )
{


	//This makes the Binary tree
	BinaryTree binary_search_tree;
	string file_name; //will be used to take in all the file content and save it to a string.
	string output_name; //this will be used to name the file.
	vector<int> int_numbers; //will hold all the number in the file.
	string my_string;
	bool file_arg_given=false; //if file not given the output will be out. the order.
	FILE* fp;

	const int BUFFERSIZE = 100;
	char buffer [BUFFERSIZE];

	if(argc==1)
	{
		fp=stdin;
		/*keeps reading in the file until the end of the file is reached. Enter is required to be pressed for
		for it to take in all the input from the keyboard.
		*/

		fseek(fp, 0, SEEK_END);
		unsigned long len = (unsigned long)ftell(fp);
		if (len ==0)
		{
			cout<<"This is file is empty. The program will exit now. "<<endl;
			exit(1);
		}
		rewind(fp);

		while(! feof (fp))
		{
			//if it is equal to null then it will break the loop that is taking in the numbers from the file.
			if ( fgets (buffer , BUFFERSIZE , fp) == NULL )
			 break;

			my_string+=buffer; //appends the buffer to a string which will be divided over whitespaces.
		}

		fclose (fp); //closes the stdin.
	}

	else if(argc>=3)
	{
		cout<<"To many arguments. it will exit now. ";
		exit(1);
	}

	else
	{

		//Takes the argument and makes it a string.
		file_name=argv[1];
		output_name=argv[1]; //will be used to name the output files.

		//Checks if the file ends with .txt if thats true it will try to open the file.
		 if(file_name.substr(file_name.find_last_of(".") + 1) == "txt")
		 {
			 fp=fopen(file_name.c_str(), "r");
			 output_name=output_name.substr(0, output_name.find(".")); //returns the file name before the dot.
		 }

		 else
		  {
			 //If it doesn't have the .txt extension then it will add the .fs17.txt
			 file_name+=".fs17";
			 fp=fopen(file_name.c_str(), "r");
		  }


		//Checks if the file was actually opened.
		if (fp==NULL )
		{
			cout<<"Could not open file.\n The program will end."; //Prints out an error message
			exit(1); //Exit program with the appropriate  message.
		}


		//Checks if the file is empty. If true it will display error and exit.
		fseek(fp, 0, SEEK_END);
		unsigned long len = (unsigned long)ftell(fp);
		if (len ==0)
		{
			cout<<"This is file is empty. The program will exit now. "<<endl;
			exit(1);
		}


		//Rewinds the file pointer back to the start of the file to start reading input.
		rewind(fp);

		//If the file is not empty and can be opened then it will read from the file.
	   while ( ! feof (fp) )
	   {
		   //if it is equal to null then it will break the loop that is taking in the numbers from the file.
		   if ( fgets (buffer , BUFFERSIZE , fp) == NULL )
			   break;

		   my_string+=buffer;
	   }

	  		fclose (fp); //closes the file
	  		file_arg_given=true;

	}

		//Separates the string numbers over white-spaces. returns a string vector.
		int_numbers=divide_string_over_spaces(my_string);

		//Calls the pushes the number into the binary tree one by one.
		for(int i=0; i<int_numbers.size(); i++)
		{

		   	int last_num=last_digit(int_numbers[i]);
		   	binary_search_tree.insert_node(last_num, int_numbers[i]);
		}

		//This will check if the file name is given if true then it will name the file and then the order info.
		//If not then it will make the output name out and append the order info.
		if(file_arg_given)
		{
			binary_search_tree.display_results(output_name);
		}
		else
		{
			output_name="out";
			binary_search_tree.display_results(output_name);
		}




	   return 0;
}



