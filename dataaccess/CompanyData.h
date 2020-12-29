#ifndef CompanyData_h_
#define CompanyData_h_
#include <vector>
#include "../businessobject/Employee.h"
#include "../businessobject/Company.h"

using namespace std;

class CompanyData
{
public:
	friend class EmployeeData;

	//Create a member of the table
	virtual bool CreateNewMember(string ) = 0;
	//Create a member of the table by Id 
	virtual bool DeleteMember(int ) = 0;
	
	// virtual Company UpdateRowTable(Company* ) = 0;
	// virtual vector<Company*> ReadRowTable(vector<Company*> table) = 0;
	// virtual vector<Company*> DeleteRowTable(vector<Company*> table) = 0;
	
};

#endif