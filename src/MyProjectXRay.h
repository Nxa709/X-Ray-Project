#ifndef MYPROJECTXRAY_H_INCLUDED
#define MYPROJECTXRAY_H_INCLUDED

#include <iostream>
#include "Image.h"
using namespace std;


typedef Pixel*OneDArray;
typedef OneDArray*TwoDArray;

class MyImage
{
public:
    //Here I am going to have my constructors
    MyImage();
    MyImage(int intRows , int intCols);
    MyImage(const MyImage& Obj);
    ~MyImage();
    //Then I  need my getters here and also my setters
    int GetRows() const;
    int GetCols() const;
    void SetRows(int intRows);
    void SetCols(int intCols);
    Pixel getPixelColour(int intRows , int intCols)const;
    void SetPixelColour(int intRows , int intCols ,int , int,int);
    string toPPM() const;
protected:
    //Here I am going to have my function that I will need
    void Clone(const MyImage& Obj);
    void DeAllocMem();
    void AllocMem(int intRows, int intCols);
    //Here I am going to have also a function that set the colour of the whole I mage
    void SetImageColour(Pixel colour);


    //Here this are going to be my array attributes
    TwoDArray _PixelArray;
    int _intRows;
    int _intCols;
};


#endif // MYPROJECTXRAY_H_INCLUDED
