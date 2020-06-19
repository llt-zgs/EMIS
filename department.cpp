#include"department.h"

Department::Department(const char* name)
{
	strcpy(m_strName,name);
}
	 
void Department::setId(int id)
{
	m_iId=id;
}
 	
void Department::setName(const char* name)
{
	strcpy(m_strName,name);
}
 	
int Department::getId(void)
{
	return m_iId;
}
 	
char* Department::getName(void)
{
	return m_strName;
}
 	
ostream& operator <<(ostream& os,const Department& dept)
{
	os << dept.m_iId << " " << dept.m_strName << " " << dept.empArr.size() << endl;
	for(uint32_t i=0; i<dept.empArr.size(); i++)
	{
		os << dept.empArr[i] << endl;
	}
	return os;
} 	
istream& operator >>(istream& is,Department& dept)
{
	int count = 0;
	is >> dept.m_iId >> dept.m_strName >> count;
	
	Employee emp;
	for(int i=0; i<count; i++)
	{
		is >> emp;
		dept.empArr.push_back(emp);
	}
	return is;
}
