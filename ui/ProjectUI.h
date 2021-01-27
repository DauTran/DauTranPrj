#ifndef ProjectUI_h_
#define ProjectUI_h_

#include <iostream>
#include <string>

#include "../businessobject/Project.h"

using namespace std;

class ProjectUI
{
    int Id;
    string PName;
    int PNumber;
    string PLocation;
    int DNum;

public:
    Project* AddMemberUI();
    Project* UpdateMemberUI();
    int DeleteMemberUI();

};

#endif