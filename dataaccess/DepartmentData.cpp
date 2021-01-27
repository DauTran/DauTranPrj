#include "DepartmentData.h"
#include<fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DepartmentData::DepartmentData(){
    _maxId = 0;
    _data.resize(0);
}

DepartmentData::DepartmentData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Department p(
            j["Id"],
            j["DName"],
            j["MgrSSN"],
            j["MgrStartDate"],
            j["Dnumber"]
        );
        _data.push_back(p);
    }
    inFile.close();
}

int DepartmentData::GetMaxId(){
    return _maxId;
}

int DepartmentData::PushBack(Department department){
    _maxId++;
    department.Id = _maxId;
    _data.push_back(department);
    return _maxId;
}

Department* DepartmentData::GetPointer(int i){
    Department* department = nullptr;
    if( i >= 0 && (_data.size()) ) department = &_data[i];
    return department;
}

int DepartmentData::GetSize(){
    return _data.size();
}

Department DepartmentData::Get(int i){
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int DepartmentData::ExportToFile(string fileName ){
    fileName += "Department.data";
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Department p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

string DepartmentData::ShowOnFile()
{
    string str;
    for(int i=0; i< _data.size(); ++i)
    {
        str += _data[i].ToString() + "\n";
    }
    return str;

}

bool DepartmentData::AddMember(){
    DepartmentUI departmentUI;
    _maxId++;
    Department* department = departmentUI.AddMemberUI();
    department->Id = _maxId;
    _data.push_back(*department);
    return true;
}

bool DepartmentData::UpdateMember()
{
    DepartmentUI departmentUI;
    Department* department = departmentUI.UpdateMemberUI();
    int id = department->GetId();

    if(department->GetDName() != "0") _data[id].DName = department->GetDName();
    if(department->GetMgrSSN() != 0) _data[id].MgrSSN = department->GetMgrSSN();
    if(department->GetMgrStartDate() != "0") _data[id].MgrStartDate = department->GetMgrStartDate();
    if(department->GetDnumber() != 0) _data[id].Dnumber = department->GetDnumber();

    return true;
}

bool DepartmentData::DeleteMember(){
    DepartmentUI departmentUI;
    int i = departmentUI.DeleteMemberUI();
    if(i < 0){
        return false;
    }else{
        for(int index=i; index < _data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].DName = _data[index+1].DName;
            _data[index].MgrSSN = _data[index+1].MgrSSN;
            _data[index].MgrStartDate = _data[index+1].MgrStartDate;
            _data[index].Dnumber = _data[index+1].Dnumber;
        }
        _data.pop_back();
    return true;   
    }
}
