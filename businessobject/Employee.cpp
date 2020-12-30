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

// ostream& operator<<(ostream& out, Employee employee){
//     return out;
// }

    // friend void ChangeValues(int id, string fName = " ", string mInit = " ", string lName = " ", long ssn = 0, string bDate = " ", string address = " ", char sex = '', int salary = 0, long superSSN = 0, int dno = 0){
    //     Id = id;
    //     FName = fName;
    //     MInit = mInit;
    //     LName = lName;
    //     SSN = ssn;
    //     BDate = bDate;
    //     Address = address;
    //     Sex = sex;
    //     Salary = salary;
    //     SuperSSN = superSSN;
    //     DNO = dno;
        
    // }


// void Employee::CreateNewMember(Company* company){

    // EmployeeData employeeArray;

    // employeeArray.PushBack(*company);
    // employeeData.ExportToFile("Employee.data");

// }
