#include "EmployeeData.h"
#include<fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

EmployeeData::EmployeeData(){
    _maxId = 0;
    _data.resize(0);
}

EmployeeData::EmployeeData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while (inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Employee p(
            j["Id"],
            j["FName"],
            j["MInit"],
            j["LName"],
            j["SSN"],
            j["BDate"],
            j["Address"],
            ((string)j["Sex"])[0],
            j["Salary"],
            j["SuperSSN"],
            j["DNO"]
        );
        _data.push_back(p);
        ++_maxId;
    }
    inFile.close(); 
}   

int EmployeeData::GetMaxId(){
    return _maxId;
}

//Id auto insert by this function PushBack()
int EmployeeData::PushBack(Employee employee){
    // assume: there is 6 employees than _maxId=6
    _maxId++; // _maxId = 7 
    employee.SetId(_maxId);  // id = 7
    _data.push_back(employee);  //add to array
    return _maxId; // return 7
}

Employee* EmployeeData::GetPointer(int i){
    Employee* e = nullptr;
    if (i >= 0 && (i < _data.size())) e = &_data[i];
    return e;
}

int EmployeeData::GetSize(){
    return _data.size();
}

Employee EmployeeData::Get(int i){
    string s("index out of bound!");
    if(i<0) throw s;
    if(i >= _data.size()) throw s;
    return _data[i];
}

int EmployeeData::ExportToFile(string fileName){
    fileName += "Employee.data";
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Employee p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

string EmployeeData::ShowOnFile()
{
    string str;
    for(int i=0; i< _data.size(); ++i)
    {
        str += _data[i].ToString() + "\n";
    }
    return str;

}

//add am employee with 
bool EmployeeData::AddMember()
{
    EmployeeUI employeeUI;
    _maxId++; // _maxId = 7 
    Employee* employee = employeeUI.AddMemberUI();
    employee->Id = _maxId;
    _data.push_back(*employee);
    return true;
}

bool EmployeeData::UpdateMember()
{
    EmployeeUI employeeUI;
    Employee* employee = employeeUI.UpdateMemberUI();

    int id = employee->GetId();
    if(employee->GetFName() != "0") _data[id].FName = employee->GetFName();
    if(employee->GetMInit() != "0") _data[id].MInit = employee->GetMInit();
    if(employee->GetLName() != "0") _data[id].LName = employee->GetLName();
    if(employee->GetSSN() != 0) _data[id].SSN = employee->GetSSN();
    if(employee->GetBDate() != "0")   _data[id].BDate = employee->GetBDate();
    if(employee->GetAddress() != "0") _data[id].Address = employee->GetAddress();
    if(employee->GetSex() != '0')     _data[id].Sex = employee->GetSex();
    if(employee->GetSalary() != 0)  _data[id].Salary = employee->GetSalary();
    if(employee->GetSuperSSN() != 0) _data[id].SuperSSN = employee->GetSuperSSN();
    if(employee->GetDNO() != 0)      _data[id].DNO = employee->GetDNO();
    return true;
}

bool EmployeeData::DeleteMember(){
    EmployeeUI employeeUI;
    int i = employeeUI.DeleteMemberUI();
    if(i < 0){
        return false;
    }else{
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].FName = _data[index+1].FName;
            _data[index].MInit = _data[index+1].MInit;
            _data[index].LName = _data[index+1].LName;
            _data[index].SSN = _data[index+1].SSN;
            _data[index].BDate = _data[index+1].BDate;
            _data[index].Address = _data[index+1].Address;
            _data[index].Sex =_data[index+1].Sex;
            _data[index].Salary =_data[index+1].SuperSSN;
            _data[index].SuperSSN = _data[index+1].SuperSSN;
            _data[index].DNO = _data[index+1].DNO;  
        }
        _data.pop_back();
    return true;   
    }
}

//restructure company 
string EmployeeData::Restructure(string supervisorName){
    long ssn = -1;
    string employeeList = " "; 
    for(int i = 0; i < _data.size(); ++i){
        string s = ( (_data[i].FName) + (_data[i].LName) ); 
        if( s == supervisorName ){
            ssn = _data[i].SSN;
            break;
        }
    }
    for(int i = 0; i < _data.size(); ++i){
        if((_data[i].SuperSSN - ssn) == 0){
            employeeList = employeeList + " ";
            employeeList = employeeList + _data[i].FName;
        }
    }
    return employeeList;
}

float EmployeeData::CalculateSalary(long mgrSSN){
    float averageSalary = 0;
    float countEmployee = 0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].SuperSSN == mgrSSN){
            averageSalary += _data[i].Salary;
            ++countEmployee;
        }
    }
    averageSalary /= float(countEmployee);

    return averageSalary;
}

vector<Employee> EmployeeData::FindEmployeeDepartment(int dno){
    //Initial no employee
    vector<Employee> departmentMember;
    departmentMember.resize(0);
    for(int i = 0; i < _data.size(); ++i)
    {
        if(_data[i].DNO == dno)
        {
            departmentMember.push_back(_data[i]);
        }
    }
    
    return departmentMember;
}

