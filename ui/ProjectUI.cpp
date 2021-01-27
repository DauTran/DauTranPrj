#include "ProjectUI.h"

Project* ProjectUI::AddMemberUI()
{
    cout<<"PName: "; fflush(stdin); getline(cin, PName); 
    cout<<"PNumber: "; cin>> PNumber;
    cout<<"PLocation: "; fflush(stdin); getline(cin, PLocation); 
    cout<<"DNum: "; cin>> DNum;
    
    Project* project = new Project(0,  PName,  PLocation, PNumber, DNum);
    return project;
}

Project* ProjectUI::UpdateMemberUI()
{
    cout<<"Insert the Id to update: "; cin>>Id; --Id;
    cout<<"** Note: Press 0 to ignore!"<<endl;
    cout<<"PName: "; fflush(stdin); getline(cin, PName); 
    cout<<"PNumber: "; cin>> PNumber;
    cout<<"PLocation: "; fflush(stdin); getline(cin, PLocation); 
    cout<<"DNum: "; cin>> DNum;
    
    Project* project = new Project(Id,  PName,   PLocation, PNumber, DNum);
    return project;
}

int ProjectUI::DeleteMemberUI()
{
    cout<<"Insert Id to delete: "; cin>>Id;
    --Id;
    return Id;
}