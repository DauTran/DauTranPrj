#include <iostream>

#include "../dataaccess/DeptLocationsData.h"
#include "../businessobject/DeptLocations.h"
#include "../businessobject/Company.h"

using namespace std;

int main(){
    bool isContinue = true;
    CompanyData* companyData = new DeptLocationsData("DeptLocationsDatabase.data");

    do
    {
        if(isContinue == 1){
            int dNumber; string dLocation;
            
            cout<<"dNumber: "; cin>> dNumber; 
            cout<<"dLocation: "; fflush(stdin); getline(cin, dLocation); 
            


            Company* pC = new DeptLocations(0, dNumber, dLocation);


            companyData->AddMember(pC);

            companyData->ExportToFile("DeptLocationsDatabase.data");
        }else if(isContinue == 0){
            isContinue = false;
        }

        cout<<"0. To stop"; cin >> isContinue;

    } while (isContinue);

    return 0;
}