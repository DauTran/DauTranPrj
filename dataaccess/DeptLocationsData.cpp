#include "DeptLocationsData.h"
#include<fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DeptLocationsData::DeptLocationsData(){
    _maxId = 0;
    _data.resize(0);
}

DeptLocationsData::DeptLocationsData(string fileName){
    ifstream inFile(fileName);  
    _maxId = 0;  
    _data.resize(0);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        DeptLocations p(
            j["Id"],
            j["DNumber"],
            j["DLocation"]
            );
        _data.push_back(p);
        ++_maxId;
    }
    // _maxId = _data.back().Id;

    inFile.close();
}

int DeptLocationsData::GetMaxId(){
    return _maxId;
}

int DeptLocationsData::PushBack(DeptLocations deptLocations){
    _maxId++;
    deptLocations.Id = _maxId;
    _data.push_back(deptLocations);
    return _maxId;
}

DeptLocations* DeptLocationsData::GetPointer(int i){
    DeptLocations* deptLocations = nullptr;
    if( i >= 0 && (_data.size()) ) deptLocations = &_data[i];
    return deptLocations;
}

int DeptLocationsData::GetSize(){
    return _data.size();
}

DeptLocations DeptLocationsData::Get(int i){
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int DeptLocationsData::ExportToFile(string fileName ){
    fileName += "DeptLocations.data";
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(DeptLocations p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}


string DeptLocationsData::ShowOnFile()
{
    string str;
    for(int i=0; i< _data.size(); ++i)
    {
        str += _data[i].ToString() + "\n";
    }
    return str;

}

bool DeptLocationsData::AddMember(){
    DeptLocationsUI deptLocationsUI;
    _maxId++;
    DeptLocations* deptLocations = deptLocationsUI.AddMemberUI();
    deptLocations->Id = _maxId;
    _data.push_back(*deptLocations);
    return true;
}

bool DeptLocationsData::UpdateMember()
{
    DeptLocationsUI deptLocationsUI;
    DeptLocations* deptLocations = deptLocationsUI.UpdateMemberUI();

    int id = deptLocations->GetId();
    
    if(deptLocations->GetDNumber() != 0) _data[id].DNumber = deptLocations->GetDNumber();
    if(deptLocations->GetDLocation() != "0") _data[id].DLocation = deptLocations->GetDLocation();
    return true;
}

bool DeptLocationsData::DeleteMember()
{ 
    DeptLocationsUI deptLocationsUI;
    int i = deptLocationsUI.DeleteMemberUI();
    
    if(i < 0){
        return false;
    }else{
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].DNumber = _data[index+1].DNumber;
            _data[index].DLocation = _data[index+1].DLocation;
        }
        _data.pop_back();
    return true;   
    }
}
