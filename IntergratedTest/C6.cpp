#include <iostream>
#include "../businessobject/Company.h"
#include "../businessobject/Employee.h"
#include "../businessobject/Department.h"

#include "../dataaccess/CompanyData.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/DepartmentData.h"

#include "../libs/json.hpp"
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;
void Write_Department_to_file(){

    DepartmentData departmentDataArray("Department.data");
    
    Department d1(1, "Research", 333445555, "1988-05-22", 5);
    departmentDataArray.PushBack(d1);
    
    Department d2(2, "Administration", 987654321, "1995-01-01", 4);
    departmentDataArray.PushBack(d2);
    
    Department d3(3, "Headquarters", 888665555, "1981-06-19", 1);
    departmentDataArray.PushBack(d3);

    for(int i=0; i < departmentDataArray.GetSize(); ++i){
        Department d = departmentDataArray.Get(i);
        cout<<d.ToString()<<endl;
    }
    departmentDataArray.ExportToFile("Department.data");
}
//Cau 6 them 
void CalculateAverageSalary(){
    string departmentName;
    cout<<"Insert department name: "<<endl;
    cin>>departmentName;
    
    DepartmentData departmentData("Department.data");
    EmployeeData employeeData("Employee.data");

    for(int i = 0; i < departmentData.GetSize(); ++i){
        if(departmentData.Get(i).GetDName() == departmentName){
            cout<<"Department number is: "<<departmentData.Get(i).GetDnumber()<<endl;
            cout<<"Average salary: "<<employeeData.CalculateSalary(departmentData.Get(i).GetMgrSSN());
        }
    }
}

int main(){
    Write_Department_to_file();
    // CalculateAverageSalary();
    return 0;
}




//Cau 6 ver1 
// void CalculateAverageSalary(){
//     string departmentName;
//     cout<<"Insert department name: "<<endl;
//     cin>>departmentName;
    
//     DepartmentData departmentData("Department.data");
//     EmployeeData employeeData("Employee.data");

//     for(int i = 0; i < departmentData.GetSize(); ++i){
//         if(departmentData.Get(i).GetDName() == departmentName){
//             cout<<"Department number is: "<<departmentData.Get(i).GetDnumber()<<endl;
//             int averageSalary = 0;
//             int countEmployee = 0;
//             for(int j = 0; j < employeeData.GetSize(); ++i){
//                 if(employeeData.Get(j).GetSuperSSN() == departmentData.Get(i).GetMgrSSN()){
//                     cout<<employeeData.Get(j).GetSuperSSN()<<endl;
//                     cout<<departmentData.Get(i).GetMgrSSN()<<endl;
//                     ++countEmployee;
//                     averageSalary = averageSalary + employeeData.Get(j).GetSalary();
//                 }
//                 cout<<"count " <<countEmployee;
//             }
//             averageSalary = averageSalary / countEmployee;
            
//             cout<<"Average salary: "<<averageSalary;
//             return;
//         }
//     }
//     departmentData.GetNameDepartment(departmentName);

// }