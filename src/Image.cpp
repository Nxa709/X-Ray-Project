#include "Image.h"
#include "MyProjectXRay.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


//Here I am theb
MyImage LoadToPPM(string MyFile)
{
    //Here I am going to Open my file
    ifstream iPPM(MyFile.c_str());
    if(iPPM.fail())
    {
        cerr << "Cannot Open The PPM File" << endl;
        exit(PPM_FILE_OPEN);
    }
    //Here I am going to have an appropriate error handing system

    //"P3" string
    string Number = " ";
    iPPM >> Number;
    if(Number != "P3")
    {
        cerr << "I mage format is not correct " << endl;
        exit(MAGIC_NUM);
    }
    //Appropriate error handling system here

    //Here I am also going to take in my rows, cols ,and maxRGB values
    int intCol = 0 , intRows = 0 , RGBMax = 0;
    iPPM >> intCol >> intRows >> RGBMax;
    //Appropriate error handling system
    if(RGBMax > 255)
    {
        cerr << "The maximum RGB value must be 255" << endl;
        exit(RGB_VALUE);
    }

    //Here I am going to create an Image object
    MyImage Obj(intRows , intCol);

    //Then I am going to create an array of Pixel values
    Pixel _ArrayPixel;
    for(int r = 0; r < intRows ; r++)
    {
        for(int c = 0 ; c < intCol ; c++)
        {
            iPPM >> _ArrayPixel.int_red >> _ArrayPixel.int_green >> _ArrayPixel.int_blue;
            //Here an Appropriate error handling
            if(iPPM.fail())
               {
                    cerr << "Invalid Data" << endl;
                    exit(INVALID_DATA);
               }
             Obj.SetPixelColour(r,c,_ArrayPixel.int_red,_ArrayPixel.int_green,_ArrayPixel.int_blue);
        }

    }
    //Here I need to close my file
    iPPM.close();
    //I then need to return it
    return Obj;

}

//Here This is my function to Perform conversion
int ConvToInt(char* CharStr)
{
    stringstream ss {CharStr};
    int Number = 0;
    ss >> Number;
    if(ss.fail())
    {
        cerr << "Cannot convert a number to Integer" << endl;
        exit(ERROR_CONVERSION);
    }
    return Number;
}
