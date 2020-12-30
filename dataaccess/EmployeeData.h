#ifndef Project_dataaccess_Employee_Data_H_
#define Project_dataaccess_Employee_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Employee.h"

using namespace std;

class EmployeeData : public CompanyData{
private:
    vector<Employee> _data;
    int _maxId;
public:
    EmployeeData();
    
    EmployeeData(string fileName);

    int GetMaxId();

    int PushBack(Employee);

    //Return a referrent object
    Employee* GetPointer(int i);   //Khai bao con tro kieu Employee

    // Return size of a array of object Employee
    int GetSize();
    

    // Return a object in array employee
    Employee Get(int i);

    int ExportToFile(string filename);

 	bool AddMember(string ); // Q1
    bool DeleteMember(int , string ); // Q2

    // Company UpdateRowTable(Company* );

    
};

#endif