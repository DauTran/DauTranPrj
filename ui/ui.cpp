#include "UI.h"

UI::UI()
{
    chooseFunction = 1;
    chooseTable = 1;
    CompanyData* companyData;
}

void UI::ShowMain()
{
        do
        {
            system("cls");
            cout<<"The list of table: \n";
            cout<<"1. Employee table \n";
            cout<<"2. Department table \n";
            cout<<"3. Department location table \n";
            cout<<"4. Project table \n";
            cout<<"5. Work on table \n";
            cout<<endl;

            cout<<"The list of functional: \n";
            cout<<"6. List the employees of a manager. \n";
            cout<<"7. The total number of hours that all employees have to work for the project. \n";
            cout<<"8. Display the department name and the average salary of the employees working for the department.\n";
            cout<<"9. Displays the names of all employees in a department and work for a particular project with the minimum number of hours.\n";


            cout<<"0. Stop \n";

            cout<<"Chose the table you want: "<<endl;
            cin>>chooseTable;

            switch(chooseTable)
            {
                case 1:
                {
                    companyData = new EmployeeData("DataBase/Employee.data");
                }
                break;

                case 2:
                {
                    companyData = new DepartmentData("DataBase/Department.data");
                }
                break;

                case 3:
                {
                    companyData = new DeptLocationsData("DataBase/DeptLocations.data");
                }
                break;

                case 4:
                {
                    companyData = new ProjectData("DataBase/Project.data");
                }
                break;

                case 5:
                {
                    companyData = new Work_onData("DataBase/Work_on.data");
                }
                break;

                case 6:
                {
                    RestructureCompany();
                    cout << "\n Press number 1 to return: "<<endl;
                    cin >> chooseTable;
                    continue;
                }
                break;

                case 7:
                {
                    GetNameProjectHours();
                    cout << "\n Press number 1 to return: "<<endl;
                    cin >> chooseTable;
                    continue;

                }
                break;

                case 8:
                {
                    CalculateAverageSalary();
                    cout << "\n Press number 1 to return: "<<endl;
                    cin >> chooseTable;
                    continue;

                }
                break;

                case 9:
                {
                    GetHoursProjectEmployeeName();
                    cout << "\n Press number 1 to return: "<<endl;
                    cin >> chooseTable;
                    continue;
                }
                break;

                case 0:
                return;

                default:
                {
                    cout<<"Your choosen wrong, please try again! \n";
                    cout<<"Chose the table you want: "<<endl;
                    cin>>chooseTable;
                }
            }
            do{
                system("cls");
                cout<<"1. Add \n";
                cout<<"2. Update \n";
                cout<<"3. Delete \n";
                cout<<"4. Display \n";
                // cout<<"5. Backup \n";
                cout<<"0. Return \n";

                cout<<"Chose one: "<<endl;
                cin>>chooseFunction;

                if(chooseFunction > 5)
                {
                    cout<<"Your choosen wrong, please try again! \n";
                    cout<<"Chose one: "<<endl;
                    cin>>chooseFunction;
                    
                }
                switch(chooseFunction)
                {
                    case 1:
                        system("cls");
                        companyData->AddMember();
                        companyData->ExportToFile(companyData->GetLink());
                        break;

                    case 2:
                        system("cls");
                        companyData->UpdateMember();
                        companyData->ExportToFile(companyData->GetLink());
                        break;

                    case 3:
                        system("cls");
                        companyData->DeleteMember();
                        companyData->ExportToFile(companyData->GetLink());

                    case 4:
                        system("cls");
                        cout << companyData->ShowOnFile();
                        cout << "\n Press number 1 to return: "<<endl;
                        cin >> chooseFunction;
                        break;

                    default:
                        {
                            cout<<"Your choosen wrong, please try again! \n";
                            cout<<"Chose the function you want: "<<endl;
                            cin>>chooseFunction;
                        }
                }
            }while(chooseFunction);
        }while(chooseTable);
}


void UI::RestructureCompany()
{
    EmployeeData employeeArray("DataBase/Employee.data");
    cout<<"Read file function"<<"\n";
    for(int i=0; i<employeeArray.GetSize(); ++i){
        Employee p = employeeArray.Get(i);
        cout<<p.ToString()<<endl;
    }
    string name;
    cout<<"Insert the name of manager: "; fflush(stdin); getline(cin, name);
    cout<<"List employee of "<<endl;
    for(int i = 0; i<name.size(); ++i)
    {
        if(name[i] == 32) 
        {
            name.erase(i, 1);
        }
    }
    cout<<employeeArray.Restructure(name);
    
}

void UI::GetNameProjectHours()
{
    int projectNumber;
    float projectHour;
    string projectName;
    cout<<" Enter the project number: "; cin>>projectNumber;
    ProjectData projectData("DataBase/Project.data");
    projectName = projectData.GetProjectName(projectNumber);
    cout<<"The project name is: "<<projectName<<endl;

    Work_onData work_onData("DataBase/Work_on.data");
    projectHour = work_onData.GetHoursProject(projectNumber);
    cout<<"Total hours is: "<<projectHour<<endl;

}

void UI::CalculateAverageSalary()
{
    string departmentName;
    cout<<"Insert department name: "<<endl;
    cin>>departmentName;
    
    DepartmentData departmentData("DataBase/Department.data");
    EmployeeData employeeData("DataBase/Employee.data");

    for(int i = 0; i < departmentData.GetSize(); ++i){
        if(departmentData.Get(i).GetDName() == departmentName){
            cout<<"Department number is: "<<departmentData.Get(i).GetDnumber()<<endl;
            cout<<"Average salary: "<<employeeData.CalculateSalary(departmentData.Get(i).GetMgrSSN());
        }
    }
}

void UI::GetHoursProjectEmployeeName()
{
    int projectNumber;
    int departmentNumber;
    ProjectData projectData("DataBase/Project.data");
    Work_onData work_onData("DataBase/Work_on.data");
    EmployeeData employeeData("DataBase/Employee.data");

    cout<<"Insert department number: "; cin>>departmentNumber;
    cout<<"Insert project number: "; cin>>projectNumber;
    //The results
    cout<<"The project is: "<<projectData.GetProjectName(projectNumber, departmentNumber);

    string nameMemberProject;
    float hours = 0;

    vector<Work_on> employeeProject;
    employeeProject = work_onData.GetHoursProjectMin(projectNumber);
    
    vector<Employee> departmentMember;
    departmentMember = employeeData.FindEmployeeDepartment(departmentNumber); 

    for(int i = 0; i < employeeProject.size(); ++i)
    {
        for(int j = 0; j < departmentMember.size(); ++j)
        {
            if(employeeProject[i].GetESSN() == departmentMember[j].GetSSN())
            {
                if(hours == 0)
                {
                    hours = employeeProject[i].GetHours();
                }
                nameMemberProject += departmentMember[j].GetName() + " ";
            }
        }
    }
    cout<<"The names are: "<<endl;
    cout<<nameMemberProject<<endl;
    cout<<"The hous minimum is: "<< hours;
    

}


// void UI::DeleteObject(CompanyData* companyData)
// {

// }