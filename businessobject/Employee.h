#ifndef Project_businessobject_Employee_h_
#define Project_businessobject_Employee_h_
#include <string>
#include "../libs/json.hpp"
#include "Company.h"


using json = nlohmann::json;
using namespace std;

class Employee : public Company{
    int Id; //id is increasing number
    string FName, MInit, LName;
    long SSN;
    string BDate, Address;
    char Sex;
    int Salary;
    long SuperSSN;
    int DNO;

public:
    friend class EmployeeData;
    
    Employee();
    Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno);
    int GetId();
    int SetId(int);
    string ToString();
    json ToJson(); 
    
    // Using to change Id of a employee
    // friend Employee ChangeValues(Employee& employee);

};

#endif  