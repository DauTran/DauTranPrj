#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>
class Project{
    int Id;
    std::string PName;
    std::string PLocation;
    int PNumber;
    int DNum;

public:
    // Default Contructor
    Project();
    // Contructor with paramaters
    Project(int id, std::string pName,std::string pLocation,int pNumber,int dNum);
};
#endif