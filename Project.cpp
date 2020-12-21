#include "Project.h"

// Default Contructor
Project::Project(){};
// Contructor with paramaters
Project::Project(int id, std::string pName,std::string pLocation,int pNumber,int dNum){
    Id = id;
    PName=pName;
    PLocation=pLocation;
    PNumber=pNumber;
    DNum=dNum;
}