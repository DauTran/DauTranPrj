#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
class Work_on{
    int Id;
    long ESSN;
    int PNO;
    float HOURS;

public:
    // Default Contructor
    Work_on();
    // Contructor with paramaters
    Work_on(int id, long eSSN,int pNO,int hours);
};
#endif