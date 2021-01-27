#ifndef Project_dataaccess_Employee_Data_H_
#define Project_dataaccess_Employee_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Employee.h"
#include "../ui/EmployeeUI.h"

using namespace std;

class EmployeeData : public CompanyData{
private:
    vector<Employee> _data;
    
    int _maxId;
public:
    EmployeeData();
    
    /** @brief The function read file from Database folder  and assign to the each element of the vector in Employee table
     */
    EmployeeData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return employee Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an employee object to list of employees
     *  
     *  Function add an employee object to list of employees
     *  @return return employee id
     *  if fail, return -1;
     */
    int PushBack(Employee);

    //Return a referrent object
    Employee* GetPointer(int i);   //Khai bao con tro kieu Employee

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();
    
    /** @brief function takes object in Employee vector 
     *  
     *  function takes object in Employee vector 
     *  @return return Employee Object
     */
    Employee Get(int i);

    int ExportToFile(string fileName);
    string ShowOnFile();

    /** @brief Function add an Employee object to list of Employees
     *  
     *  Function add an Employee object to list of Employees
     *  @return true 
     *  
    */
 	bool AddMember() override; 

    /** @brief Function update an Employee object to list of Employees
     *  
     *  Function add an Employee object to list of Employees
     *  @return true 
     *  
    */
    bool UpdateMember() override;

    /** @brief Function delete an Employee object to list of Employees
     *  
     *  Function delete an Employee object to list of Employees
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember() override;  

    /** @brief Function to do a function number 6, insert the name of supervisor and you have the list of employees
     *   
     *  if not find supervisor name, return empty string
     *  @return return a string name of employees 
     */
    string Restructure(string supervisorName);

    /** @brief Function to do the function 8, insert the mgrSSN than you have the list of employees
     *   
     *  if not find supervisor name, return empty string
     *  @return return a string name of employees 
     */
    float CalculateSalary(long );

    /** @brief Function to do the function 9, insert the department number than you have the list of employees
     *  in department 
     *  if not find supervisor name, return empty string
     *  @return return a vector employee type of employees 
     */
    vector<Employee> FindEmployeeDepartment(int );

    // bool UpdateMember();

};

#endif