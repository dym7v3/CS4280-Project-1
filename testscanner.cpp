//
// Created by Dennis Moyseyev on 10/24/2017.
//
#include <iostream>
#include "./token.h"
#include "./scanner.h"

using namespace std;

int Character_Counter=0;

const void Test_Scanner(string File_String)
{
    //Gets the first character in the file string and will be used to send it to the driver.
    char first_character=Get_Char(File_String,Character_Counter);
    bool not_reached_end_of_file= true;

    int count=0;
    do
    {
        Token *the_token= nullptr;
        the_token = Driver(first_character);
        count++;
        cout << (*the_token).Get_Line_Number() << endl;

        //This checks if the last token that was returned was the end of the file.
        if((*the_token).Get_Token_ID()== End_Of_File)
        {
            not_reached_end_of_file=false;
        }

    }while(not_reached_end_of_file);
}
