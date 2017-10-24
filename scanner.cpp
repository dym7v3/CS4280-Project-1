//
// Created by Dennis Moyseyev on 10/18/2017.
//
#include <string>
#include <iostream>
#include <map>
#include "./token.h"
#include "./testscanner.h"

using namespace std;

enum STATE
{
    INITIAL, //S0 first state
    FINAL_STATE,
    ERROR,




};

const int END_OF_FILE_COLUMN=0;
const int DIGIT_COLUMN=1;
const int LETTER_COLUMN=2;
const int WHITESPACE_COLUMN=3;
const int EQAULS_COLUMN=4;
const int LESSTHAN_COLUMN=5;
const int GREATERTHAN_COLUMN=6;
const int NOT_COLUMN=7;
const int COLON_COLUMN=8;
const int PLUS_COLUMN=9;
const int MINUS_COLUMN=10;
const int MUlTIPLY_COLUMN=11;
const int DIVIDE_COLUMN=12;
const int AMPERSAND_COLUMN=13;
const int PERCENT_COLUMN=14;
const int PERIOD_COLUMN=15;
const int LEFTBRACKET_COLUMN=16;
const int RIGHTBRACKET_COLUMN=17;
const int LEFTBRACE_COLUMN=18;
const int RIGHTBRACE_COLUMN=19;
const int COMMA_COLUMN=20;
const int LEFTPARENTHESIS_COLUMN=21;
const int RIGHTPARENTHESIS_COLUMN=22;
const int SEMICOLON_COLUMN=23;



int table[27][24] = {
        { 2000 , 2 , 1 , 0 , 3 , 5 , 7 , 9 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 } ,
        { 2001 , 1 , 1 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 , 2001 } ,
        { 2002 , 2 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 , 2002 } ,
        { 2003 , 2003 , 2003 , 2003 , 4 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 , 2003 } ,
        { 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004 , 2004, 2004 , 2004 , 2004 , 2004 , 2004 } ,
        { 2005 , 2005 , 2005 , 2005 , 6 , 2005 , 2005, 2005, 2005 , 2005 , 2005, 2005 , 2005 , 2005 , 2005, 2005 , 2005 , 2005 , 2005 , 2005 , 2005 , 2005 , 2005 , 2005 , } ,
        { 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 , 2006 } ,
        { 2007 , 2007 , 2007 , 2007 , 8 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 , 2007 } ,
        { 2008 , 2008 , 2008 , 2008, 2008 , 2008 , 2008 , 2008, 2008 , 2008 , 2008 , 2008, 2008 , 2008 , 2008 , 2008, 2008 , 2008 , 2008 , 2008, 2008 , 2008 , 2008 , 2008  } ,
        { -1 , -1 , -1 , -1 , 10 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 },
        { 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 , 2009 } ,
        { 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 , 2010 } ,
        { 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 , 2011 } ,
        { 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 , 2012 } ,
        { 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 , 2013 } ,
        { 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 , 2014 } ,
        { 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 , 2015 } ,
        { 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 , 2016 } ,
        { 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 , 2017 } ,
        { 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 , 2018 } ,
        { 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 , 2019 } ,
        { 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 , 2020 } ,
        { 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 , 2021 } ,
        { 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 , 2022 } ,
        { 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 , 2023 } ,
        { 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 , 2024 } ,
        { 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 , 2025 } ,






};

//Returns a character from the string at the number in the string.
const char Get_Char(string &file_string, int char_number_in_string)
{
    if(file_string.length()<char_number_in_string || char_number_in_string<0)
    {
        cout<<"ERROR: Can't return a character that is outside the string. Program will terminate."<<endl;
        exit(1);
    }
    return file_string[char_number_in_string];
}

//This gets called by the test scanner program.
Token * Driver (char first_char)
{
    STATE state=INITIAL;
    TOKEN_ID this_token=End_Of_File;
    string value_string;
    Token *my_token= new Token(this_token, "hello", 5);

    while(state!=FINAL_STATE)
    {






    }





    return my_token;
}