#include <iostream>

#include "../dataaccess/DepartmentData.h"
#include "../businessobject/Department.h"
#include "../businessobject/Company.h"

using namespace std;

int main(){
    string dName; long mgrSSN; string mgrStartDate; int dNumber;
    
    cout<<"dName: "; cin>> dName; 
    cout<<"mgrSSN: "; cin>> mgrSSN; 
    cout<<"mgrStartDate: "; fflush(stdin); getline(cin, mgrStartDate); 
    cout<<"dNumber: "; cin>>dNumber; 

    Company* pC = new Department(0, dName, mgrSSN, mgrStartDate, dNumber);

    CompanyData* companyData = new DepartmentData("DepartmentDatabase.data");

    companyData->AddMember(pC);

    companyData->ExportToFile("DepartmentDatabase.data");

    return 0;
}