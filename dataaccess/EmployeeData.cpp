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
    }
    inFile.close();
   
    
}   

int EmployeeData::GetMaxId(){
    return _maxId;
}
int EmployeeData::PushBack(Employee e){
    if (_maxId < e.GetId()){
        _maxId = e.GetId();
    }
    _data.push_back(e);
    return _maxId;
}

Employee* EmployeeData::GetPointer(int i){
    Employee* e = nullptr;
    if (i >= 0 && i<_data.size())
        e = &_data[i];
    return e;
}

int EmployeeData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if(!outFile){
        return 0;
    }
    for(Employee p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
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

int EmployeeData::Update(int i, Employee employee){
    if(i<0) return -1;
    else if(i>_data.size()) return -1;

    _data[i] = employee;

    else if(_maxId < employee.Id) _maxId = employee.Id;
    
    else return _maxId;
}