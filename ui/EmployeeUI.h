#ifndef EmployeeUI_h_
#define EmployeeUI_h_

#include <iostream>
#include <string>
#include "../businessobject/Company.h"
#include "../businessobject/Employee.h"
#include "../dataaccess/EmployeeData.h"

using namespace std;

class EmployeeUI
{
    int id;
    string fName;
    string mInit;
    string lName; 
    long ssn; 
    string bDate; 
    string address; 
    char sex; 
    int salary; 
    long superSSN; 
    int dno;
    
public:      
    Employee* AddMemberUI();
    Employee* UpdateMemberUI();
    int DeleteMemberUI(); 


};
#endif