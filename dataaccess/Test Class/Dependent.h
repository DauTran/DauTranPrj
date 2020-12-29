#ifndef _DENPENDENT_H_
#define _DEPENDENT_H_
#include <string>
class Dependent{
    long ESSN;
    std::string DependentName;
    char Sex;
    std::string BDate;
    std::string Relationship;

public:
    Dependent(long eSSN,std::string dependentName,char sex,std::string bDate,std::string relationship);
    Dependent();
};
#endif