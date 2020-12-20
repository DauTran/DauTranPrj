#ifndef _figure_h_
#define _figure_h_
#include<string>
using namespace std;

class Company{
public:
	virtual Company* createTable() = 0;
	virtual Company* updateTable() = 0;
	virtual Company* readTable() = 0;
	virtual Company* deleteTable() = 0;
};

class Employee{
	unsigned int Id;
	string fName;
	char mInit;
	string lName;
	unsigned float ssn;
	string bDate;
	string address;
	char sex;
	unsigned int salary;
	int superSSN;
	unsigned DNO; 
	
	
	
};	

class DEPTLocations{
	unsigned int dNumber;
	string dLocation;
	
};

class Department{
	string dName;
	unsigned int dNumber;
	unsigned float mgrSSN;
	string mgrStartDate;
	
};

class WorkOn{
	unsigned float ESSN;
	unsigned int PNO;
	float hours;
};

class Project{
	string PName;
	unsigned int PNumber;
	string Plocation;
	unsigned int DNum;
};

class Dependent{
	unsigned float ESSN;
	string dependentName;
	char sex;
	string Bdate;
	string relationship
};
#endif
