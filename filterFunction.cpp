//
// Created by Dennis Moyseyev on 10/18/2017.
//

#include <string>
#include <iostream>
#include "filterFunction.h"
using namespace std;

/*
 * This function will go through the whole string and remove the comments in the string.
 * and return a new string with the comments removed to the caller function.
 */
const string remove_comments(const string to_remove_comments_string)
{

    string string_without_comments;
    bool comment_started=false; //Keeps track if a comment is started.
    int size_of_string=to_remove_comments_string.length();
    int number_of_lines=1; //keeps tack on the file length.
    int currently_in_string=0;
    int where_comment_was_started=0;
    for(const char & c : to_remove_comments_string)
    {
        ++currently_in_string; //keeps track of the current place in the string.
        //Checks if a comment was started if yes it will enter the if statment.
        if(comment_started)
        {
            if(c=='#') //checks if the end of the comment was found.
            {
                comment_started=false;
            }
            if(c=='\n') //counts the amount of lines in the program string.
            {
                number_of_lines++;
            }
            //Checks if it reached the end of the string and a comment was opened but never closed it will throw an error.
            if(size_of_string==currently_in_string)
            {
                cout<<"ERROR: The file has an open comment statement but not closed comment statement at line : "<<where_comment_was_started<<endl;
                cout<<"The scanner will terminate. "<<endl;
                exit(1);
            }
            continue; //it will continue going in the string if a comment was started and hasn't end.
        }
        if(c=='#')
        {
            comment_started=true;
            /*
             * Grabs where the line number where the comment was started. This will be used just in case
             * it gets to the end of the page and the comment wasn't closed it will tell the user where the
             * last comment was started.
            */
             where_comment_was_started=number_of_lines;
        }
        if(c=='\n')
        {
            number_of_lines++;
        }
        if(!comment_started)
        {
            string_without_comments+=c;
        }
    }
    //returns the new with the comments removed.
    return  string_without_comments;
}

/*
 * Count function that will count the number of lines in the program string. This function
 * will be called after the program removes comments from the program.
 */

const int count_lines(const string to_get_number_of_new_lines) {

    int number_of_lines=1; //variable will be used to count the amount of lines.
    //Goes character by character through the whole string and counts the amount of times there is a new line.
    for(const char & c : to_get_number_of_new_lines)
    {
        if(c=='\n')
        {
            number_of_lines++;
        }
    }

    //returns the amount.
    return number_of_lines;
}
