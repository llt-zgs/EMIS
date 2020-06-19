#include"service_ctrl_impl.h"
#include"service_mode_impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(deptArr);
}
	
ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}
	
bool ServiceCtrlImpl::addDept(Department& dept)
{
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		if(!strcmp(dept.getName(),deptArr[i].getName()))
		{
			info("该部门已经存在!");
			return false;
		}	
	}
	
	dept.setId(get_id(typeid(Department)));
	deptArr.push_back(dept);
	return true;
}

bool ServiceCtrlImpl::delDept(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(id == it->getId())
		{
			if(it->empArr.size())
			{
				info("该部门中还有员工未处理！");
				return false;
			}
			
			deptArr.erase(it);
			return true;
		}
	}
	info("该部门不存在！");
	return false;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
	emp.setId(get_id(typeid(Employee)));
	
	for(uint32_t i =0; i<deptArr.size(); i++)
	{
		if(id == deptArr[i].getId())
		{
			deptArr[i].empArr.push_back(emp);
			return true;
		}
	}
	
	return false;
}

bool ServiceCtrlImpl::delEmp(int id) 
{
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		vector<Employee>::iterator it;
		for(it=deptArr[i].empArr.begin(); it!=deptArr[i].empArr.end(); it++)
		{
			if(id == it->getId())
			{
				deptArr[i].empArr.erase(it);
				return true;
			}
		}
	}
	
	return false;
}

bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		for(uint32_t j=0; j<deptArr[i].empArr.size(); j++)
		{
			if(id == deptArr[i].empArr[j].getId())
			{
				deptArr[i].empArr[j] = emp;
				return true;
			}
		}
	}
	
	return false;
}

Department* ServiceCtrlImpl::listEmp(int id)
{
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		if(id == deptArr[i].getId())
		{
			return &deptArr[i];
		}
	}
	
	return NULL;
}

vector<Department>& ServiceCtrlImpl::listAllEmp()
{
	return deptArr;
}
