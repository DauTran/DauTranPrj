#include "DepartmentUI.h"

Department* DepartmentUI::AddMemberUI()
{
    cout<<"DName: "; fflush(stdin); getline(cin, dName); 
    cout<<"MgrSSN: "; cin >> mgrSSN;
    cout<<"DName: "; fflush(stdin); getline(cin, mgrStartDate); 
    cout<<"DNumber: "; cin >> dNumber;

    Department* department = new Department(0,  dName,  mgrSSN,  mgrStartDate, dNumber);
    return department;
}

Department* DepartmentUI::UpdateMemberUI()
{
    cout<<"Insert the Id to update: "; cin>>id; --id;
    cout<<"** Note: Press 0 to ignore!"<<endl;
    cout<<"DName: "; fflush(stdin); getline(cin, dName); 
    cout<<"MgrSSN: "; cin >> mgrSSN;
    cout<<"DName: "; fflush(stdin); getline(cin, mgrStartDate); 
    cout<<"DNumber: "; cin >> dNumber;

    Department* department = new Department( id,  dName,  mgrSSN,  mgrStartDate, dNumber);
    return department;
}

int DepartmentUI::DeleteMemberUI()
{
    cout<<"Insert Id to delete: "; cin>>id;
    --id;
    return id;
}