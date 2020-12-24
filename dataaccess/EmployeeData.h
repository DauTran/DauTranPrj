#ifndef Project_dataaccess_Employee_Data_H_
#define Project_dataaccess_Employee_Data_H_
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "../businessobject/Employee.h"

class EmployeeData{
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
    int ExportToFile(string filename);
    // Return size of a array of object Employee
    int GetSize();
    // Return a object in array employee
    Employee Get(int i);
    // Update value
    int Update(int i, Employee employee);

    // Employee GetObj(Employee employee, int i);  //Lay doi tuong ra hien thi
};
#endif