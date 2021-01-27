#include "EmployeeUI.h"

Employee* EmployeeUI::AddMemberUI()
{
    cout<<"First Name: "; cin>>fName; 
    cout<<"Midle Name: "; cin>> mInit; 
    cout<<"Last name: "; cin>>lName; 
    cout<<"SSN: "; cin>>ssn; 
    cout<<"Birthday: "; fflush(stdin); getline(cin, bDate); 
    cout<<"Address: "; getline(cin, address); 
    cout<<"Sex: "; cin>>sex; 
    cout<<"Salary: "; cin>>salary; 
    cout<<"super SSN "; cin>>superSSN; 
    cout<<"DNO: "; cin>>dno;

    Employee* employee = new Employee(0, fName, mInit, lName, ssn, bDate, address, sex, salary, superSSN, dno);
    return employee;
}

Employee* EmployeeUI::UpdateMemberUI()
{
    cout<<"Insert the Id to update: "; cin>>id; --id;
    cout<<"** Note: Press 0 to ignore!"<<endl;
    cout<<"First Name: "; cin>>fName; 
    cout<<"Midle Name: "; cin>> mInit; 
    cout<<"Last name: "; cin>>lName; 
    cout<<"SSN: "; cin>>ssn; 
    cout<<"Birthday: "; fflush(stdin); getline(cin, bDate); 
    cout<<"Address: "; getline(cin, address); 
    cout<<"Sex: "; cin>>sex; 
    cout<<"Salary: "; cin>>salary; 
    cout<<"super SSN "; cin>>superSSN; 
    cout<<"DNO: "; cin>>dno;

    Employee* employee = new Employee(id, fName, mInit, lName, ssn, bDate, address, sex, salary, superSSN, dno);
    return employee;
}

int EmployeeUI::DeleteMemberUI()
{
    cout<<"Insert Id to delete: "; cin>>id;
    --id;
    return id;
}

// int EmployeeUI::ShowMemberUI()
// {
    
// }