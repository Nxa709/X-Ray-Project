#include "Filter.h"
#include <iostream>
using namespace std;


//Here I first define my constructors
//Then I do not need to define my apply filter function since it is virtual
//I also demonstate my constructor chaining here
Filter::Filter():Filter(DEFAULT_ROWS,DEFAULT_COLS)
{
    InitKernel();
}

Filter::Filter(int intRows , int intCols)
{
    _intRows = intRows;
    _intCols = intCols;
    InitKernel();
}
Filter::~Filter()
{
    DeAllocMem();
}

Filter::Filter(const Filter&Obj)
{
    Clone(Obj);
}

void Filter::InitKernel()
{
    //Initalizing my Kernel here
    Kernel = new int*[_intRows];
    for(int r = 0 ; r < _intRows; r++)
    {
        Kernel[r] = new int[_intCols];
        for(int c = 0 ; c < _intCols; c++)
        {
            Kernel[r][c] = 0;
        }
    }
}

void Filter::DeAllocMem()
{
    //Here I am deallocating my memory
    for(int r = 0 ; r < _intRows ; r++)
    {
        delete[] Kernel[r];
    }
    delete[] Kernel;
    Kernel = nullptr;
}

void Filter::Clone(const Filter&Obj)
{
    //here I am cloning my function
    for(int r = 0 ; r < _intRows ; r++)
    {
        for(int c = 0; c < _intCols; c++)
        {
            Kernel[r][c] = Obj.Kernel[r][c];
        }
    }
}
