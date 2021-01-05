#include <iostream>

#include "../dataaccess/ProjectData.h"
#include "../dataaccess/CompanyData.h"

#include "../businessobject/Project.h"
#include "../businessobject/Company.h"

using namespace std;

int main(){
    bool isContinue = true;
    CompanyData* companyData = new ProjectData("ProjectDatabase.data");

    do
    {
        if(isContinue == 1){
            // int id, string pName,string pLocation,int pNumber,int dNum
        string pName; string pLocation; int pNumber; int dNum;
        cout<<"pName: "; fflush(stdin); getline(cin, pName); 
        cout<<"pLocation: "; fflush(stdin); getline(cin, pLocation); 
        cout<<"pNumber: "; cin >> pNumber; 
        cout<<"dNum: "; cin >> dNum; 

        Company* pC = new Project(0, pName, pLocation, pNumber, dNum);


        companyData->AddMember(pC);

    }
    else if(isContinue == 0){
        isContinue = false;
    }

    cout<<"0. To stop"; cin >> isContinue;

} while (isContinue);
    companyData->ExportToFile("ProjectDatabase.data");


    return 0;
}