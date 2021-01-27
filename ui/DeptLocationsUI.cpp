#include "DeptLocationsUI.h"

DeptLocations* DeptLocationsUI::AddMemberUI()
{
    cout<<"DNumber: "; cin>>DNumber; 
    cout<<"DLocation: "; fflush(stdin); getline(cin, DLocation); 

    DeptLocations* deptLocations = new DeptLocations(0, DNumber, DLocation);
    return deptLocations;
}

DeptLocations* DeptLocationsUI::UpdateMemberUI()
{
    cout<<"Insert the Id to update: "; cin>>Id; --Id;
    cout<<"** Note: Press 0 to ignore!"<<endl;
    cout<<"DNumber: "; cin>>DNumber; 
    cout<<"DLocation: "; fflush(stdin); getline(cin, DLocation); 

    DeptLocations* deptLocations = new DeptLocations(Id, DNumber, DLocation);
    return deptLocations;
}

int DeptLocationsUI::DeleteMemberUI()
{
    cout<<"Insert Id to delete: "; cin>>Id;
    --Id;
    return Id;
}