#include <iostream>
#include <vector>
#include <string>
#include "../libs/json.hpp"

#include "../businessobject/Employee.h"
#include "../businessobject/Project.h"
#include "../businessobject/Work_on.h"

// #include "../dataaccess/CompanyData.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/ProjectData.h"
#include "../dataaccess/Work_onData.h"


using namespace std;
using json = nlohmann::json;

void GetHoursProjectEmployeeName(){
    int projectNumber;
    int departmentNumber;
    ProjectData projectData("Project.data");
    Work_onData work_onData("Work_on.data");
    EmployeeData employeeData("Employee.data");

    cout<<"Insert department number: "; cin>>departmentNumber;
    cout<<"Insert project number: "; cin>>projectNumber;
    //The results
    cout<<"The project is: "<<projectData.GetProjectName(projectNumber, departmentNumber);

    string nameMemberProject;
    float hours = 0;

    vector<Work_on> employeeProject;
    employeeProject = work_onData.GetHoursProjectMin(projectNumber);
    
    vector<Employee> departmentMember;
    departmentMember = employeeData.FindEmployeeDepartment(departmentNumber); 

    for(int i = 0; i < employeeProject.size(); ++i)
    {
        for(int j = 0; j < departmentMember.size(); ++j)
        {
            if(employeeProject[i].GetESSN() == departmentMember[j].GetSSN())
            {
                if(hours == 0)
                {
                    hours = employeeProject[i].GetHours();
                }
                nameMemberProject += departmentMember[j].GetName() + " ";
            }
        }
    }
    cout<<"The names are: "<<endl;
    cout<<nameMemberProject<<endl;
    cout<<"The hous minimum is: "<< hours;
    

}

int main(){
    GetHoursProjectEmployeeName();

    return 0;
}









// void Sort()
// {
//     vector<int> vt{5, 9, 2, 8, 4, 0, 1, 3};
//     int temp;
//     for(int i = vt.size()-1; i > 0; --i){
//         for(int j = 0; j < i; ++j){
//             if(vt[j] > vt[j+1]){
//                 temp = vt[j+1];
//                 vt[j+1] = vt[j];
//                 vt[j] = temp;
//             }
//         }
//     }

//     cout<<"The result is: "<<endl; 
//     for(int i = 0; i < vt.size(); ++i){
//         cout<<vt[i]<<endl;
//     }
// }