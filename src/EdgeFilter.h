#ifndef EDGEFILTER_H_INCLUDED
#define EDGEFILTER_H_INCLUDED
#include <iostream>
#include "Filter.h"
using namespace std;


//This class inherits from Filter class
class EdgeFilter :public Filter
{
public:
    //It should have its own constuctors
    EdgeFilter();
    EdgeFilter(int intRows , int intCols);
    void ApplyTheFilter(MyImage&Obj, int intNumTimes) override;
private:
    //Here It then going to have it own applyEdgeFilterFunction

    void InitEdgeKernel();

};


#endif // EDGEFILTER_H_INCLUDED
