#ifndef Project_dataaccess_Project_Data_H_
#define Project_dataaccess_Project_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Project.h" 

using namespace std;

class ProjectData : public CompanyData{
private:
    vector<Project> _data;
    int _maxId;
public:
    ProjectData();

    ProjectData(string fileName);

    int GetMaxId();

    int PushBack(Project);

    Project* GetPointer(int i);

    int GetSize();

    Project Get(int i);

    int ExportToFile(string );

    bool AddMember(Company* ) override;
    bool DeleteMember(int ) override;
    
};
#endif