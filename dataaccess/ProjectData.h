#ifndef Project_dataaccess_Project_Data_H_
#define Project_dataaccess_Project_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Project.h" 
#include "../ui/ProjectUI.h"

using namespace std;

class ProjectData : public CompanyData{
private:
    vector<Project> _data;
    int _maxId;
public:
    ProjectData();
    /** @brief The function read file from Database folder  and assign to the each element of the vector in ProjectData table
     */
    ProjectData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Project Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Project object to list of Projects
     *  
     *  Function add an Project object to list of Projects
     *  @return return Project id
     *  if fail, return -1;
     */
    int PushBack(Project);

    Project* GetPointer(int i);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Project vector 
     *  
     *  function takes object in Project vector 
     *  @return return Project Object
     */
    Project Get(int i);

    /** @brief Function to export file data of Project table
     *  
     *  @return return 1 if true 
     */
    int ExportToFile(string );
    string ShowOnFile();

    /** @brief Function add an Project object to list of Projects
     *  
     *  Function add an Project object to list of Projects
     *  @return return true 
     *  
     */
    bool AddMember() override;

    /** @brief Function update an Project object to list of Projects
     *  
     *  Function update an Project object to list of Projects
     *  @return return true 
     *  
     */
    bool UpdateMember() override;

    /** @brief Function delete an Project object to list of Projects
     *  
     *  Function delete an Project object to list of Projects
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember() override;

    /** @brief Function to do a function 7, to get Projects name with project number insert
     *  @return return the project name if throw project number  
     *  if fail, return blank string
     */
    string GetProjectName(int );

    /** @brief Function to do a function 9 overloading with to get Projects name with project number  and department number insert
     *  @return return the project name if throw project number  
     *  if fail, return blank string
     */
    string GetProjectName(int , int );
    
};
#endif