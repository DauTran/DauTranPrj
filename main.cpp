#include <iostream>
#include "dataaccess/CompanyData.h"
#include "businessobject/Employee.h"
#include "dataaccess/EmployeeData.h"
#include "libs/json.hpp"
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

EmployeeData employeeArray;

void write_employee_to_file(){
    // EmployeeData employeeArray;

    // Employee e(1, "Chau", "Bao", "Ngo", 111222333, "1975-04-30", "Chicago", 'M', 10000, -1, 5);
    Employee e1(1, "John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee e2(2, "Franklin", "T", "Wong", 333445555, "1955-12-08", "638’vbss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee e3(3, "Alida", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring. TX", 'F', 25000, 987654321, 4);
    Employee e4(4, "Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry Bellaire. TX", 'F', 43000, 888665555, 4);
    Employee e5(5, "Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Huml* TX", 'M', 38000, 333445555, 5);
    Employee e6(6, "Joyce", "A", "English", 453453453, "1972-07-31", "5631 Rice, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e7(7, "Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas. Houston, TX", 'M', 25000, 987654321, 4);
    Employee e8(8, "James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    
    employeeArray.PushBack(e1);
    employeeArray.PushBack(e2);
    employeeArray.PushBack(e3);
    employeeArray.PushBack(e4);
    employeeArray.PushBack(e5);
    employeeArray.PushBack(e6);
    employeeArray.PushBack(e7);
    employeeArray.PushBack(e8);

// Save an employee to a string
    for(int i=0; i < employeeArray.GetSize(); ++i){
        Employee p = employeeArray.Get(i);
        cout<<p.ToString()<<endl;
    }
    employeeArray.ExportToFile("Employee1.data");
}

// Show on employee information to screen
void read_employee_from_file(){
    
    EmployeeData employeeData("Employee1.data");
    employeeData.DeleteMember(1);

    cout<<"Read file function"<<"\n";

    for(int i=0; i<employeeData.GetSize(); ++i){
        Employee p = employeeData.Get(i);
        cout<<p.ToString()<<endl;
    }
    employeeData.ExportToFile("Employee1.data");
}

// Create a new member from keyboard
void Create(){

    
    bool isContinue = true;
    while(isContinue){
        int yourChoise = 0;
        cout<< "Select your action: "<<endl;
        cout<< "1. create "<<endl;
        cout<< "0. stop"<<endl;
        cin>>yourChoise;
        if(yourChoise == 0){
            isContinue = false;
        }
        else if(yourChoise == 1){
            
            int id; string fName; string mInit; string lName; long ssn; string bDate; string address; char sex; int salary; long superSSN; int dno;
            cout<<"Id: "; cin>>id;
            cout<<"First Name: "; cin>>fName; 
            cout<<"Midle Name: "; cin>> mInit; 
            cout<<"Last name: "; cin>>lName; 
            cout<<"SSN: "; cin>>ssn; 
            cout<<"Birthday: "; getline(cin, bDate); 
            cout<<"Address: "; getline(cin, address); 
            cout<<"Sex: "; cin>>sex; 
            cout<<"Salary: "; cin>>salary; 
            cout<<"super SSN "; cin>>superSSN; 
            cout<<"DNO: "; cin>>dno;

            Employee employee(id, fName, mInit, lName, ssn, bDate, address, sex, salary, superSSN, dno);
            
            employeeArray.PushBack(employee);

        }

    }
    employeeArray.CreateNewMember();
   
}

// Delete a member
void Delete(){
    employeeArray.DeleteMember(1);
    employeeArray.ExportToFile("Employee1.data");
}

int main(){

    // write_employee_to_file();
    read_employee_from_file();
    // Create(); 
    // Delete();

   

    return 0;
}
// Hien thi phan tu thu i ra man hinh
    // Employee* e = employeeData.GetPointer(7);
    // if (e == nullptr){
    //     cout << "can not get Employee" << endl;
    // }
    // else{
    //     // cout << e->GetId() << endl;
    //     cout << e->ToString()<<endl;
    // }
