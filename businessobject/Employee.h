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
    friend Employee ChangeValues(Employee& employee);



    //// Insert value to class employee
    //// friend ostream& operator<<(ostream& out, Employee employee);

    // ver1//friend void ChangeValues(int id, string fName = " ", string mInit = " ", string lName = " ", long ssn = 0, string bDate = " ", string address = " ", char sex = '', int salary = 0, long superSSN = 0, int dno = 0);
};

#endif  