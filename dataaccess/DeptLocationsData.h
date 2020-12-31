#ifndef Project_dataaccess_DeptLocations_Data_H_
#define Project_dataaccess_DeptLocations_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/DeptLocations.h"

using namespace std;

class DeptLocationsData : public CompanyData{
private:
    vector<DeptLocations> _data;
    int _maxId;
public:
    DeptLocationsData();

    DeptLocationsData(string fileName);

    int GetMaxId();

    int PushBack(DeptLocations);

    DeptLocations* GetPointer(int i);

    int GetSize();

    DeptLocations Get(int i);

    int ExportToFile(string );

    bool AddMember(Company* ) override;
    bool DeleteMember(int ) override;
    
};
#endif