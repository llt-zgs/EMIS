#include"manager_ctrl_impl.h"
#include"manager_mode_impl.h"
#include"tools.h"

ManagerCtrlImpl::ManagerCtrlImpl(void)
{
	mgrMode = new ManagerModeImpl;
	mgrMode->load(mgrArr);
}
ManagerCtrlImpl::~ManagerCtrlImpl(void)
{
	mgrMode->save(mgrArr);
	delete mgrMode;
}
	
bool ManagerCtrlImpl::addMgr(Manager& mgr)
{
	for(uint32_t i=0; i<mgrArr.size(); i++)
	{
		if(mgr == mgrArr[i])
		{
			info("用户名已经存在,");
			return false;
		}
	}
	int id = get_id(typeid(Manager));
	if(id < 0)
	{
		return false;
	}
	
	mgr.setId(id);
	mgrArr.push_back(mgr);
	
	return true;
}

bool ManagerCtrlImpl::delMgr(int id)
{
	vector<Manager>::iterator it;
	for(it=mgrArr.begin(); it!=mgrArr.end(); it++)
	{
		if(id == it->getId())
		{
			mgrArr.erase(it);
			return true;
		}
	}
	
	return false;
}

vector<Manager>& ManagerCtrlImpl::listMgr(void)
{
	return mgrArr;
}

