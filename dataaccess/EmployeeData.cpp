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
    if (i >= 0 && i<_data.size())
        e = &_data[i];
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

bool EmployeeData::CreateNewMember(string fileName){
    ofstream outFile(fileName, ios::app);
    if(!outFile){
        return false;
    }else{
        for(Employee employee : _data){
            outFile<<employee.ToJson()<<endl;
        }
        outFile.close();

        return true;
    }
}

bool EmployeeData::DeleteMember(int i){
    if(i < 0){
        return false;
    }else{
        for(int index=i; index<_data.size()-1; ++index){
            _data[index] = _data[index+1];   
            _data[index] = ChangeValues(_data[index]);
        }
        _data.pop_back();
        ofstream outFile("Employee.data", ios::out);
        for(Employee employee : _data){
            outFile<<employee.ToJson()<<endl;
        }
        outFile.close();

        return true;   
    }
}

// Company EmployeeData::UpdateRowTable(Company* company){
//     company = new Employee();
//     return *company;
// }



