#include "service_view_impl.h"
#include "service_ctrl_impl.h"

ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl = new  ServiceCtrlImpl;
}
	
ServiceViewImpl::~ServiceViewImpl(void)
{
	delete srcCtrl;
}

void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		clear_screen();
		info("****欢迎进入运营子系统****\n");
		info("     1、添加部门\n");
		info("     2、删除部门\n");
		info("     3、列出所有部门\n");
		info("     4、添加员工\n");
		info("     5、删除部门\n");
		info("     6、修改员工\n");
		info("     7、列出部门所有员工\n");
		info("     8、列出系统所有员工\n");
		info("     9、退出运营子系\n");
		
		switch(get_cmd('1','9'))
		{
			case '1':addDept();break;
			case '2':delDept();break;
			case '3':listDept();break;
			case '4':addEmp();break;
			case '5':delEmp();break;
			case '6':modEmp();break;
			case '7':listEmp();break;
			case '8':listAllEmp();break;
			case '9':return;
		}
	}
}

void ServiceViewImpl::addDept(void)
{
	char name[20] ={};
	info("请输入部门名:");
	get_str(name,sizeof(name));
	
	Department dept(name);
	if(srcCtrl->addDept(dept))
	{
		info("添加部门成功！",1.5);
	}
	else
	{
		info("添加部门失败！",1.5);
	}
}

void ServiceViewImpl::delDept(void)
{
	int id;
	info("请输入要删除的部门的ID:");
	cin >> id;
	
	if(srcCtrl->delDept(id))
	{
		info("删除部门成功！",1.5);
	}
	else
	{
		info("删除部门失败！",1.5);
	}
}

void ServiceViewImpl::listDept(void)
{
	vector<Department> deptArr = srcCtrl->listDept();
	
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		cout << deptArr[i].getId() << " " << deptArr[i].getName() << " " << deptArr[i].empArr.size() << endl;
	}
	
	anykey_continue();
}

void ServiceViewImpl::addEmp(void)
{
	int id;
	char name[20]={};
	char sex =0 ;
	int age =1 ;
	
	info("请输入要加入的部门ID:");
	cin >> id;
	
	info("请输入员工姓名:");
	get_str(name,sizeof(name));
	
	info("请输入员工性别:");
	sex = get_sex();
	
	info("请输入员工年龄:");
	cin >> age;
	
	Employee emp(name,sex,age);
	if(srcCtrl->addEmp(id,emp))
	{
		info("添加员工成功！",1.5);
	}
	else
	{
		info("添加员工失败！",1.5);
	}
}

void ServiceViewImpl::delEmp(void)
{
	int id;
	info("请输入要删除的员工ID:");
	cin >> id;
	
	if(srcCtrl->delEmp(id))
	{
		info("删除员工成功！",1.5);
	}
	else
	{
		info("删除员工失败！",1.5);
	}
}

void ServiceViewImpl::modEmp(void)
{
	int id;
	char name[20]={};
	char sex =0 ;
	int age =1 ;
	
	info("请输入要修改的员工ID:");
	cin >> id;
	
	info("请输入员工姓名:");
	get_str(name,sizeof(name));
	
	info("请输入员工性别:");
	sex = get_sex();
	
	info("请输入员工年龄");
	cin >> age;
	
	Employee emp(name,sex,age,id);
	if(srcCtrl->modEmp(id,emp))
	{
		info("修改员工成功！",1.5);
	}
	else
	{
		info("修改员工失败！",1.5);
	}
}

void ServiceViewImpl::listEmp(void)
{
	int id;
	info("请输入要列出的部门ID:");
	cin >> id;
	
	Department* dept = srcCtrl->listEmp(id);
	if(NULL == dept)
	{
		info("该部门不存在！",1.5);
		return;
	}
	
	cout<< dept->getId() << " " << dept->getName() << " " << dept->empArr.size() << endl;
	
	for(uint32_t i=0; i<dept->empArr.size(); i++)
	{
		cout << dept-> empArr[i] << endl;
	}
	
	anykey_continue();

}

void ServiceViewImpl::listAllEmp(void)
{
	vector<Department> & deptArr = srcCtrl->listDept();
	
	for(uint32_t i=0; i<deptArr.size(); i++)
	{
		cout << deptArr[i] << endl;
	}
	
	anykey_continue();
}

