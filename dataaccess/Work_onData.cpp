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

Work_onData :: Work_onData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
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

int Work_onData :: ExportToFile(string filename)
{
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Work_on e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

bool Work_onData::AddMember(Company* company){
    _maxId++;
    Work_on* work_on = (Work_on*)company;
    work_on->Id = _maxId;
    _data.push_back(*work_on);
    return true;
}

bool Work_onData::DeleteMember(int i){
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

// void Work_onData ::Edit_Table()
// {
//     Ui ui;
//     int i;
//     Work_on work_on;
//     Work_onData work_onData("Work_on.data");
//     i = ui.ChooseToEdit();
//     work_on = work_onData._data[i];
//     work_onData._data[i] = EnterWork_onInfor(work_on);
//     work_onData.ExportToFile("Work_on.data");
// }

float Work_onData::GetHoursProject(int projectNumber){
    float hoursProject = 0.0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNO == projectNumber){
            hoursProject += _data[i].Hours; 
        }
    }
    return hoursProject;
}



