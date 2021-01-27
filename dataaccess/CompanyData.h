#ifndef CompanyData_h_
#define CompanyData_h_
#include <vector>
#include <direct.h>
#include <string>
#include <ctime>
#include "../businessobject/Company.h"
#include "../businessobject/Employee.h"

using namespace std;

class CompanyData{
	string mBackupLink;
public:
    /** @brief The function create folder named "Backup data" and subfolder day and time  
	*/
	CompanyData();
	/** @brief The function to get the link from Backup data folder to time folder
     *  
     *  @return return string of the link
     */
	string GetLink();
	//To export data
	virtual int ExportToFile(string filename) = 0;
	//Return a string of each member of vector
	virtual string ShowOnFile() = 0;

	//Create a member of the table
	virtual bool AddMember() = 0;

	virtual bool UpdateMember() = 0;
	//D a member of the table by Id 
	virtual bool DeleteMember() = 0;

};

#endif