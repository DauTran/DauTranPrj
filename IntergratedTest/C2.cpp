#include <iostream>
#include "../dataaccess/CompanyData.h"
#include "../dataaccess/EmployeeData.h"

#include "../businessobject/Company.h"
#include "../businessobject/Employee.h"

#include "../libs/json.hpp"
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;
//Cau 2 them 1 ham Restructure() trong EmployeeData.h EmployeeData.cpp  
void RestructureCompany(){
    EmployeeData employeeArray("Employee.data");
    cout<<"Read file function"<<"\n";
    for(int i=0; i<employeeArray.GetSize(); ++i){
        Employee p = employeeArray.Get(i);
        cout<<p.ToString()<<endl;
    }

    string name;
    cout<<"Nhap ten quan ly: "; cin>>name;
    cout<<"List employee of "<<endl;
    cout<<employeeArray.Restructure(name);
    
}

int main(){

    RestructureCompany();

    return 0;
}
