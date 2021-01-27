#ifndef DeptLocationsUI_h_
#define DeptLocationsUI_h_

#include <iostream>
#include <string>
#include "../businessobject/Company.h"
#include "../businessobject/DeptLocations.h"
#include "../dataaccess/DeptLocationsData.h"

using namespace std;

class DeptLocationsUI
{
    int Id;
    int DNumber;
    string DLocation;

public:
    DeptLocations* AddMemberUI();
    DeptLocations* UpdateMemberUI();
    int DeleteMemberUI();

};


#endif