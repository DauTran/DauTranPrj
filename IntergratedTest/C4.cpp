#include <iostream>
#include "../businessobject/Company.h"
#include "../businessobject/Work_on.h"
#include "../businessobject/Project.h"

#include "../dataaccess/CompanyData.h"
#include "../dataaccess/Work_onData.h"
#include "../dataaccess/ProjectData.h"

#include "../libs/json.hpp"
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;


void Write_Work_on_to_file(){

    Work_onData Work_onDataArray("Work_on.data");

    Work_on w1(1, 123456789, 1, 32.5);
    Work_onDataArray.PushBack(w1);
    Work_on w2(2, 123456789, 2, 7.5);
    Work_onDataArray.PushBack(w2);
    Work_on w3(3, 666884444, 3, 40.0);
    Work_onDataArray.PushBack(w3);
    Work_on w4(4, 453453453, 1, 20.0);
    Work_onDataArray.PushBack(w4);
    Work_on w5(5, 453453453, 2, 20.0);
    Work_onDataArray.PushBack(w5);
    Work_on w6(6, 333445555, 2, 10.0);
    Work_onDataArray.PushBack(w6);
    Work_on w7(7, 333445555, 3, 10.0);
    Work_onDataArray.PushBack(w7);
    Work_on w8(8, 333445555, 10, 10.0);
    Work_onDataArray.PushBack(w8);
    Work_on w9(9, 999887777, 10, 10.0);
    Work_onDataArray.PushBack(w9);
    Work_on w10(10, 999887777, 20, 10.0);
    Work_onDataArray.PushBack(w10);
    Work_on w11(11, 987987987, 30, 30.0);
    Work_onDataArray.PushBack(w11);
    Work_on w12(12, 987987987, 10, 10.0);
    Work_onDataArray.PushBack(w12);
    Work_on w13(13, 987654321, 10,35.0 );
    Work_onDataArray.PushBack(w13);
    Work_on w14(14, 987654321, 30, 20.0);
    Work_onDataArray.PushBack(w14);
    Work_on w15(15, 987654321, 20, 15.0);
    Work_onDataArray.PushBack(w15);
    Work_on w16(16, 888665555, 20, -1);
    Work_onDataArray.PushBack(w16);
    

// Save an employee to a string

    for(int i=0; i < Work_onDataArray.GetSize(); ++i){
        Work_on p = Work_onDataArray.Get(i);
        cout<<p.ToString()<<endl;
    }
    Work_onDataArray.ExportToFile("Work_on.data");
}

void Write_Project_to_file(){
    ProjectData projectDataArray("Project.data");

    Project p1(1, "ProductX", "Bellaire", 1, 5);
    projectDataArray.PushBack(p1);
    Project p2(2, "ProductY", "Sugarland", 2, 5);
    projectDataArray.PushBack(p2);
    Project p3(3, "ProductZ", "Houston", 3, 5);
    projectDataArray.PushBack(p3);
    Project p4(4, "Computerization", "Stafford", 10, 4);
    projectDataArray.PushBack(p4);
    Project p5(5, "Reorganization", "Houston", 20, 1);
    projectDataArray.PushBack(p5);
    Project p6(6, "Newbenefits", "Stafford", 30, 4);
    projectDataArray.PushBack(p6);

    for(int i=0; i < projectDataArray.GetSize(); ++i){
        Project p = projectDataArray.Get(i);
        cout<<p.ToString()<<endl;
    }
    projectDataArray.ExportToFile("Project.data");

}
//Nho thay doi hours work_on sang kieu float
// Cau4 them 1 ham GetProjectName trong ProjectData.h, ProjectData.cpp. 1 ham GetHoursProject trong Work_on trong Work_onData.cpp, Work_onData.h 
void GetNameProjectHours(){
    int projectNumber;
    float projectHour;
    string projectName;
    cout<<" Enter the project number: "; cin>>projectNumber;
    ProjectData projectData("Project.data");
    projectName = projectData.GetProjectName(projectNumber);
    cout<<"The project name is: "<<projectName<<endl;

    Work_onData work_onData("Work_on.data");
    projectHour = work_onData.GetHoursProject(projectNumber);
    cout<<"Total hours is: "<<projectHour<<endl;

}

int main(){
    Write_Work_on_to_file();
    Write_Project_to_file();
    // Cau4
    GetNameProjectHours();

    return 0;
}