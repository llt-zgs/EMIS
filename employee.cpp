#include"employee.h"

Employee::Employee(const char* name,char sex,char age,int id)
{
	m_iId = id;
	m_iAge = age;
	strcpy(m_strName,name);
	m_cSex = sex;
	
}
void Employee::setId(int id)
{
	m_iId = id;
}

void Employee::setAge(int age)
{
	m_iAge = age;
}

void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}

void Employee::setSex(char sex)
{
	m_cSex = sex;
}

int Employee::getId(void)
{
	return m_iId;
}

int Employee::getAge(void)
{
	return m_iAge;
}

char* Employee::getName(void)
{
	return m_strName;
}

char Employee::getSex(void)
{
	return m_cSex;
}

ostream& operator <<(ostream& os,const Employee& emp)
{
	return os << emp.m_iId <<" " << emp.m_iAge << " " << emp.m_strName << " " << emp.m_cSex;
}
 	
istream& operator >>(istream& is,Employee& emp)
{
	return is >> emp.m_iId >> emp.m_iAge >> emp.m_strName >> emp.m_cSex;
}
