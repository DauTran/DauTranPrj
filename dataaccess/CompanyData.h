#ifndef CompanyData_h_
#define CompanyData_h_
#include <vector>
#include "../businessobject/Employee.h"
#include "../businessobject/Company.h"

using namespace std;

class CompanyData{
public:

	virtual int ExportToFile(string filename) = 0;

	//Create a member of the table
	virtual bool AddMember(Company* ) = 0;
	//D a member of the table by Id 
	virtual bool DeleteMember(int ) = 0;
	//Update a member of the table
	// virtual bool UpdateMember() = 0;	
};

#endif