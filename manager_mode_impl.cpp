#include"manager_mode_impl.h"
#include "emis.h"
void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	cout<< "-----load-----" << endl;
	ifstream ifs(MANAGER_PATH,ios::in);
	
	Manager mgr;
	while(ifs.good())
	{
		ifs >> mgr;
		if(ifs.good())
		{
			mgrArr.push_back(mgr);
		}
	}
	
	ifs.close();
	
}

void ManagerModeImpl::save(vector<Manager>& mgrArr)
{
	cout << "-----save-----" << endl;
	ofstream ofs(MANAGER_PATH,ios::out);
	
	for(uint32_t i=0; i<mgrArr.size(); i++)
	{
		ofs << mgrArr[i];
	}
	
	ofs.close();	
}
