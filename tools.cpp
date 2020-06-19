#include <stdlib.h>
#include <unistd.h>
#include <getch.h>
#include "manager.h"
#include "department.h"
#include "employee.h"
#include "tools.h"
#include "emis.h"

// 清理输入缓冲区
void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}


void info(const char* str,float sec)
{
	cout << str;
	cout.flush();
	int usec = sec*1000000;
	usleep(usec);
}

void clear_screen(void)
{
	system("clear");
}
char get_cmd(char start,char end)
{	
	cout << "-----------------------" << endl;
	cout << "请输入指令:";
	while(true)
	{
		char cmd = getch();
		if(cmd >=start && cmd <= end)
		{
			cout << cmd << endl;
			return cmd;
		}
	}
}

// 获取字符串
char* get_str(char* str,size_t len)
{
	clear_stdin();
	fgets(str,len,stdin);
	size_t size = strlen(str);

	if('\n' == str[size-1])
	{
		str[size-1] = '\0';
	}
	else
	{
		clear_stdin();
	}

	return str;
}

// 获取密码
char* get_pwd(char* pass,size_t len,bool flag)
{
	clear_stdin();
	size_t index = 0;

	while(index < len)
	{
		char key = getch();
		if(127 == key)
		{
			if(index > 0)
			{
				index--;
				if(flag) printf("\b \b");
			}
			continue;
		}

		if('\n' == key) break;

		pass[index++] = key;
		if(flag) printf("*");
	}

	pass[index] = '\0';
	printf("\n");
	return pass;
}

char get_sex(void)
{
	char sex = 0;
	for(;;)
	{
		sex = getch();
		if('w'==sex || 'W'==sex || 'm'==sex || 'M'==sex)
		{
			printf("%c\n",sex);
			break;
		}
	}
	return sex;
}



void init_id(void)
{
	ifstream ifs(ID_PATH,ios::in);
	if(ifs.good())
	{
		ifs.close();
		return ;
	}
	
	int ids[3] = {10,100,1000};
	ofstream ofs(ID_PATH,ios::out);
	if(!ofs.good())
	{
		info("ID文件初始化失败\n");
		return;
	}
	
	ofs.write((char*)ids,sizeof(ids));
	ofs.close();
}

int get_id(const type_info& type)
{
	fstream fs(ID_PATH,ios::in|ios::out);
	if(!fs.good())
	{
		info("ID文件打开失败，");
		return -1;
	}
	
	int ids[3] = {} , id = 0;
	fs.read((char*)ids,sizeof(ids));
	cout << ids[0] << " " << ids[1] << " " << ids[2] << endl;
	
	if(type == typeid(Manager))
	{
		id = ++ids[0];
	}
	else if(type == typeid(Department))
	{
		id = ++ids[1];
	}
	else if(type == typeid(Employee))
	{
		id = ++ids[2];
	}
	else
	{
		return -1;
	}
	
	fs.seekp(0,ios::beg);
	fs.write((char*)ids,sizeof(ids));
	fs.close();
	
	return id;
}

// 按任意键继续
void anykey_continue(void)
{
	clear_stdin();
	puts("按任意键继续......");
	getch();
}
