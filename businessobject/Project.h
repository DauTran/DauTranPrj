#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>
#include "../libs/json.hpp"
#include "Company.h"

using json = nlohmann::json;
using namespace std;

class Project : public Company{
    int Id;
    string PName;
    int PNumber;
    string PLocation;
    int DNum;

public:
    friend class ProjectData;
    // Default Contructor
    Project();
    // Contructor with paramaters
    Project(int id, string pName, string pLocation,int pNumber,int dNum);
    string ToString();
    json ToJson();

    int GetId();
    string GetPName();
    int GetPNumber();
    string GetPLocation();
    int GetDNum();
};

#endif