//
// Created by Dennis Moyseyev on 10/24/2017.
//
#include <iostream>
#include "./token.h"
#include "./scanner.h"

using namespace std;

const void Test_Scanner(const string &File_String)
{
    bool not_reached_end_of_file= true;


    do
    {
        Token *the_token= nullptr;
        the_token = Driver(File_String);

        //This checks if the last token that was returned was the end of the file.
        if((*the_token).Get_Token_ID()== End_Of_File)
        {
            not_reached_end_of_file=false;
        }

    }while(not_reached_end_of_file);
}
