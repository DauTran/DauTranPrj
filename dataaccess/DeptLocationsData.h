#ifndef Project_dataaccess_DeptLocations_Data_H_
#define Project_dataaccess_DeptLocations_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/DeptLocations.h"
#include "../ui/DeptLocationsUI.h"
using namespace std;

class DeptLocationsData : public CompanyData{
private:
    vector<DeptLocations> _data;
    int _maxId;
public:
    DeptLocationsData();

    /** @brief The function read file from Database folder  and assign to the each element of the vector in DeptLocations table
     */

    DeptLocationsData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
        *  
        *  The function returns the MaxID of the last element of the vector
        *  @return return DeptLocations Max Id
        *  if fail, return -1;
        */
    int GetMaxId();

    /** @brief Function add an DeptLocations object to list of DeptLocations
        *  
        *  Function add an DeptLocations object to list of DeptLocations
        *  @return return DeptLocations id
        *  if fail, return -1;
        */
    int PushBack(DeptLocations);

        /** @brief function takes a address of object in DeptLocations vector 
         *  
         *  function takes object in DeptLocations vector 
         *  @return return a address of DeptLocations Object
         */
    DeptLocations* GetPointer(int i);

    /** @brief The function returns the size of the vector
        *  
        *  The function returns the size of the vector
        *  @return return Size of vector.
        *  if fail, return -1;
        */
    int GetSize();

    /** @brief function takes object in DeptLocations vector 
        *  
        *  function takes object in DeptLocations vector 
        *  @return return DeptLocations Object
        */
    DeptLocations Get(int i);

    int ExportToFile(string filename);
    string ShowOnFile();

    /** @brief Function add an DeptLocation object to list of DeptLocations
        *  
        *  Function add an DeptLocation object to list of DeptLocations
        *  @return return true 
        */
    bool AddMember() override;

    /** @brief Function update an DeptLocation object to list of DeptLocations
        *  
        *  Function update an DeptLocation object to list of DeptLocations
        *  @return return true 
        */  
    bool UpdateMember() override;

        /** @brief Function delete an DeptLocation object to list of DeptLocations
         *  
         *  Function delete an DeptLocation object to list of DeptLocations
         *  @return return true 
         *  if fail, return false
         */
    bool DeleteMember() override;
    
};
#endif