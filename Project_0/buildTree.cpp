

#include "buildTree.h"
#include <iostream>
#include <vector>
#include <String>
#include <sstream>
#include <cstdlib>
using namespace std;



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


//Gets the last digit of number.
string get_last_digit(int index, vector<string> my_vector)
{
	string num=my_vector[index];
	return (num.substr(num.length() - 1));
}






