#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>
using namespace std;



void clear_stdin(void);

//提示信息 带休眠的
void info(const char* str,float sec =0);

void clear_screen(void);

char get_cmd(char start,char end);

char* get_str(char* str,size_t len);

char* get_pwd(char* pass,size_t len,bool flag);

char get_sex(void);

void init_id(void);

int get_id(const type_info& type);

void anykey_continue(void);

#endif //TOOLS_H
