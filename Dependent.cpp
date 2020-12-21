#include "Dependent.h"

Dependent::Dependent(){}
Dependent::Dependent(int id, long eSSN,std::string depndentName,char sex,std::string bDate,std::string relationShip){
    Id = id;
    ESSN=eSSN;
    DepndentName=depndentName;
    Sex=sex;
    BDate=bDate;
    Relationship=relationShip;
}