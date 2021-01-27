#ifndef Project_dataaccess_Department_Data_H_
#define Project_dataaccess_Department_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Department.h"
#include "../ui/DepartmentUI.h"

using namespace std;

class DepartmentData : public CompanyData{
private:
    vector<Department> _data;
    int _maxId;
public:
    DepartmentData();

    /** @brief The function read file from Database folder  and assign to the each element of the vector in Department table
     */
    DepartmentData(string fileName);
    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Department Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Department object to list of Department
     *  
     *  Function add an Department object to list of Department
     *  @return return Department id
     *  if fail, return -1;
     */
    int PushBack(Department);

    Department* GetPointer(int i);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Department vector 
     *  
     *  function takes object in Department vector 
     *  @return return Department Object
     */
    Department Get(int i);

    /** @brief Function to export file data of Department table
     *  
     *  @return return 1 if true 
     */
    int ExportToFile(string );

    /** @brief Function view all Department object to list of Departments
     *  
     *  Function add an Department object to list of Departments
     *  @return return string of all elements in Departments data 
     */
    string ShowOnFile();

    /** @brief Function add an Department object to list of Departments
     *  
     *  Function add an Department object to list of Departments
     *  @return return true 
     */
    bool AddMember() override;

    /** @brief Function update an Department object to list of Departments
     *  
     *  Function add an Department object to list of Departments
     *  @return return true 
     */
    bool UpdateMember() override;

    /** @brief Function delete an Department object to list of Departments
     *  
     *  Function delete an Department object to list of Departments
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember() override;
    
};
#endif