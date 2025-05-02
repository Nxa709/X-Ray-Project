#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

class MyImage;

/*Here This is going to be an abstract class  where by I will have my every thing
that will dipict or provide a picture of how my Filters will look like
*/

//Here I am going to have my default values
//I am also going to demostrate Inheritence here

class Filter
{
    public:
    //Here I am going to have my constructors
    Filter();
    Filter(int intRows , int intCols);
    Filter(const Filter&Obj);
    void virtual ApplyTheFilter(MyImage&Obj,int intNumTimes) = 0;
    //Then Here I should also have my destructor
    ~Filter();

    //Here I am going to have my default values
    static const int DEFAULT_ROWS =100;
    static const int DEFAULT_COLS = 100;
protected:
    int _intRows;
     int _intCols;
    void InitKernel();
    void Clone(const Filter&obj);
    void DeAllocMem();
    //This array memory is not dynamically allocated
    //This also saves computational time
    int** Kernel;
};

#endif // FILTER_H_INCLUDED
