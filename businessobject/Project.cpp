#include "Project.h"

using namespace std;

// Default Contructor
Project::Project(){};
// Contructor with paramaters
Project::Project(int id, string pName,string pLocation,int pNumber,int dNum){
    Id = id;
    PName = pName;
    PLocation = pLocation;
    PNumber = pNumber;
    DNum = dNum;
}
string Project::ToString(){
    string s;
    s += "{";
    s += to_string(Id) + " ";
    s += PName + " ";
    s += PLocation + " ";
    s += to_string(PNumber) + " ";
    s += to_string(DNum) + " ";
    s += "}";
    return s;
}

json Project::ToJson(){
    json j;
    j["Id"] = Id;
    j["PName"] = PName;
    j["PLocation"] = PLocation;
    j["PNumber"] = PNumber;
    j["DNum"] = DNum;
    return j;
}

int Project::GetId()
{
    return Id;
}

string Project::GetPName()
{
    return PName;
}

int Project::GetPNumber()
{
    return PNumber;
}

string Project::GetPLocation()
{
    return PLocation;
}

int Project::GetDNum()
{
    return DNum;
}
