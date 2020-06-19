#include "manager_view_impl.h"
#include "emis.h"
#include "tools.h"

EMIS* EMIS::emis;

EMIS::EMIS(void)
{
	init_id();
	mgrView = new ManagerViewImpl;
}

EMIS::~EMIS(void)
{
	delete mgrView;
}

EMIS* EMIS::create(void)
{
	if(NULL == emis)
	{
		emis = new EMIS;
	}
	return emis;
}

void EMIS::start(void)
{
	while(true)
	{
		clear_screen();
		
		info("****欢迎使用指针企业信息管理系统****\n");
		info("        1、登录管理子系统\n");
		info("        2、登录运营子系统\n");
		info("        3、退出\n");
		
		switch(get_cmd('1','3'))
		{
			case '1' :mgrView->loginManager();break;
			case '2' :mgrView->loginService();break;
			case '3' :delete emis; return;
		}
	}
}



