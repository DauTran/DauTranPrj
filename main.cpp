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
    employeeArray.ExportToFile("Employee.data");
}

// Read and show on employee information to screen
void read_employee_from_file(){
    // EmployeeData employeeData("Employee1.data");
    EmployeeData employeeArray("Employee1.data");
    cout<<"Read file function"<<"\n";
    for(int i=0; i<employeeArray.GetSize(); ++i){
        Employee p = employeeArray.Get(i);
        cout<<p.ToString()<<endl;
    }
}

// Create a new member from keyboard
void Create(){
    EmployeeData employeeArray("Employee.data");

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
            cout<<"Birthday: "; fflush(stdin); getline(cin, bDate); 
            cout<<"Address: "; getline(cin, address); 
            cout<<"Sex: "; cin>>sex; 
            cout<<"Salary: "; cin>>salary; 
            cout<<"super SSN "; cin>>superSSN; 
            cout<<"DNO: "; cin>>dno;

            Employee employee(id, fName, mInit, lName, ssn, bDate, address, sex, salary, superSSN, dno);
            employeeArray.PushBack(employee);
        }

    }
    employeeArray.CreateNewMember("EmployeeDatabase.data");
   
}

// Delete a member
void Delete(){
    EmployeeData employeeArray("Employee.data");

    employeeArray.DeleteMember(1);
    
}

int main(){
    int yourChoose = 0;
    string supervisorName;
    do
    {
        cout<<"Nhap vao gia tri can nhap: "; cin>>yourChoose;

        switch(yourChoose){
            case 1:
                cout<<"Ban nhap 1"<<endl;
                // write_employee_to_file();
                // read_employee_from_file();
                // Create(); 
                // Delete();
                break;
            case 2:
                
                cout<<"Ban nhap 2"<<endl;
                cout<<"Input supervisor'name: "; fflush(stdin); getline(cin, supervisorName);
                cout<<"Your insert: "<<supervisorName;
                break;
            case 3:
                cout<<"Ban nhap 3"<<endl;
                break;
            case 4:
                cout<<"Ban nhap 4"<<endl;
                break;
            case 5:
                cout<<"Ban nhap 5"<<endl;
                break;
            case 6:
                cout<<"Ban nhap 6"<<endl;
                break;
            case 7:
                cout<<"Ban nhap 7"<<endl;
                break;
            case 8:
                cout<<"Ban nhap 8"<<endl;
                break;
            case 9:
                cout<<"Ban nhap 9"<<endl;
                break;
            default:
                cout<<"Ban da nhap sai "<<endl;
                

        }
       
       
       
        // if(yourChoose ==1){
        //     cout<<"Ban nhap 1";
        // }
        // else if(yourChoose ==2){
        //     cout<<"Ban nhap 2";
        // }else{
        //     cout<<"Moi nhap lai: "; cin>>yourChoose;
        // }
    } while (yourChoose>0 && yourChoose<10);  //Su dung ki tu dac biet de  ket thuc chuong trinh
    
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
