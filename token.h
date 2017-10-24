//
// Created by Dennis Moyseyev on 10/18/2017.
//

#ifndef P1_TOKEN_H
#define P1_TOKEN_H
#include<string>


using namespace std;

enum TOKEN_ID
{
    End_Of_File,
    Keyword_Begin,
    Keyword_End,
    Keyword_Check,
    Keyword_Loop,
    Keyword_Void,
    Keyword_Var,
    Keyword_Return,
    Keyword_Input,
    Keyword_Output,
    Keyword_Program,
    Integer,
    Identifiers,
    Operator_Equal,
    Operator_Less_Than,
    Operator_Less_Than_Or_Equal_To,
    Operator_Greater_Than,
    Operator_Greater_Than_Or_Equal_To,
    Operator_Not_Equal_To,
    Operator_Equal_To,
    Operator_Plus,
    Operator_Minus,
    Operator_Divide,
    Operator_Multiply,
    Operator_Modulo,
    Operator_Ampersand,
    Delimiter_Colon,
    Delimiter_Period,
    Delimiter_Left_Parenthesis,
    Delimiter_Right_Parenthesis,
    Delimiter_Left_Curly_Brace,
    Delimiter_Right_Curly_Brace,
    Delimiter_Left_Bracket,
    Delimiter_Right_Bracket,
    Delimiter_Comma,
    Delimiter_Semi_Colon
};


class Token
{
//Private methods. This will be the line number, token id and the actual value of the string.
private:
    TOKEN_ID  token_id;
    int line_number;
    string the_string;
public:

    //Constructor for the class.
    Token(TOKEN_ID , string, int);

    //Used to get the line number.
    int Get_Line_Number();

    //Used to get the string value of the Token.
    string Get_The_String();

    //Used to get the Token Id.
    TOKEN_ID Get_Token_ID();
};



#endif //P1_TOKEN_H
