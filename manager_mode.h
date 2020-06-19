#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H
#include<vector>
#include"manager.h"

using namespace std;

class ManagerMode
{
public:
	virtual void load(vector<Manager>&) = 0;

	virtual void save(vector<Manager>&) = 0;
};
#endif// MANAGER_MODE_H
