#include "Departerment.h"

using namespace std;

// Default Contructor
Departerment::Departerment(){}
// Contructor with paramaters
Departerment::Departerment(int id, std::string dName, long mgrSSN, std::string mgrStartDate,int dNumber){
    Id = id;
    DName = dName;
    MgrSSN = mgrSSN;
    MgrStartDate = mgrStartDate;
    Dnumber=dNumber;
}