#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <vector>
#include "employee.h"
#include "tools.h"

class Department
{
	int m_iId;
	char m_strName[20];
	
public:
	vector<Employee> empArr;
	
	Department(const char* name="");
 	
 	void setId(int id);
 	
 	void setName(const char* name);
 	
 	int getId(void);
 	
 	char* getName(void);
 	
 	friend ostream& operator <<(ostream& os,const Department& dept);
 	
 	friend istream& operator >>(istream& is,Department& dept);
};
#endif //DEPARTMENT_H
