#ifndef DepartmentUI_h_
#define DepartmentUI_h_

#include <iostream>
#include <string>
#include "../businessobject/Company.h"
#include "../businessobject/Department.h"
#include "../dataaccess/DepartmentData.h"

using namespace std;

class DepartmentUI
{
    int id;
    string dName;
    long mgrSSN;
    string mgrStartDate;
    int dNumber;

public:
    Department* AddMemberUI();
    Department* UpdateMemberUI();
    int DeleteMemberUI();
};

#endif