#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
class Work_on{
    long ESSN;
    int PNO;
    float Hours;

public:
    // Default Contructor
    Work_on();
    // Contructor with paramaters
    Work_on(long eSSN,int pno,int hours);
};
#endif