#ifndef _DENPENDENT_H_
#define _DEPENDENT_H_
#include <string>
class Dependent{
    int Id;
    long ESSN;
    std::string DepndentName;
    char Sex;
    std::string BDate;
    std::string Relationship;

public:
    Dependent(int id, long eSSN,std::string depndentName,char sex,std::string bDate,std::string relationShip);
    Dependent();
};
#endif