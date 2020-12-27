#ifndef CompanyData_h_
#define CompanyData_h_
#include <vector>
#include "../businessobject/Employee.h"
using namespace std;

class CompanyData
{
public:
	//Create a member of the table
	virtual bool CreateNewMember() = 0;
	
	// virtual bool DeleteMember() = 0;
	// virtual vector<Company*> UpdateRowTable(vector<Company*> table) = 0;
	// virtual vector<Company*> ReadRowTable(vector<Company*> table) = 0;
	// virtual vector<Company*> DeleteRowTable(vector<Company*> table) = 0;
	
};

#endif