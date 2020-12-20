#ifndef _figure_h_
#define _figure_h_
#include<string>
using namespace std;

class Company{
public:
	Company();
	~Company();
	virtual Company* createTable() = 0;
	virtual Company* updateTable() = 0;
	virtual Company* readTable() = 0;
	virtual Company* deleteTable() = 0;
};











class Dependent{
	unsigned float ESSN;
	string dependentName;
	char sex;
	string Bdate;
	string relationship
};
#endif
