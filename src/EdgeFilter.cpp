#include "EdgeFilter.h"
#include "Filter.h"
#include "MyProjectXRay.h"
#include <iostream>
using namespace std;

//So my Kernel Array should be dynamically allocated
EdgeFilter::EdgeFilter():Filter()
{
    InitKernel();
}

EdgeFilter::EdgeFilter(int intRows, int intCols):Filter(DEFAULT_ROWS,DEFAULT_COLS)
{
    _intRows = intRows;
    _intCols = intCols;
    InitKernel();
}
//Here I promised to have a definition of the ApplyTheFilter
void EdgeFilter::ApplyTheFilter(MyImage&Obj , int intNumTimes)
{
    //Here this is very important
    int num_row = Obj.GetRows();
    int num_col = Obj.GetCols();
    int Convole_red ;
    int Convole_green ;
    int Convole_blue ;
    int Counter = 0;
    //int sum_kernel ;
    //Here I am going to create a clone of my Image
    MyImage Obj_Clone(Obj);

    //My mistake here was that my function didn't know
    //What is the value of my _intRows since they are private
    //So Always use the getters!!!
    //And also setters!!

    /*Here now I am going to crate a very important thing a pseudo Image
    *So I am going to create my Image as a greey scale
    *Looking at each and every pixel in my Image
    */

    double intensity = 0.0;
    while(Counter != intNumTimes)
    {
    for(int r = 1; r<num_row-1 ; r++)
    {

        for(int c = 1; c<num_col-1 ; c++)
        {
            intensity = 0.299 *Obj.getPixelColour(r,c).int_red + 0.587*Obj.getPixelColour(r,c).int_green + 0.114*Obj.getPixelColour(r,c).int_blue;
            if(intensity < 64)
            {
                //Make shades of Blue
                Convole_red = 0;
                Convole_green = 0;
                Convole_blue = 255 *(intensity/64);
            }

    else if (intensity < 128) {  // Map to shades of cyan
        Convole_red = 0;
        Convole_green = 255 * (intensity - 64) / 64;
        Convole_blue = 255;
    }
    else if (intensity < 192) {  // Map to shades of yellow
        Convole_red = 255 * (intensity - 128) / 64;
        Convole_green = 255;
        Convole_blue = 255 * (intensity - 128) / 64;
    }
    else {  // Map to shades of red
        Convole_red = 255;
        Convole_green=255 * (intensity - 192) / 64;
        Convole_blue = 0;
    }
            Obj.SetPixelColour(r,c,Convole_red,Convole_green,Convole_blue);
        }
    }
    Counter++;

}
}

void EdgeFilter::InitEdgeKernel()
{
    Kernel[0][0] = 0;
    Kernel[0][1] = -1;
    Kernel[0][2] = 0;
    Kernel[1][0] = -1;
    Kernel[1][1] = 5;
    Kernel[1][2] = -1;
    Kernel[2][0] = 0 ;
    Kernel[2][1] = -1;
    Kernel[2][2] = 0;
}
