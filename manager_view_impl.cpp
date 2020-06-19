#include "manager_view_impl.h"
#include "service_view_impl.h"
#include "manager_ctrl_impl.h"
#include "tools.h"
#include "emis.h"

ManagerViewImpl::ManagerViewImpl(void)
{
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}
	
ManagerViewImpl::~ManagerViewImpl(void)
{
	delete mgrCtrl;
	delete srcView;
}

void ManagerViewImpl::loginManager(void)
{
	char user[20] ={};
	char pwd[20] = {};
	char pwd2[20] = "1234";
	
	ifstream ifs(ADMIN_PATH,ios::in);
	if(ifs.good())
	{
		ifs.read(pwd2,sizeof(pwd));
		pwd2[strlen(pwd2)-1] = '\0';
	}
	
	info("请输入用户名:");
	get_str(user,sizeof(user));
	
	info("请输入密码:");
	get_pwd(pwd,sizeof(pwd),true);
	
	
	if(!strcmp("admin",user) && !strcmp(pwd,pwd2))
	{
		menuMgr();
	} 
	else
	{
		info("用户名或密码错误！",1.5);
	}
}

void ManagerViewImpl::loginService(void)
{
	char user[20] ={};
	char pwd[20] = {};
	
	info("请输入用户名:");
	get_str(user,sizeof(user));
	
	info("请输入密码:");
	get_pwd(pwd,sizeof(pwd),true);
	
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(uint32_t i=0; i<mgrArr.size(); i++)
	{
		if(!strcmp(user,mgrArr[i].getName()) || atoi(user)==mgrArr[i].getId())
		{
			if(!strcmp(pwd,mgrArr[i].getPwd()))
			{
				srcView->menuSrc();
				return;
			}
		}
		
		else
		{
			info("密码错误！",1.5);
			return;
		}
	}
	
	info("该用户不存在！",1.5);
	
}

void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		clear_screen();
		info("***欢迎进入管理子系统***\n");
		info("1、添加管理员\n");
		info("2、删除管理员\n");
		info("3、显示所有管理员\n");
		info("4、退出管理子系统\n");
		
		switch(get_cmd('1','4'))
		{
			case '1': addMgr();break;
			case '2': delMgr();break;
			case '3': listMgr();break;
			case '4': return;
		}
	}
}

void ManagerViewImpl::addMgr(void)
{
	char name[20]={};
	info("请输入用户名:");
	get_str(name,sizeof(name));
	
	char pwd[20] = {};
	info("请输入密码");
	get_pwd(pwd,sizeof(pwd),true);
	
	char pwd2[20] = {};
	info("请再次输入密码");
	get_pwd(pwd2,sizeof(pwd2),true);
	
	if(strcmp(pwd,pwd2))
	{
		info("两次输入的密码不同，添加失败\n",1.5);
		return;
	}
	
	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
	{
		info("添加管理员成功!\n",1.5);
	}
	else
	{
		info("添加管理失败!\n",1.5);
	}

}

void ManagerViewImpl::delMgr(void)
{
	int id =0;
	info("请输入要删除的管理员ID:\n");
	cin >> id;
	
	if(mgrCtrl->delMgr(id))
	{
		info("删除管理员成功！\n",1.5);
	}

	else
	{
		info("删除管理员失败！\n",1.5);
	}
}

void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(uint32_t i=0; i<mgrArr.size(); i++)
	{
		cout << mgrArr[i].getId() <<" " << mgrArr[i].getName()<< " " << mgrArr[i].getPwd() <<endl;
	}
	anykey_continue();
}
