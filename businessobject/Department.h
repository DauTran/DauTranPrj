#ifndef _DEPARTERMENT_H_
#define _DEPARTERMENT_H_
#include string
class Departerment{
    stdstring DName;
    long MgrSSN;
    stdstring MgrStartDate;
    int Dnumber;

public
     Default Contructor
    Departerment();
     Contructor with paramaters
    Departerment(stdstring dName, long mgrSSN, stdstring mgrStartDate,int dNumber);
};
#endif 