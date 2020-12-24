#include <iostream>
#include "businessobject/Employee.h"
#include "dataaccess/EmployeeData.h"
#include "libs/json.hpp"
using namespace std;
using json = nlohmann::json;

void write_employee_to_file(){
    
        // Employee e(1, "Chau", "Bao", "Ngo", 111222333, "1975-04-30", "Chicago", 'M', 10000, -1, 5);
    Employee e1(1, "John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee e2(2, "Franklin", "T", "Wong", 333445555, "1955-12-08", "638’vbss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee e3(3,"Alida", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring. TX", 'F', 25000, 987654321, 4);
    Employee e4(4, "Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry Bellaire. TX", 'F', 43000, 888665555, 4);
    Employee e5(5, "Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Huml* TX", 'M', 38000, 333445555, 5);
    Employee e6(6, "Joyce", "A", "English", 453453453, "1972-07-31", "5631 Rice, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e7(7, "Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas. Houston, TX", 'M', 25000, 987654321, 4);
    Employee e8(8, "James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    
    EmployeeData employeeData;
    employeeData.PushBack(e1);
    employeeData.PushBack(e2);
    employeeData.PushBack(e3);
    employeeData.PushBack(e4);
    employeeData.PushBack(e5);
    employeeData.PushBack(e6);
    employeeData.PushBack(e7);
    employeeData.PushBack(e8);

    for(int i=0; i < employeeData.GetSize(); ++i){
        Employee p = employeeData.Get(i);
        cout<<p.ToString()<<endl;
    }

    employeeData.ExportToFile("Employee1.data");
}

void read_employee_from_file(){
    
    EmployeeData employeeData("Employee1.data");

    cout<<"Read file function"<<"\n";
    for(int i=0; i<employeeData.GetSize(); ++i){
        Employee p = employeeData.Get(i);
        cout<<p.ToString()<<endl;
    }
}

int main(){

    write_employee_to_file();
    read_employee_from_file();
    

   

    // Employee* e = employeeData.GetPointer(7);
    // if (e == nullptr){
    //     cout << "can not get Employee" << endl;
    // }
    // else{
    //     // cout << e->GetId() << endl;
    //     cout << e->ToString()<<endl;
    // }
   

    return 0;
}

