#ifndef UI_h_
#define UI_h_
#include <iostream>
#include <stdlib.h>

#include "../dataaccess/CompanyData.h"
#include "../dataaccess/ProjectData.h"
#include "../dataaccess/Work_onData.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/DepartmentData.h"
#include "../dataaccess/DeptLocationsData.h"


using namespace std;

class UI
{
private:
    unsigned int chooseFunction;
    unsigned int chooseTable;
    CompanyData* companyData;
public:
    UI();
    void ShowMain();
    // The Functional 6
    void RestructureCompany();
    //The  Functional 7
    void GetNameProjectHours();
    //The Functional 8
    void CalculateAverageSalary();
    //The Functional 9
    void GetHoursProjectEmployeeName();
};

#endif