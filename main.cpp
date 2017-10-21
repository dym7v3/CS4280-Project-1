//
// Created by Dennis Moyseyev on 10/17/2017.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include "./filterFunction.h"

using namespace std;

const static int BUFFER_SIZE = 100;
const string File_Input(const string &);

int main ( int argc, char *argv[] )
{

    string file_name_string; //will be used to take in all the file content and save it to a string.
    string string_from_file;
    FILE* fp;
    char buffer [BUFFER_SIZE];

    if(argc==1)
    {

        fp=stdin;
        /*keeps reading in the file until the end of the file is reached. Enter is required to be pressed for
        for it to take in all the input from the keyboard.
        */
        fseek(fp, 0, SEEK_END);
        auto len = (unsigned long)ftell(fp);
        if (len ==0)
        {
            cout<<"This is file is empty. The program will exit now. "<<endl;
            exit(1);
        }
        rewind(fp);

        while(! feof (fp))
        {
            //if it is equal to null then it will break the loop that is taking in the numbers from the file.
            if ( fgets (buffer , BUFFER_SIZE , fp) == nullptr )
                break;

            string_from_file+=buffer; //appends the buffer to a string which will be divided over whitespaces.
        }

        fclose (fp); //closes the stdin.
    }

    else if(argc>=3)
    {
        cout << "To many arguments. it will exit now. ";
        exit(1);
    }
    else
    {
        //Takes the input file and converts it into a string which will be scanned through
        //and the tokens will be taken out of it.
        file_name_string=argv[1];
        string_from_file=File_Input(file_name_string);

    }


    string_from_file=remove_comments(string_from_file);


    return 0;
}
const string File_Input(const string &file_name_without_ext) {

        string file_name=file_name_without_ext + ".fs17";
        ifstream inFile;
        inFile.open(file_name);//open the input file

        //Checks if the stream_variable is able to be open if not it will
        //throw an error.
        if (inFile)
        {
            stringstream strStream;
            strStream << inFile.rdbuf();//read the file
            string str = strStream.str();//str holds the content of the file
            return str;

        }
        //Only ends up here if the file was not able to be open.
        else
        {
            cout<<"No File was found with the input name.\nThe program will be terminated.\n";
            exit(1);
        }
}
