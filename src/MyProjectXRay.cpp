#include "MyProjectXRay.h"
#include <iostream>
#include <sstream>
using namespace std;

//Here I am going to have my constructors
//Also illustrating constructor chaining
MyImage::MyImage():MyImage(DEFAULT_ROWS,DEFAULT_COLS)
{
    AllocMem(DEFAULT_ROWS,DEFAULT_COLS);
}
MyImage::~MyImage()
{
    DeAllocMem();
}
MyImage::MyImage(int intRows , int intCols)
{
    _intRows = intRows;
    _intCols = intCols;
    AllocMem(_intRows,_intCols);
}
MyImage::MyImage(const MyImage& Obj):MyImage(Obj._intRows,Obj._intCols)
{
    Clone(Obj);

}

//Here I am going to allocate amemory for my array
void MyImage::AllocMem(int intRows , int intCols)
{
    //Here When I allocate the memory I must use my original rows and Column
    _intRows = intRows;
    _intCols = intCols;
    _PixelArray =  new Pixel*[_intRows];
    for(int r = 0; r < intRows ; r++)
    {
        _PixelArray[r] = new Pixel[_intCols];
        for(int c = 0; c < intCols ; c++)
        {
            _PixelArray[r][c].int_red = 0;
            _PixelArray[r][c].int_green = 0;
            _PixelArray[r][c].int_blue = 0;
        }
    }

}

//Here I am going to return my rows
int MyImage::GetRows() const
{
    return _intRows;
}
int MyImage::GetCols() const
{
    return _intCols;
}

//Here I am going to have my setters
void MyImage::SetRows(int intRows)
{
    _intRows = intRows;
}

Pixel MyImage::getPixelColour(int intRow , int intCol) const
{
    return _PixelArray[intRow][intCol];
}
void MyImage::SetPixelColour(int intRow , int intCol,int intred , int intgreen , int intblue)
{
    _PixelArray[intRow][intCol].int_red = intred;
    _PixelArray[intRow][intCol].int_green = intgreen;
    _PixelArray[intRow][intCol].int_blue = intblue;
}

//Here this is a function to set the whole I mage colour
void MyImage::SetImageColour(Pixel Colour)
{
    for(int r = 0; r < _intRows ; r++)
    {
        for(int c = 0; c < _intCols ; c++)
        {
            _PixelArray[r][c] = Colour;
        }
    }
}

//Here I am going to have my function that is going to deallocate my memory
void MyImage::DeAllocMem()
{
    for(int r = 0; r < _intRows ; r++)
    {
        delete[] _PixelArray[r];
    }
    delete[]  _PixelArray;
    _PixelArray = nullptr;
}
//Here I am going to make a cloning function for my other objects
void MyImage::Clone(const MyImage&Obj)
{
    for(int r = 0; r < _intRows ; r++)
    {
        for(int c = 0 ; c < _intCols ; c++)
        {
            _PixelArray[r][c].int_red = Obj._PixelArray[r][c].int_red;
            _PixelArray[r][c].int_green = Obj._PixelArray[r][c].int_green;
            _PixelArray[r][c].int_blue = Obj._PixelArray[r][c].int_blue;
        }
    }

}


//This is a function that will insert my Pixel Values(Colour)into my Image
string MyImage::toPPM() const
{
    stringstream ssPPM;
    ssPPM << "P3" << endl
          <<_intCols << " " << _intRows << endl
           << "255" << endl;
         for (int r = 0 ; r < _intRows ; r++)
         {
             for(int c  = 0; c < _intCols ; c++)
             {
                 ssPPM << _PixelArray[r][c].int_red << " "
                       << _PixelArray[r][c].int_green << " "
                       << _PixelArray[r][c].int_blue << " ";
             }
             ssPPM << endl;
         }
         return ssPPM.str();
}

