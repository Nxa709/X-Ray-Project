#include <iostream>
#include<fstream>
#include "Image.h"
#include "MyProjectXRay.h"
#include "EdgeFilter.h"
using namespace std;

int main(int argc , char**argv)
{

//Here I am going to read th
    string FileName = argv[1];
    int intNumTimes = ConvToInt(argv[2]);
    //So the problem is that I did not declare my Image as .ppm that is why
    //It was giving me problems
    MyImage Obj = LoadToPPM("Chest.ppm");
    EdgeFilter* Object_2 = new EdgeFilter();
    Object_2 -> ApplyTheFilter(Obj,intNumTimes);

    cout << Obj.toPPM();
    return 0;
}
