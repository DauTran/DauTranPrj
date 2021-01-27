#ifndef _dataaccess_Workon_Data_H_
#define _dataaccess_Workon_Data_H_
#include <vector>
#include <string>

#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Work_on.h"
#include "../ui/Work_onUI.h"

using namespace std;

class Work_onData : public CompanyData{
private:
    vector <Work_on> _data;
    int _maxId;
public:
    Work_onData();

    /** @brief The function read file from Database folder  and assign to the each element of the vector in Department table
     */
    Work_onData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Work_on Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Work_on object to list of Work_ons
     *  
     *  Function add an Work_on object to list of Work_ons
     *  @return return Work_on id
     *  if fail, return -1;
     */
    int PushBack(Work_on);

    /** @brief function takes an address of object in Work_on vector 
     *  
     *  function takes object in Work_on vector 
     *  @return return an address of Work_on Object
     */
    Work_on* GetPointer(int i);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Work_on vector 
     *  
     *  function takes object in Work_on vector 
     *  @return return Work_on Object
     */
    Work_on Get(int);

    /** @brief Function to export file data of Work_on table
     *  
     *  @return return 1 if true 
     */
    int ExportToFile(string fileName);

    string ShowOnFile();

    /** @brief Function add an Work_on object to list of Work_on
     *  
     *  Function add an Work_on object to list of Work_on
     *  @return return true 
     *  
     */
    bool AddMember() override;

    /** @brief Function update an Work_on object to list of Work_on
     *  
     *  Function update an Work_on object to list of Work_on
     *  @return return true 
     *  
     */
    bool UpdateMember() override;

    /** @brief Function delete an Work_on object to list of Work_on
     *  
     *  Function delete an Work_on object to list of Work_on
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember() override;

    /** @brief Function to do the function 7, to get total time to complete project with pno insert
     *  @return return total hours 
     *  if not, return 0
     */
    float GetHoursProject(int );

    /** @brief Function to do the function 9, to get employee in a project follow by pno
     *  @return return a vector employee 
     */
    vector<Work_on> GetHoursProjectMin(int );
    
};
#endif