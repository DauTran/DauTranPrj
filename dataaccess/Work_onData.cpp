#include "Work_onData.h"
#include <string>
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;
using namespace std;

Work_onData::Work_onData()
{
    _maxId = 0;
    _data.resize(0);
}


Work_onData :: Work_onData(string fileName)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Work_on w(
            j["Id"],
            j["ESSN"],
            j["PNO"], 
            j["Hours"]
        );
        _data.push_back(w);
        _maxId ++;

    }
    inFile.close();
}

int Work_onData::GetMaxId()
{
    return _maxId;
}

int Work_onData::PushBack(Work_on w)
{
    if (_maxId < w.GetId()){
        _maxId = w.GetId();
    }
    _data.push_back(w);
    return _maxId;
}


Work_on* Work_onData::GetPointer(int i)
{
    Work_on* w = nullptr;
    if (i >= 0 && i<_data.size())
        w = &_data[i];
    return w;
}

int Work_onData :: GetSize()
{
    return _data.size();
}

Work_on Work_onData :: Get(int i)
{
    string s("index out of bound");
    if(i<0) throw s;
    if(i> _data.size()) throw s;
    return _data [i];
}


int Work_onData :: ExportToFile(string fileName)
{
    fileName += "Work_on.data";
    ofstream outFile(fileName, ios::out);
    if (!outFile) return 0;
    for (Work_on e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

string Work_onData::ShowOnFile()
{
    string str;
    for(int i=0; i< _data.size(); ++i)
    {
        str += _data[i].ToString() + "\n";
    }
    return str;
}

bool Work_onData::AddMember(){
    Work_onUI work_onUI;
    _maxId++;
    Work_on* work_on = work_onUI.AddMemberUI();
    work_on->Id = _maxId;
    _data.push_back(*work_on);
    return true;
}

bool Work_onData::UpdateMember()
{
    Work_onUI work_onUI;
    Work_on* work_on = work_onUI.UpdateMemberUI();

    int id = work_on->GetId();
    if(work_on->GetESSN() != 0) _data[id].ESSN = work_on->GetESSN();
    if(work_on->GetPNO() != 0)  _data[id].PNO = work_on->GetPNO();
    if(work_on->GetHours() != 0) _data[id].Hours = work_on->GetHours();
    return true;
}

bool Work_onData::DeleteMember(){
    Work_onUI work_onUI;
    int i = work_onUI.DeleteMemberUI();
    if(i < 0){
        return false;
    }else{
        for(int index=i; index < _data.size()-1; ++index){
            _data[index].Id    = _data[index].Id-1;
            _data[index].ESSN  = _data[index+1].ESSN;
            _data[index].PNO   = _data[index+1].PNO;
            _data[index].Hours = _data[index+1].Hours ;

        }
        _data.pop_back();
        return true;
    }
}

float Work_onData::GetHoursProject(int projectNumber){
    float hoursProject = 0.0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNO == projectNumber){
            hoursProject += _data[i].Hours; 
        }
    }
    return hoursProject;
}

vector<Work_on> Work_onData::GetHoursProjectMin(int pno)
{
    vector<Work_on> employeeProject;
    employeeProject.resize(0);

    for(int i = 0; i < _data.size(); ++i)
    {
        if(_data[i].PNO == pno) employeeProject.push_back(_data[i]); 
    }


    //Sort following the value of hours column
    Work_on temp;
    for(int i = employeeProject.size()-1; i > 0 ; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(employeeProject[j].Hours > employeeProject[j+1].Hours)
            {
                temp = employeeProject[j+1];
                employeeProject[j+1] = employeeProject[j];
                employeeProject[j] = temp;
            }
        }
    }
    return employeeProject;
}



