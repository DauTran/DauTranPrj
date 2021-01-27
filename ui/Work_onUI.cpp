#include "Work_onUI.h"

Work_on* Work_onUI::AddMemberUI()
{
    cout<<"ESSN: "; cin>>ESSN; 
    cout<<"Midle PNO: "; cin>> PNO; 
    cout<<"Hours: "; cin>>Hours; 

    Work_on* work_on = new Work_on(0, ESSN, PNO, Hours);
    return work_on;
}

Work_on* Work_onUI::UpdateMemberUI()
{
    cout<<"Insert the Id to update: "; cin>>Id; --Id;
    cout<<"** Note: Press 0 to ignore!"<<endl;
    cout<<"ESSN: "; cin>>ESSN; 
    cout<<"Midle PNO: "; cin>> PNO; 
    cout<<"Hours: "; cin>>Hours; 

    Work_on* work_on = new Work_on(Id, ESSN, PNO, Hours);
    return work_on;
}

int Work_onUI::DeleteMemberUI()
{
    cout<<"Insert Id to delete: "; cin>>Id;
    --Id;
    return Id;
}