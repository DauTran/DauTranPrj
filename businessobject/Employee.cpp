#include "Employee.h"
using namespace std;

Employee::Employee(){}
Employee::Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno){
    Id = id;
    FName = fName;
    MInit = mInit;
    LName = lName;
    SSN = ssn;
    BDate = bDate;
    Address = address;
    Sex = sex;
    Salary = salary;
    SuperSSN = superSSN;
    DNO = dno;
}
int Employee::GetId(){
    return Id;
}
//?
int Employee::SetId(int id){
    Id = id;
    return id;
}

string Employee::ToString(){
    string s;
    s += "{";
    // convert char to string
    string sex = string(1, Sex);
    s += to_string(Id) + " ";
    s += FName + " ";
    s += MInit + " ";
    s += LName + " ";
    s += to_string(SSN) + " ";
    s += BDate + " ";
    s += Address + " ";
    s += sex + " ";
    s += to_string(Salary) + " ";
    s += to_string(SuperSSN) + " ";
    s += to_string(DNO) + " ";
    s += "}";
    return s;
}

json Employee::ToJson(){
    json j;
    j["Id"] = Id;
    j["FName"] = FName;
    j["MInit"] = MInit;
    j["LName"] = LName;
    j["SSN"] = SSN;
    j["BDate"] = BDate;
    j["Address"] = Address;
    j["Sex"] = string(1, Sex);  //convert a char to a string
    j["Salary"] =  Salary;
    j["SuperSSN"] = SuperSSN;
    j["DNO"] = DNO;

    return j;
}

string Employee::GetName()
{
    return (FName + LName);
}

string Employee::GetFName()
{
    return FName;
}
string Employee::GetMInit()
{
    return MInit;
}
string Employee::GetLName()
{
    return LName;
}
long Employee::GetSSN()
{
    return SSN;
}
string Employee::GetBDate()
{
    return BDate;
}
string Employee::GetAddress()
{
    return Address;
}
char Employee::GetSex() 
{
    return Sex;
}
int Employee::GetDNO()
{
    return DNO;
}

int Employee::GetSalary(){
    return Salary;
}

long Employee::GetSuperSSN(){
    return SuperSSN;
}
