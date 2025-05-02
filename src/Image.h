#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include<iostream>
using namespace std;


//Here I do a forwad declaration of my Image
class MyImage;
/*Here I am then going to make a file that only deals with Opening the file
After Opening the file it reads what is there and then insert it into another
Image it is called File Handling*/

struct Pixel
{
    int int_red;
    int int_green;
    int int_blue;
};

enum Codes
{
    FAIL = -6,
    PPM_FILE_OPEN,
    MAGIC_NUM,
    ERROR_CONVERSION,
    INVALID_DATA,
    RGB_VALUE,
    SUCESS
};

//Here I am going to have my constant variables
static const int DEFAULT_ROWS = 3;
static const int DEFAULT_COLS = 3;
static constexpr Pixel DEFAULT_COLOUR = {123,123,123};

//Here I am going to have a function that is going to return my Image
MyImage LoadToPPM(string MyFile);

//Here this is  my function to convert characters entered in
//The command line to integers
int ConvToInt(char* chString);




#endif // IMAGE_H_INCLUDED
